#include "fenvik.h"
#include <iostream>

using namespace std;



int main()
{
fen *a=new fen;
fen *t=new fen;
setlocale(LC_ALL,"Russian");
    int nn,delta,x,l,r;
cout<<"Введите количество элементов : ";
cin>>nn;
FenvikCreate(nn,t,a);

int count;
cout<<"\nВыберите действие: 1-Сумма на отрезке.  2-Обновление числа в массиве. ";
cin>>count;
switch(count)
{
case 1:
    {
       cout<<"\nВведите левую и правую границы: ";
cin>>l>>r;
FenvikSum(l,r,t,a);
break;
    }

case 2:
    {
      cout<<"Введите  x и delta"<<endl;
cin>>x>>delta;
FenvikAdd(x,delta,t,a);



break;

    }
}



}

