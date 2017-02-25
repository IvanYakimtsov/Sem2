#include <iostream>
#include <vector>
#include <iterator> // заголовочный файл итераторов
using namespace std;
void add(vector<vector<int> > & ed)
{
    for(int i=0; i<ed.size(); i++)
    {
        ed[i].push_back(i+1);
        ed[i].push_back(i+2);
        ed[i].push_back(i+3);

    }
}
int main()
{
    setlocale(LC_ALL,"RUSSIAN");
    int arraySize = 0;
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
   /* cout << "¬ведите размер массива: ";
    cin >> arraySize;*/
    vector<vector<int> > edges;
  // edges.reserve(3);
   edges.push_back(A);
  // edges[0].push_back(1);

    /*add(edges);
    for(int i=0; i<edges.size(); i++)
    {
        for(int j=0; j<edges[i].size(); j++)
        {
            cout<<edges[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return 0;
}
