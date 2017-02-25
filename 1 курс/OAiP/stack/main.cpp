#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define RANGE 50
using namespace std;


struct Node
{
    int inf;
    Node *next;
};

void push(Node *&st,int dat)
{
    // Загрузка числа в стек

    Node *el = new Node;
    el->inf = dat;
    el->next = st;
    st=el;
}


int pop(Node *&st)
{  int data;
   Node *tmp=st;
   data=st->inf;
   st=st->next;
   delete tmp;
   return data;
}

void del(Node *&st)
{
    Node *temp = st;
    st = st->next;
    delete temp;

}

int peek(Node *st)
{
    // Получение числа без его извлечения
    return st->inf;
}
void Show_Steck(Node *st)
{
    while(st!=NULL)
    {
        cout<<st->inf<<" ";
        st=st->next;
    }
}
void Sort_info(Node *p)
{
    Node *t = NULL, *t1;
    int r;
    do
    {
        for (t1=p; t1 -> next != t; t1 = t1-> next)
            if (t1-> inf > t1-> next -> inf)
            {
                r = t1-> inf;
                t1-> inf = t1-> next -> inf;
                t1-> next -> inf = r;
            }
        t = t1;
    }
    while (p -> next != t);
}
void Del_Steck(Node *&p)
{
    Node *t;
    while( p != NULL)
    {
        t = p;
        p = p -> next;
        delete t;
    }
}
void copy_vv_steck(Node *st,Node *&st1)
{
    while(st!=0)
    {
        Node *el = new Node;
        el->inf = st->inf;
        el->next = st1;
        st1=el;
        st=st->next;
    }

}
copy_steck(Node *st,Node *&st1)
{
    Node *S1 = NULL;
    copy_vv_steck(st,S1);
    copy_vv_steck(S1,st1);
    Del_Steck(S1);
}
void task_lab5(Node *st,int max1,int min1)
{
    int temp;
    while(st!=NULL)
    {
        temp=st->inf;
        if(temp==max1)
            st->inf=min1;


        if(temp==min1)
            st->inf=max1;

        st=st->next;
    }
}
void choose_element(Node *&st,int f)
{int i=0;
    while(i!=f-1)
    {
        st=st->next;
        i++;
    }
}
void Delete(Node* &l,int number)
{ // Удаление вершины key из списка
    int key=0;
 Node *Head=l;
 int i=0;
    while(i!=number-1)
    {
        l=l->next;
        i++;
    }
    key=l->inf;
    l=Head;
   if(l->inf==key){Node *tmp=l; l=l->next; delete tmp;}
   else
        {
	 Node *tmp=l;
	 while(tmp)
         {
	    if(tmp->next) // есть следующая вершина
	       if(tmp->next->inf==key)
                  {  // и она искомая
		     Node *tmp2=tmp->next;
	             tmp->next=tmp->next->next;
	             delete tmp2;
	           }
	       tmp=tmp->next;
	 }
   }
}
int main()
{
    setlocale(LC_ALL,"Russian");
    cout<<"Введите количество элементов стэка: ";
    int n;
    cin>>n;
    cout<<endl;
    int e=0;
    Node *S = NULL;
    for (int i=0; i<n; i++)
    {
       // e=rand() % RANGE;
        push(S,i);

    }
    Show_Steck(S);

    Delete(S,5);

    cout<<endl;
    Show_Steck(S);







   // Node *S1 = NULL;
   // copy_steck(S,S1);
  //  cout<<endl;
   // Show_Steck(S1);
    //Sort_info(S1);



   /* int max=0,min=0;
    min=pop(S1);
    for (int i=0; i<n-2; i++)
    {
        del(S1);
    }
    min=pop(S1);
    task_lab5(S,max,min);
    cout<<endl;
    Show_Steck(S);*/
    Del_Steck(S);
   // Del_Steck(S1);
    return 0;
}
