#include <iostream>
#include <fstream>
#include "cstdlib"
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <Windows.h>

using namespace std;


class User
{
private:
    string id;
    string pin;
    bool blocking_status;
    double balance;
public:
    void setData(string id_temp, string pin_temp, string blocking_status_temp, double balance_temp)
    {
        id = id_temp;
        pin = pin_temp;
        if(blocking_status_temp == "1") blocking_status = true;
        if(blocking_status_temp == "0") blocking_status = false;
        balance=balance_temp;
    }
    bool checkBlock()
    {
        return blocking_status;
    }
    bool checkPin(string pin_inp)
    {
        if(pin == pin_inp) return true;
        if(pin != pin_inp) return false;
    }
    double getBalance(string id_temp, string pin_temp)
    {
        if(id_temp == id && pin_temp == pin) return balance;
        else return -1;
    }

    void setBalance(string id_temp, string pin_temp, double balance_tmp)
    {
        if(id_temp == id && pin_temp == pin)balance = balance_tmp;
    }

    void blockCard()
    {
        blocking_status=true;
        ofstream data("dataBase.txt",ios_base::app);
        data<<id;
        data<<endl;
        data<<pin;
        data<<endl;
        data<<blocking_status;
        data<<endl;
        data<<balance;
        data<<endl;
        data.close();
    }
};


class Server
{
private:
    User *user = new User();
    string pin;
    string user_id;
    bool end_of_session=false;
    bool remove_line(const char *filename, size_t index)
    {
        vector<string> vec;
        ifstream file(filename);
        if (file.is_open())
        {
            string str;
            while (getline(file, str))
                vec.push_back(str);
            file.close();
            if (vec.size() < index)
                return false;
            vec.erase(vec.begin() + index);
            ofstream outfile(filename);
            if (outfile.is_open())
            {
                copy(vec.begin(), vec.end(),
                     ostream_iterator<string>(outfile, "\n"));
                outfile.close();
                return true;
            }
            return false;
        }
        return false;
    }
public:
    void getUserData(string card)
    {

        string buff;
        int line=0;
        ifstream data("dataBase.txt");
        while(true)
        {
            buff="";
            data >> buff;
            line++;
            if(buff == card)
            {
                user_id=card;
                string pin;
                data >> pin;
                string blocking;
                data >> blocking;
                string btemp;
                stringstream balance;
                data >> btemp;
                balance << btemp;
                double balance_tmp;
                balance >> balance_tmp;
                data.close();
                user->setData(card,pin,blocking,balance_tmp);
                if(user->checkBlock())
                {
                    delete user;
                    end_of_session=true;
                    cout<<"карта заблокирована"<<endl;
                    remove("card.txt");
                }
                else
                {
                    remove_line("dataBase.txt", line-1);
                    remove_line("dataBase.txt", line-1);
                    remove_line("dataBase.txt", line-1);
                    remove_line("dataBase.txt", line-1);
                }

                break;
            }
        }
        data.close();
    }

    bool checkAccess(string pin_tmp)
    {
        pin = pin_tmp;
        return user->checkPin(pin_tmp);
    }

    void blockUser(string card)
    {
        user->blockCard();
        delete user;
    }

    bool checkEnd()
    {
        return end_of_session;
    }

    void balance()
    {
        while(true)
        {
            system("cls");
            double j = user->getBalance(user_id,pin);
            cout<<"баланс равен: "<<j<<endl;
            cout<<"0 назад"<<endl;
            int i=-1;
            cin>>i;
            if(i==0) break;
        }
    }
    void money()
    {
        int sum = 0;
        while(true)
        {
            int i=-1;
            bool success=false;
            system("cls");
            cout<<"выберите сумму: "<<endl;
            cout<<"1 25"<<endl;
            cout<<"2 50"<<endl;
            cout<<"3 75"<<endl;
            cout<<"4 100"<<endl;
            cout<<"5 друга€ сумма"<<endl;
            cout<<"0 назад"<<endl;
            cin>>i;
            switch(i)
            {
            case 1:
            {
                sum=25;
                success=true;
                break;
            }
            case 2:
            {
                sum=50;
                success=true;
                break;
            }
            case 3:
            {
                sum=75;
                success=true;
                break;
            }
            case 4:
            {
                sum=100;
                success=true;
                break;
            }
            case 5:
            {
                system("cls");
                cout<<"введите сумму: ";
                cin>>sum;
                cout<<endl;
                if(sum>0) success=true;
                break;
            }
            case 0:
            {
                success=true;
                break;
            }
            default:
                break;
            }
            if(success) break;
        }

        if(sum>0)
        {
            if(sum <= user->getBalance(user_id,pin))
            {
                system("cls");
                ofstream money("money.txt",ios_base::app);
                user->setBalance(user_id,pin,user->getBalance(user_id,pin) - sum);
                cout<<"выдача наличных"<<endl;
                Sleep(500);
                money<<sum;
                money<<endl;
            }
            else
            {
                while(true)
                {
                    system("cls");
                    cout<<"недостаточно денег"<<endl;
                    cout<<"0 назад"<<endl;
                    int i=-1;
                    cin>>i;
                    if(i==0) break;
                }
            }
        }
    }
    void updateDataBase()
    {
        ofstream data("dataBase.txt",ios_base::app);
        data<<user_id;
        data<<endl;
        data<<pin;
        data<<endl;
        data<<user->checkBlock();
        data<<endl;
        data<<user->getBalance(user_id,pin);
        data<<endl;
        data.close();
    }

};




class ATM
{
public:
    void start()
    {
        while(true)
        {
            bool access=false;
            string card;
            ifstream data("card.txt");
            data >> card;
            if(data.is_open())
            {
                Server *session = new Server();
                int attempts = 0;
                session -> getUserData(card);
                ///тут происходит работа с пользователем
                while(access!=true && attempts!=3 && !session->checkEnd())
                {
                    string pin;
                    cout<<"¬ведите пин код: ";
                    cin>>pin;
                    cout<<endl;
                    access = session->checkAccess(pin);
                    if(access == false)
                    {
                        cout<<"неверный пин-код"<<endl;
                        attempts++;
                        system("cls");
                    }
                }
                if(attempts == 3)
                {
                    cout<<"карта заблокирована"<<endl;
                    session->blockUser(card);
                }
                if(access)
                {

                }
                data.close();
                if(access) session->updateDataBase();
                delete session;
                remove("card.txt");
            }

            //  break;
        }





    }
};






int main()
{
    setlocale(LC_ALL, "rus");
    ATM *atm = new ATM();
    atm -> start();
    return 0;
}
