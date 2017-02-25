#include <iostream>
#include <vector>
#include <iterator>
#include <stdio.h>
using namespace std;

int finish=2;

void DFS(int v, vector<bool> &mark, vector<vector<int> > &graph,vector<int> &prior,int from)
{
    if (mark[v])  // ���� �� ����� ��� ����, �� ��� ������ ������ ������
    {
        return;
    }
    mark[v] = 1;   // ��������, ��� �� ����� ����
    prior[v] = from;
    if (v == finish)   // ���������, ����� ��
    {
        cout << "Hooray! The path was found!\n";
        return;
    }
    for (int i = 0; i < graph[v].size(); ++i)  // ��� ������� �����
    {
        DFS(graph[v][i],mark,graph,prior,v);  // ����������� �� ������
    }
}
vector<int> get_path(vector<int> &prior)
{   int start=0;
    vector<int> ans;
    for (int v = finish; v != start; v = prior[v])  // �������� �� ���� �� ����� � ������
    {
        ans.push_back(v);  // ���������� �������
    }
    ans.push_back(start);
  //  reverse(ans.begin(), ans.end());  // �������������� ����
    return ans;
}

int main()
{  setlocale(LC_ALL,"RUSSIAN");
   int zn;// ������� ��������
   int arraySize = 0;
   cout<<"������� ���������� ������:"<<endl;
   cin>>arraySize;
   vector<vector<int> > graph(arraySize);
   for(int i=0;i<graph.size();i++)   // ��������� ������ �������
   {
         for(int j=0;j<graph.size();j++)
        {    cin>>zn;
             if(zn!=0) graph[i].push_back(j);;
        }
   }
  vector<bool> mark(arraySize);
  vector<int> path;
  vector<int>prior(arraySize);
  DFS(0,mark,graph,prior,0);
 path=get_path(prior);
   for(int i=0;i<path.size();i++)
   {
       cout<<path[i];
   }
   return(0);
}
