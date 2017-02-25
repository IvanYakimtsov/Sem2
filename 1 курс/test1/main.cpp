#include <iostream>
#include <conio.h>
#include<cstring>


using namespace std;



struct tovar
{ char name[100];};
void qs(tovar work[],int left,int right,int count)
{
int l=left;
int r=right;
char midname[20];
int mid=(l+r)/2;
strcpy(midname,work[mid].name);
count++;
while (l<=r)
{
while ((strcmp(work[l].name, midname) < 0))
 {
  l++;
   }
while ((strcmp(work[r].name, midname) > 0))
  {
   r--;
  }
if(l<=r){swap(work[l],work[r]); l++;r--;}
}
if(l<right)qs(work,l,right,count);
if(r>left)qs(work,left,r,count);
}


//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{  tovar work[100];
int i,n,count=0;
cout<<"Vvedite kolvo chisel: "<<endl;
cin>>n;
for (i=0;i<n;i++)
{cout<<"Vvedite chislo: ";
 cin>>work[i].name;
 }
 qs(work,0,n,count) ;

 for(i=0;i<n+1;i++)
{cout<<work[i].name<<" ";}
 getch();
        return 0;
}
//---------------------------------------------------------------------------

