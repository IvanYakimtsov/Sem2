#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;


struct Node
{
    vector<int> vert;
    int name,priv,weight;
    bool check;
};

int main()
{
   setlocale(LC_ALL,"Russian");
   cout<<"количество вершин: ";int N;cin>>N;
   Node *Graph;
   Graph=new Node[N];
   for(int i=0;i<N;i++)
   {
    Graph[i].name=i;
    Graph[i].priv=-1;
    Graph[i].weight=0;
    Graph[i].check=true;
   }
   cout<<endl<<"Список смежности: "<<endl;
   int tmp;
   int g=0;
   while(g<N)
   {
      cin>>tmp;
      if(tmp!=-1) Graph[g].vert.push_back(tmp);
      if(tmp==-1) g++;
   }
   cout<<"номер начальной вершины: ";
   int begin;
   cin>>begin;
   begin=begin-1;;
   cout<<endl<<"номер конечной вершины: ";
   int end;
   cin>>end;
   end=end-1;
   cout<<endl;
   swap(Graph[0],Graph[begin]);
   swap(Graph[N-1],Graph[end]);
       for(int e=0;e<N;e++)
       {
           for(int i=0;i<Graph[e].vert.size()-1;i=i+2)
           {
               tmp=Graph[e].vert[i];
               for(int j=0;j<N;j++) if(Graph[j].name==tmp) {tmp=j;break;}
               if(Graph[tmp].weight<Graph[e].weight+Graph[e].vert[i+1] && Graph[tmp].check)
               {
                   Graph[tmp].weight=Graph[e].weight+Graph[e].vert[i+1];
                   Graph[tmp].priv=Graph[e].name;
               }
           }
            Graph[e].check=false;
       }
       swap(Graph[0],Graph[begin]);
       swap(Graph[N-1],Graph[end]);

       int e=Graph[end].priv;
       cout<<Graph[end].name+1<<" ";
       while(e!=begin)
       {
          cout<<Graph[e].name+1<<" ";
          e=Graph[e].priv;
       }
       cout<<Graph[begin].name+1<<" ";


    return 0;
}
