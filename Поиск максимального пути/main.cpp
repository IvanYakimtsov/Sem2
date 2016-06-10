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
   FILE* fi;
   int test=0;
    while(test<5)
   {
    switch(test)
    {
        case 0:{fi = fopen("1.txt","r");cout<<endl<<"test1";break;}
        case 1:{fi = fopen("2.txt","r");cout<<endl<<"test2";break;}
        case 2:{fi = fopen("3.txt","r");cout<<endl<<"test3";break;}
        case 3:{fi = fopen("4.txt","r");cout<<endl<<"test4";break;}
        case 4:{fi = fopen("5.txt","r");cout<<endl<<"test5";break;}
    }
   setlocale(LC_ALL,"Russian");
   int n,N;
   fscanf(fi,"%d",&N);
   fscanf(fi,"%d",&n);
   Node *Graph;
   Graph=new Node[N];
   for(int i=0;i<N;i++)
   {
    Graph[i].name=i;
    Graph[i].priv=-1;
    Graph[i].weight=0;
    Graph[i].check=true;
   }
  // cout<<endl<<"Список смежности: "<<endl;
   vector<vector<int> > L(n);
   int tmp;
   for(int i=0;i<n;i++)
    for(int j=0;j<3;j++)
   {
       fscanf(fi,"%d",&tmp);
       if(j!=2) L[i].push_back(tmp-1);
       else L[i].push_back(tmp);
   }


  for(int i=0;i<n;i++)
  {
      Graph[L[i][0]].vert.push_back(L[i][1]);
      Graph[L[i][0]].vert.push_back(L[i][2]);
      Graph[L[i][1]].vert.push_back(L[i][0]);
      Graph[L[i][1]].vert.push_back(L[i][2]);
  }






   int begin;
   fscanf(fi,"%d",&begin);
   begin=begin-1;;
   int end;
   fscanf(fi,"%d",&end);
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
   test++;
   }
    return 0;
}
