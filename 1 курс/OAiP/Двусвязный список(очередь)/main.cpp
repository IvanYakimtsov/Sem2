#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define RANGE 50
using namespace std;
struct Node
{
    int inf;
    Node *next,*priv;
};
void push(Node *&ln,int data,Node *&ln_end)
{

    if(!ln)
    {
        ln=new Node;
        ln->inf=data;
        ln->next=NULL;
        ln->priv=NULL;
        ln_end=ln;
        return;
    }
    else
    {
        Node *tmp=ln;
        while(tmp->next)tmp=tmp->next;
        Node *el=new Node;
        el->inf=data;
        el->next=NULL;
        el->priv=tmp;
        tmp->next=el;
        ln_end=el;
    }
}
void push_at_begin(Node *&ln,int data)
{

    if(!ln)
    {
        ln=new Node;
        ln->inf=data;
        ln->next=NULL;
        ln->priv=NULL;
        return;
    }
    else
    {
        Node *el = new Node;
        el->inf = data;
        el->next = ln;
        el->priv=NULL;
        ln->priv=el;
        ln=el;
    }
}

void Show_quene(Node *st)
{
    while(st!=NULL)
    {
        cout<<st->inf<<" ";
        st=st->next;
    }
}
void Show_quene_from_end(Node *st)
{
    while(st!=NULL)
    {
        cout<<st->inf<<" ";
        st=st->priv;
    }
}
//-----------------------------------------------------------------------------------------------------
void copy_quene(Node *st,Node *&st1)
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
int pop(Node *&st)
{
    // Извлечение из стека

    int value = st->inf;
    Node *temp = st;
    st = st->next;
    delete temp;

    return value;
}
void del(Node *&st)
{
    Node *temp = st;
    st = st->next;
    delete temp;

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
void Del_Steck(Node *p)
{
    Node *t;
    while( p != NULL)
    {
        t = p;
        p = p -> next;
        delete t;
    }
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
//-----------------------------------------------------------------------------------------------------
int main()
{
    setlocale(LC_ALL,"Russian");
    cout<<"Введите размер списка: ";
    int n;
    cin>>n;
    cout<<endl;
    Node *Q=NULL;
    Node *Q_END=NULL;
    int e=0;
    for (int i=0; i<n; i++)
    {
        e=rand() % RANGE;
        push(Q,e,Q_END);
    }
    cout<<"Вывод очереди с начала: "<<endl;
    Show_quene(Q);
    cout<<endl;
    cout<<"Вывод очереди с конца: "<<endl;
    Show_quene_from_end(Q_END);
    Node *Q1 = NULL;
    copy_quene(Q,Q1);
    Sort_info(Q1);
    int max=0,min=0;
    min=pop(Q1);
    for (int i=0; i<n-2; i++)
    {
        del(Q1);
    }
    max=pop(Q1);
    task_lab5(Q,max,min);
    cout<<endl;
    cout<<"Вывод очереди задания: "<<endl;
    Show_quene(Q);
    cout<<endl;
    cout<<"Добавление элемента в начало: "<<endl;
    push_at_begin(Q,666);
    Show_quene(Q);
    cout<<endl;
    cout<<"Вывод очереди с конца: "<<endl;
    Show_quene_from_end(Q_END);
    Del_Steck(Q);
    Del_Steck(Q1);

    return 0;
}
