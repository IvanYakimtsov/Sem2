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
{  // Загрузка числа в стек

   Node *el = new Node;
   el->inf = dat;
   el->next = st;
   st=el;
}

int pop(Node *&st)
{       // Извлечение из стека
   int value = st->inf;
   Node *temp = st;
   st = st->next;
   delete temp;

   return value;
}

int peek(Node *st)
{     // Получение числа без его извлечения
   return st->inf;
}

//==============================================================

Node **graph;   // Массив списков смежности
const int vertex = 1; // Первая вершина

FILE* fi = fopen("euler.in","r"); //Файл с матрицей смежности
FILE* fo = fopen("euler.out","w"); // Результирующий файл

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
{ // Удаление вершины key из списка

   if(l->inf==key)  {Node *tmp=l; l=l->next; delete tmp;}
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

int eiler(Node **gr,int num)
{ // Определение эйлеровости графа

   int count;
   for(int i=0;i<num;i++)
   {  //проходим все вершины

      count=0;
      Node *tmp=gr[i];

	 while(tmp)
         {       // считаем степень
            count++;
	    tmp=tmp->next;
         }
      if(count%2==1)return 0; // степень нечетная
   }
   return 1;   // все степени четные
}

void eiler_path(Node **gr)
{ //Построение цикла
   Node *S = NULL;// Стек для  пройденных вершин
   int v=vertex;// 1я вершина (произвольная)
   int u;

   push(S,v); //сохраняем ее в стек
   while(S)
       {  //пока стек не пуст

         v = peek(S); // текущая вершина
         if(!gr[v]){ // если нет инцидентных ребер
         v=pop(S);if(S) {fprintf(fo,"%d\-",v+1);}
                     else {fprintf(fo,"%d\ ",v+1);} //выводим вершину
       }
       else
       {
         u=gr[v]->inf; push(S,u);  //проходим в следующую вершину
         del(gr[v],u); del(gr[u],v); //удаляем пройденное ребро
      }
   }
}

int main()
{
   int n; // Количество вершин
   int m;
   int zn;// Текущее значение
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
