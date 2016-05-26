#include <iostream>
#include <vector>
#include <list>

using namespace std;

void peresechenie( vector <vector<int> > A,vector <vector<int> > B,int a,int b)
{
    vector <vector<int> > C;  ///cоздаем множество С
    //------------------------------------------------------------------------------

    for(int i=0; i<a; i++)///если i меньше а прибавляем к i единицу
    {
        for(int j=0; j<b; j++)///если j меньше b прибавляем к j единицу
        {
            if(A[i]==B[j])///Если i-й элемент множества A и j-й элемент множества B равны
            {

                C.push_back(A[i]);///добавляем i-й элемент в множество C
                break;
            }

        }

    }
    ///Множество С- пересечение множеств А и В.
    cout<<endl;
    cout<<"Пересечение: "<<endl;//выводим пересечение
    cout<<"{";
    for (int i = 0; i < C.size(); i++)
    {
        cout<<"<";
        cout<<C[i][0];
        cout<<",";
        cout<<C[i][1];
        cout<<">";
    }
    cout<<"}"; ///выводим на экран множество С
    cout<<endl<<"----------------------------------------------"<<endl;
}

void Obedinenie( vector <vector<int> > A,vector <vector<int> > B,int a,int b)///Операция объединения
{
    vector <vector<int> > C1(B); ///Создаём множество С1 равное множеству В.
    for(int i=0; i<a; i++) ///если i меньше а прибавляем к i единицу
    {
        for(int j=0; j<b; j++) ///если j меньше b прибавляем к b единицу
        {
            if(A[i]==C1[j])
            {
                C1[j][0]=0; ///Заменяем j элемент множества С1 на 0.
                break;
            }

        }

    }
    vector <vector<int> > C(A); ///Cоздаем множество С равное множеству А.
    for(int i_b=0; i_b<b; i_b++) if(C1[i_b][0]!=0)
        {
            C.push_back(C1[i_b]);  ///Копируем элементы множество C1 не равные нулю в множество С.
        }
    ///---------------------------------------------------------------



    cout<<"объединение:"<<endl; ///С-объединение множеств.
    cout<<"{";
    for (int i = 0; i < C.size(); i++)
    {
        cout<<"<";
        cout<<C[i][0];
        cout<<",";
        cout<<C[i][1];
        cout<<">";
    }
    cout<<"}"; ///выводим на экран множество С
    cout<<endl<<"----------------------------------------------"<<endl;


}
void Raznost( vector <vector<int> > A,vector <vector<int> > B,int a,int b) ///операция разности
{
    vector <vector<int> > C2(A);   ///Создаём множество С2 равное множеству А.
    for(int j=0; j<b; j++) ///если j<b увеличиваем j на единицу
    {
        for(int i=0; i<a; i++) ///если i<b увеличиваем i на единицу
        {
            if(B[i]==C2[j]) ///Если i-ый элемент множества A равен j-ому элементу множества С2
            {
                C2[j][0]=0; ///Заменяем j элемент множества С2 на 0
                break;
            }

        }

    }
    cout<<"разность:"<<endl;
      cout<<"{";
    for (int i = 0; i < C2.size(); i++)
    {
        if(C2[i][0]!=0)
        {cout<<"<";
        cout<<C2[i][0];
        cout<<",";
        cout<<C2[i][1];
        cout<<">";}
    }
    cout<<"}"; ///выводим разность на экран
    cout<<endl<<"----------------------------------------------"<<endl;

}
void sem_razn( vector <vector<int> > A,vector <vector<int> > B,int a,int b) ///операция семметрической разности
{
    vector <vector<int> > C6(A); ///Создаем множество С6 равное множеству А
    for(int i=0; i<b; i++)
    {
        for(int j=0; j<a; j++)
        {
            if(B[i]==C6[j]) ///Если i-ый элемент множества B равен j-ому элементу множества С6
            {
                C6[j][0]=0; ///Заменяем j элемент С6 на 0
                break;
            }

        }

    }
    vector <vector<int> > C7(B); ///Создаем множество С7 равное множеству В
    for(int i=0; i<b; i++) ///если i меньше b увеличиваем i на 1
    {
        for(int j=0; j<a; j++) ///если j меньше a увеличиваем j на 1
        {
            if(A[i]==C7[j]) ///Если i-ый элемент множества А равен j-ому элементу множества С7
            {
                C7[j][0]=0; ///заменяем j элемент множества С7 на 0
                break;
            }

        }

    }

    cout<<"симметрическая разность:"<<endl; ///выводим симметрическую разность на экран
  cout<<"{";
    for (int i = 0; i < C6.size(); i++)
    {
        if(C6[i][0]!=0)
        {cout<<"<";
        cout<<C6[i][0];
        cout<<",";
        cout<<C6[i][1];
        cout<<">";}
    }
    for (int i = 0; i < C7.size(); i++)
    {
        if(C7[i][0]!=0)
        {cout<<"<";
        cout<<C7[i][0];
        cout<<",";
        cout<<C7[i][1];
        cout<<">";}
    }
    cout<<"}"; ///выводим симметрическую разность на экран
    cout<<endl<<"----------------------------------------------"<<endl;
}



