#include "fenvik.h"

//fen *a=new fen;
//fen *t=new fen;

int n;

void init (int nn,fen *t,fen *a)
{
	n = nn;
	t->f.assign (n, 0);
}

int sum (int r,fen *t,fen *a)
{
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t->f[r];
	return result;
}

void inc (int i, int delta,fen *t,fen *a)
{
	for (; i < n; i = (i | (i+1)))
		t->f[i] += delta;
}


void init (fen *t,fen *a)
{
	init ((int) a->f.size(),t,a);
	for (unsigned i = 0; i < a->f.size(); i++)
		inc (i, a->f[i],t,a);
}

void FenvikSum(int l,int r,fen *t,fen *a)
{
    cout<<"Сумма : "<<sum (r-1,t,a) - sum (l-2,t,a)<<endl;
}


void FenvikAdd(int x,int delta,fen *t,fen *a)
{
    a->f[x-1]=a->f[x-1]+delta;
inc(x-1,delta,t,a);
cout<<"Массив: ";
for(int i=0;i<a->f.size();i++)
{
  cout<<a->f[i]<<" ";
}
cout<<"\nДерево Фенвика для обновленного массива: ";
for(int i=0;i<t->f.size();i++)
{
  cout<<t->f[i]<<" ";
}

}


void FenvikCreate(int nn,fen *t,fen *a)
{
    a->f.assign(nn,0);
 for(int i=0;i<nn;i++)
 {cout<<"Введите элемент: ";
  cin>>a->f[i];

}

init(nn,t,a);
init(t,a);

cout<<"Исходный массив: ";
 for(int i=0;i<nn;i++)
 {
    cout<<a->f[i]<<" ";
 }

cout<<endl<<"Дерево Фенвика: ";
 for(int i=0;i<nn;i++)
 {
    cout<<t->f[i]<<" ";
 }


}

