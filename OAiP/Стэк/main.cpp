#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<ctime>
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

int peek(Node *st)
{
    // Получение числа без его извлечения
    return st->inf;
}
void copy_vise_versa_steck(Node *st,Node *&st1)
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
/*void Del_1(Node *&p)
{
    Node *t,*begin=p;
    while( p != NULL)
    {

        t = p->next;
        if(p->next!=NULL) p->next=p->next->next;
        p = p -> next;
        delete t;
    }
    p=begin;
}*/

void Del_1(Node *&p)
{
    Node *t,*begin=p,*b1;
    while(p->inf % 2 == 0)
    {
        t=p;
        delete t;
        p = p -> next;
    }
    begin=p;

    while(p)
    {
        while(true)
        {
            if(p->next)
            {
                if(p->next->inf % 2 == 0)
                {
                    t=p->next;
                    delete t;
                    p->next = p -> next->next;
                }
                else break;
            }
            else break;
        }
        if(p->next) p=p->next;
        else break;
    }
    p=begin;
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


int find_max(Node *&st1)
{
    int max=0;
    while(st1)
    {
        if(st1->inf>max) max=st1->inf;
        st1=st1->next;
    }
    return max;
}

int find_min(Node *&st1)
{
    int min=10000;
    while(st1)
    {
        if(st1->inf<min) min=st1->inf;
        st1=st1->next;
    }
    return min;
}

void laba5_K(Node *&st1, Node *&st2)
{
    int max=0;
    Node *st1_begin=st1;
    max=find_max(st1);
    st1=st1_begin;
    while(st1)
    {
        if(st1->inf!=max)
        {

            if(!st2)
            {

                st2=new Node;
                st2->inf=st1->inf;
                st2->next=NULL;
            }
            else
            {

                Node *tmp=st2;
                while(tmp->next)tmp=tmp->next;
                Node *el=new Node;
                el->inf=st1->inf;
                el->next=NULL;
                tmp->next=el;
            }
        }
        else break;
        st1=st1->next;
    }
    st1=st1_begin;
    Show_Steck(st2);
    cout<<endl;

}

void laba5_L(Node *&st1)
{
    int max=0,min=0;
    Node* st1_begin=st1;
    max=find_max(st1);
    st1=st1_begin;
    min=find_min(st1);
    st1=st1_begin;
    while(st1)
    {
        if(st1->inf==min) st1->inf=max;
        else if(st1->inf==max) st1->inf=min;
        st1=st1->next;
    }
    st1=st1_begin;

}

int main()
{
    srand(time(0));
    setlocale(LC_ALL,"Russian");
    cout<<"Введите количество элементов стэка: ";
    int n;
    cin>>n;
    cout<<endl;
    int e=0;
    Node *S = NULL;
    //  push(S,6);
    for (int i=0; i<n; i++)
    {
         e=rand() % 100;
        //cin>>e;
        push(S,e);

    }
    Show_Steck(S);
    cout<<endl;
    /* Node *S1 = NULL;
     copy_vise_versa_steck(S,S1);
     Sort_info(S1);
     int max=0,min=0;
     min=pop(S1);
     for (int i=0; i<n-2; i++)
     {
         del(S1);
     }
     max=pop(S1);
     task_lab5(S,max,min);
     cout<<endl;*/

    //del_1(S1);
    Del_1(S);
    // Node *S1=NULL;
    //  laba5_K(S,S1);
    //laba5_L(S);


    Show_Steck(S);
    cout<<endl;





    Del_Steck(S);
    cout<<endl;


    return 0;
}