void Composition( vector <vector<int> > A,vector <vector<int> > B,int a,int b) ///операция композиции
{
  int tmp=a;
  if(b<a) tmp=b;
  vector <vector<int> > C9(A);///Создаем множество С8 равное множеству А
  for(int i=0;i<tmp;i++)
  {
      C9[i][1]=B[i][1]; ///заменяем вторые компоненты i-го кортежа графика С9 на вторые компоненты i-го кортежа графика В
  }
cout<<"композиция А и В:"<<endl;
   cout<<"{"; ///выводим композицию на экран
    for (int i = 0; i < tmp; i++)
    {
        cout<<"<";
        cout<<C9[i][0];
        cout<<",";
        cout<<C9[i][1];
        cout<<">";
    }
    cout<<"}"; ///выводим композицию на экран
    cout<<endl<<"----------------------------------------------"<<endl;
}


void inversion(vector <vector<int> > A) ///операция инверсии
{
  vector <vector<int> > C8(A); ///Создаем множество С8 равное множеству А
  for(int i=0;i<C8.size();i++)
  {
      swap(C8[i][0],C8[i][1]);
  }
  cout<<"инверсия графика А:"<<endl;
   cout<<"{"; ///выводим инверсию на экран
    for (int i = 0; i < C8.size(); i++)
    {
        cout<<"<";
        cout<<C8[i][0];
        cout<<",";
        cout<<C8[i][1];
        cout<<">";
    }
    cout<<"}"; ///выводим инверсию на экран
    cout<<endl<<"----------------------------------------------"<<endl;

}


int main()
{
    bool kol=true;
    setlocale(LC_ALL,"Russian");
    cout<<"Ведите мощность множества А: " ;
    int a;                                  ///Пользователь задает мощность множества A (a)
    cin>>a;
    vector <vector<int> > A(a);
    cout<<"Ведите мощность множества В: ";
    int b;
    cin>>b;                                ///Пользователь задает мощность множестваB (b)
    vector <vector<int> > B(b);
   int tmp1=0,tmp2=0;
    cout<<"введите кортежи множество А: ";
    cout<<endl;
    for (int i = 0; i < a; i++)
    {
        cout<<i+1<<" "<<"кортеж:";
        cout<<endl;
        tmp1=0;
        tmp2=0;
        cin>>tmp1;
        A[i].push_back(tmp1);
        cin>>tmp2;
        A[i].push_back(tmp2);
    }
    cout<<endl;
    cout<<"введите кортежи множество B: ";
    cout<<endl;
    for (int i = 0; i < b; i++)
    {
        cout<<i+1<<" "<<"кортеж:";
        cout<<endl;
        tmp1=0;
        tmp2=0;
        cin>>tmp1;
        B[i].push_back(tmp1);
        cin>>tmp2;
        B[i].push_back(tmp2);
    }
    cout<<"множество А: ";
    cout<<"{";
    for (int i = 0; i < a; i++)
    {
        cout<<"<";
        cout<<A[i][0];
        cout<<",";
        cout<<A[i][1];
        cout<<">";
    }
    cout<<"}";
    cout<<endl;
    cout<<"множество B: ";
    cout<<"{";
    for (int i = 0; i < b; i++)
    {
        cout<<"<";
        cout<<B[i][0];
        cout<<",";
        cout<<B[i][1];
        cout<<">";
    }
    cout<<"}";
    cout<<endl;
    ///---------------------------------------------------------------------------------------------------------

     int in;
    ///Пользователь выбирает операцию над множествами-------------------------------------------------------------
        while(kol)
        {

            cout << "1.Операция пересечения АВ." << endl;
            cout << "2.Операция объединения АВ." << endl;
            cout << "3.Операция разность АВ." << endl;
            cout << "4.Операция инверсии А." << endl;
            cout << "5.Операция композиции АВ." <<endl;
            cout << "6.Операция симметрическоф разности." << endl;
            cout << "7.Завершить программу." << endl;
            cin >> in;
            switch (in)
            {
            case 1:
        {
            peresechenie(A,B,a,b);    ///пересечение
            break;
        }
            case 2:
        {
            Obedinenie(A,B,a,b);    ///объединение
            break;
        }
            case 3:
        {
            Raznost(A,B,a,b);    ///разность
            break;
        }
            case 4:
        {
            inversion(A);    ///инверсия
            break;
        }
            case 5:
        {
            Composition(A,B,a,b);    ///композиция
            break;
        }
            case 6:
        {
            sem_razn(A,B,a,b);    ///симметрическая разность
            break;
        }
            case 7:
        {
            kol=false;    ///завершение работы
            break;
        }
            default:
        {
            cout<<"Error!! ";    ///ошибка при вводе
            break;
        }
            }

        }
    ///---------------------------------------------------------------------------------------------------------




    return 0;
}
