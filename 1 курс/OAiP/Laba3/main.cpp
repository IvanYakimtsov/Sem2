//---------------------------------------------------------------------------
#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<io.h>
#include<fstream>
#include<string.h>
using namespace std;
#pragma hdrstop
//---------------------------------------------------------------------
struct person  {
      		char Fio[30];
      	      	double sball;
                int ntabel,time,tmoney,zarplata;
};
person Work[100];
void qsort(person Work[],int left,int right)
{
int l=left;
int r=right;
int mid=(l+r)/2;
while (l<=r)
{
while (Work[l].zarplata<Work[mid].zarplata) l++;
while(Work[r].zarplata>Work[mid].zarplata) r--;
if (l<=r) { swap(Work[l],Work[r]); l++; r--;}
}
if (l<right) qsort(Work, left, right);
if (left<r) qsort(Work, left,right );
}
#pragma argsused
int main(int argc, char* argv[])
{int i,n,e,sverhur;

cout<<"vvedite colvo rabotnikow:";
cin>>n;
ifstream Sp("Spisok.txt");
for(int i=0;i<n;i++){
Sp>>Work[i].Fio;
Sp>>Work[i].ntabel;
Sp>>Work[i].time;
Sp>>Work[i].tmoney;
if(Work[i].time>144) sverhur=Work[i].time-144;
Work[i].zarplata=(Work[i].time*Work[i].tmoney+sverhur*2*Work[i].tmoney)-
0.12*(Work[i].time*Work[i].tmoney+sverhur*2*Work[i].tmoney);
}
qsort(Work,0,n);

ofstream f("spisok_obrabotan.txt");
for(i=0;i<n;i++)
{f<<"Worker:"<<Work[i].Fio<<endl<<"dannie: "<<Work[i].ntabel<<endl<<"time: "<<
Work[i].time<<endl<<"time/money: "<<Work[i].tmoney<<endl<<"zarplata: "<<
Work[i].zarplata<<endl;}



getch();
        return 0;
}
//---------------------------------------------------------------------------
