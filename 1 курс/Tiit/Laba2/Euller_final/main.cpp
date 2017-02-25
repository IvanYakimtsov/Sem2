#include <iostream>
#include <stdio.h>
using namespace std;
struct Node
{
   int inf;
   Node *next;
};

//============================Stack==============================


void push(Node *&st,int dat)
{  // �������� ����� � ����

   Node *el = new Node;
   el->inf = dat;
   el->next = st;
   st=el;
}

int pop(Node *&st)
{       // ���������� �� �����
   int value = st->inf;
   Node *temp = st;
   st = st->next;
   delete temp;

   return value;
}

int peek(Node *st)
{     // ��������� ����� ��� ��� ����������
   return st->inf;
}

//==============================================================

Node **graph;   // ������ ������� ���������
const int vertex = 1; // ������ �������

FILE* fi = fopen("euler.in","r"); //���� � �������� ���������
FILE* fo = fopen("euler.out","w"); // �������������� ����

void add(Node *&ln,int data)
{

    if(!ln)
    {
        ln=new Node;
        ln->inf=data;
        ln->next=NULL;
        return;
    }
    else
    {
        Node *tmp=ln;
        while(tmp->next)tmp=tmp->next;
        Node *el=new Node;
        el->inf=data;
        el->next=NULL;
        tmp->next=el;
    }
}

void del(Node* &l,int key)
{ // �������� ������� key �� ������

   if(l->inf==key)  {Node *tmp=l; l=l->next; delete tmp;}
   else
     {
         Node *tmp=l;
         while(tmp)
         {
               if(tmp->next) // ���� ��������� �������
               if(tmp->next->inf==key)
               {  // � ��� �������
                     Node *tmp2=tmp->next;
                     tmp->next=tmp->next->next;
                     delete tmp2;
               }
               tmp=tmp->next;
         }
   }
}

int eiler(Node **gr,int num)
{ // ����������� ����������� �����

   int count;
   for(int i=0;i<num;i++)
   {  //�������� ��� �������

      count=0;
      Node *tmp=gr[i];

	 while(tmp)
         {       // ������� �������
            count++;
	    tmp=tmp->next;
         }
      if(count%2==1)return 0; // ������� ��������
   }
   return 1;   // ��� ������� ������
}

void eiler_path(Node **gr)
{ //���������� �����
   Node *S = NULL;// ���� ���  ���������� ������
   int v=vertex;// 1� ������� (������������)
   int u;

   push(S,v); //��������� �� � ����
   while(S)
       {  //���� ���� �� ����

         v = peek(S); // ������� �������
         if(!gr[v]){ // ���� ��� ����������� �����
         v=pop(S);if(S) {fprintf(fo,"%d\-",v+1);}
                     else {fprintf(fo,"%d\ ",v+1);} //������� �������
       }
       else
       {
         u=gr[v]->inf; push(S,u);  //�������� � ��������� �������
         del(gr[v],u); del(gr[u],v); //������� ���������� �����
      }
   }
}

int main()
{
   int n; // ���������� ������
   int m;
   int zn;// ������� ��������
   int A[2];
   fscanf(fi,"%d",&n); graph=new Node*[n];
   fscanf(fi,"%d",&m);
   for(int i=0;i<n;i++)graph[i]=NULL;
   for(int i=0;i<m;i++)
   {
     for(int j=0;j<2;j++)
        {
             fscanf(fi,"%d",&zn);
             A[j]=zn;
        }
        add(graph[A[0]-1],(A[1]-1));
        add(graph[A[1]-1],(A[0]-1));
   }
  if(eiler(graph,n)){fprintf(fo,"Yes\n");eiler_path(graph);}
  else fprintf(fo,"No");

   return(0);
}
