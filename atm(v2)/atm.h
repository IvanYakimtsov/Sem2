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



class DataBase
{
public:
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


    int checkAccess(string card,string pin_inp)
    {
        string buff;
        ifstream data("dataBase.txt");
        while(true)
        {
            buff="";
            data >> buff;
            if(buff == card)
            {
                string pin;
                data >> pin;
                string blocking;
                data >> blocking;
                data.close();
                if(blocking == "1")
                {
                    return -1;
                }
                else
                {
                    if(pin_inp == pin) return 1;
                    else return 0;
                }

                break;
            }
        }
    }

    void blockCard(string card)
    {

        string buff;
        int line=0;
        ifstream data("dataBase.txt");
        while(true)
        {
            line++;
            buff="";
            data >> buff;
            if(buff == card)
            {
                string pin;
                data >> pin;
                string tmp;
                data>>tmp;
                string balance;
                data>>balance;
                data.close();
                remove_line("dataBase.txt", line-1);
                remove_line("dataBase.txt", line-1);
                remove_line("dataBase.txt", line-1);
                remove_line("dataBase.txt", line-1);
                ofstream data("dataBase.txt",ios_base::app);
                data<<card;
                data<<endl;
                data<<pin;
                data<<endl;
                data<<1;
                data<<endl;
                data<<balance;
                data<<endl;
                data.close();
            }
        }
    }
    vector<string> getData(string card)
    {
        vector<string> output;
        string buff;
        int line=0;
        ifstream data("dataBase.txt");
        while(true)
        {
            line++;
            buff="";
            data >> buff;
            if(buff == card)
            {
                string pin;
                data >> pin;
                string blocking;
                data >> blocking;
                string balance;
                data>>balance;
                data.close();
                remove_line("dataBase.txt", line-1);
                remove_line("dataBase.txt", line-1);
                remove_line("dataBase.txt", line-1);
                remove_line("dataBase.txt", line-1);
                output.push_back(card);
                output.push_back(pin);
                output.push_back(blocking);
                output.push_back(balance);
                break;
            }
        }
        return output;
    }


   void updateDataBase(string user,string pin,bool block,double balance)
   {
        ofstream data("dataBase.txt",ios_base::app);
        data<<user;
        data<<endl;
        data<<pin;
        data<<endl;
        data<<block;
        data<<endl;
        data<<balance;
        data<<endl;
        data.close();
   }
};

class Display
{
protected:
    void showMainDisplay()
        {
        cout<<"�������� ���������"<<endl<<endl;
        cout<<"1 ������ ��������"<<endl;
        cout<<"2 �������� �������"<<endl;
        cout<<"0 ������� �����"<<endl;
        }

};

class User
{
    string id;
    string pin;
    bool blocking_status;
    double balance;
public:
    void setData(string id_temp, string pin_temp, string blocking_status_temp, string balance_temp)
    {
        id = id_temp;
        pin = pin_temp;
        if(blocking_status_temp == "1") blocking_status = true;
        if(blocking_status_temp == "0") blocking_status = false;
        stringstream btmp;
        btmp << balance_temp;
        btmp >> balance;
    }
    double getBalance()
    {
      return balance;
    }

    void setBalance(double b){balance=b;}

    void update()
    {
    DataBase *data=new DataBase();
    data->updateDataBase(id,pin,blocking_status,balance);
    delete data;
    }
};

class OperationDisplay : public Display
{
protected:
    virtual void showMoneyDisplay() = 0;
    virtual void showBalanceDisplay(int) = 0;
};


class Money : public OperationDisplay
{
private:
     void showBalanceDisplay(int balance){};
     void showMoneyDisplay()
     {
        cout<<"�������� �����: "<<endl;
        cout<<"1 25"<<endl;
        cout<<"2 50"<<endl;
        cout<<"3 75"<<endl;
        cout<<"4 100"<<endl;
        cout<<"5 ������ �����"<<endl;
        cout<<"0 �����"<<endl;
     }
 public:
    int getMoney(double balance)
    {
        int sum = 0;
        while(true)
        {
            int i=-1;
            bool success=false;
            system("cls");
            showMoneyDisplay();
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
                cout<<"������� �����: ";
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
            if(sum <= balance)
            {
                system("cls");
                ofstream money("money.txt",ios_base::app);
                balance=balance-sum;
                cout<<"������ ��������"<<endl;
                Sleep(500);
                money<<sum;
                money<<endl;
            }
            else
            {
                while(true)
                {
                    system("cls");
                    cout<<"������������ �����"<<endl;
                    cout<<"0 �����"<<endl;
                    int i=-1;
                    cin>>i;
                    if(i==0) break;
                }
            }
        }
      return balance;
    }
};

class Balance : public OperationDisplay
{
private:
    void showMoneyDisplay(){};
    void showBalanceDisplay(int balance)
    {
       cout<<"������ �����: ";
       cout<<balance<<endl;
       cout<<"0 �����"<<endl;
    }
public:
    void getBalance(double balance)
    {
       system("cls");
       showBalanceDisplay(balance);
       while(true)
       {
           int i=-1;
           cin>>i;
           if(i==0) break;
       }
    }
};

class MainMenu : public Display
{
public:
    void showMenu(string card)
    {
        system("cls");
        User *user = new User();
        DataBase *data = new DataBase();
        vector<string> info;
        info=data->getData(card);
        user -> setData(info[0],info[1],info[2],info[3]);
        while(true)
        {
            system("cls");
            int choose;
            int sum;
            showMainDisplay();
            bool correct_input=true;
            cin>>choose;
            cout<<endl;
            switch(choose)
            {
            case 0:
            {
                correct_input == true;
                system("cls");
                break;
            }
            case 2:
            {
                Balance *b = new Balance();
                b->getBalance(user->getBalance());
                delete b;
                correct_input=false;
                break;
            }
            case 1:
            {
                Money *m = new Money();
                user->setBalance(m->getMoney(user->getBalance()));
                delete m;
                correct_input=false;
                break;
            }
            default:
                correct_input=false;
            }
            if(correct_input == true) break;
        }
     user->update();
     delete user;
    }
};

class ATM
{
public:
    void start()
    {
        while(true)
        {
            int access=0;
            string card;
            ifstream data("E:\card.txt");
            data >> card;
            if(data.is_open())
            {
                system("cls");
                int attempts=0;
                DataBase *dataB = new DataBase();
                while(access!=1 && attempts!=3 && access!=-1)
                {
                    string pin;
                    cout<<"������� ��� ���: ";
                    cin>>pin;
                    cout<<endl;
                    access = dataB ->checkAccess(card,pin);
                    if(access==0)
                    {
                        system("cls");
                        attempts++;
                        cout<<"�������� ���-���"<<endl;
                    }
                    if(access==-1)
                    {
                        system("cls");
                        cout<<"����� �������������"<<endl;
                        break;
                    }
                }

                if(attempts == 3)
                {
                    system("cls");
                    cout<<"����� �������������"<<endl;
                    dataB ->blockCard(card);
                }

                if(access == 1)
                {
                    MainMenu *menu = new MainMenu();
                    menu->showMenu(card);
                    delete menu;
                }
                delete dataB;
                data.close();
                while(true)
                {
                    system("cls");
                    cout<<"�������� �����"<<endl;
                    data.open("E:\card.txt");
                    if(!data.is_open()) break;
                    data.close();
                    Sleep(700);
                }
            }


            data.close();
            // break;
        }

    }



};

