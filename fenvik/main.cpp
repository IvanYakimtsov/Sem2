#include "fenvik.h"
#include <iostream>

using namespace std;



int main()
{
fen *a=new fen;
fen *t=new fen;
setlocale(LC_ALL,"Russian");
    int nn,delta,x,l,r;
cout<<"������� ���������� ��������� : ";
cin>>nn;
FenvikCreate(nn,t,a);

int count;
cout<<"\n�������� ��������: 1-����� �� �������.  2-���������� ����� � �������. ";
cin>>count;
switch(count)
{
case 1:
    {
       cout<<"\n������� ����� � ������ �������: ";
cin>>l>>r;
FenvikSum(l,r,t,a);
break;
    }

case 2:
    {
      cout<<"�������  x � delta"<<endl;
cin>>x>>delta;
FenvikAdd(x,delta,t,a);



break;

    }
}



}

