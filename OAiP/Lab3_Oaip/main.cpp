//---------------------------------------------------------------------------
#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<io.h>
#include<fstream>
#include<string.h>
using namespace std;

//---------------------------------------------------------------------------
struct person  {
      		char Fio[30];

                int ntabel,time,tmoney,zarplata;
};
person Work[100];

//----------------------------------------------------
void qs(person Work[],int left,int right)
{
int l=left;
int r=right;
int mid=(l+r)/2;
while (l<=r)
{
while(Work[l].zarplata<Work[mid].zarplata) l++;
while(Work[r].zarplata>Work[mid].zarplata) r--;
if(l<=r){swap(Work[l],Work[r]); l++;r--;}
}
if(l<right)qs(Work,l,right);
if(r>left)qs(Work,left,r);
}

//----------------------------------------------------
int BSearch(person Work[], int key,int n)
{
int left=0, right=n, mid;
while (left<=right)
{
mid=left+(right-left)/2;
if (key<Work[mid].zarplata) right=mid-1;
else if (key>Work[mid].zarplata) left=mid+1;
else return mid;
}
return -1;
}
//-----------------------------------------------
int main(int argc, char* argv[])
{int i,n,e,sverhur;


ifstream Sp("Spisok.txt");
Sp>>n;
for(int i=0;i<n;i++){
Sp>>Work[i].Fio;
Sp>>Work[i].ntabel;
Sp>>Work[i].time;
Sp>>Work[i].tmoney;
sverhur=0;
if(Work[i].time>144) sverhur=Work[i].time-144;
Work[i].zarplata=((Work[i].time-sverhur)*Work[i].tmoney+sverhur*2*Work[i].tmoney)-
0.12*(Work[i].time*Work[i].tmoney+sverhur*2*Work[i].tmoney);
}
qs(Work,0,n-1);

ofstream f("spisok_obrabotan.txt");
for(i=0;i<n;i++)
{f<<"Worker:"<<Work[i].Fio<<endl<<"id: "<<Work[i].ntabel<<endl<<"time: "<<
Work[i].time<<endl<<"time/money: "<<Work[i].tmoney<<endl<<"zarplata: "<<
Work[i].zarplata<<endl<<"/---------------------------"<<endl;}
int zarp;
cout<<endl<<"vvedite zarplatu sotrudnika"<<endl;
cin>>zarp;
if (BSearch(Work,zarp,n)==-1) cout<<"\nЁлемент не найден";
else cout<<"\nNomer Sotrudnika v spiske: "<<BSearch(Work,zarp,n)+1;

getch();
        return 0;
}
//---------------------------------------------------------------------------
