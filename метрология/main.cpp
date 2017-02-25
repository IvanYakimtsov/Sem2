#include <iostream>
#include <vector>
#include <string>
#include<cstdlib>


using namespace std;

int main()
{
    vector<vector <int> > Matrix;
    Matrix.resize(7);
    cout<<"Matrix: "<<endl;
    for(int i=0;i<7;i++)
   {
    for(int j=0;j<8;j++) {
                            int buf=rand()%100 +1;
                            Matrix[i].push_back(buf);
                            cout<<Matrix[i][j]<<" ";
                         }
                          cout<<endl;
   }
  vector<vector <int> > Min_El;
  Min_El.resize(8);
  int min_el;
  int x,y;
  for(int j=0;j<8;j++)
    {  min_el=Matrix[0][j];
        x=0;
        y=j;
        for(int i=0;i<7;i++) {
                            if(Matrix[i][j]<min_el)
                                {
                                min_el=Matrix[i][j];
                                x=i;
                                y=j;
                                }
                            }
     Min_El[j].push_back(min_el);
     Min_El[j].push_back(x);
     Min_El[j].push_back(y);
    }
    int min_matrix_el=Min_El[0][0];
    int min_matrix_x=Min_El[0][1];
    int min_matrix_y=Min_El[0][2];
    for(int i=0;i<Min_El.size();i++)
    {
        if(Min_El[i][0]<min_matrix_el)
        {
         min_matrix_el = Min_El[i][0];
         min_matrix_x = Min_El[i][1];
         min_matrix_y = Min_El[i][2];
        }
    }
    cout<<"Matrix: "<<endl;
     cout<<"Minim column elements: "<<endl;
    for(int i=0;i<Min_El.size();i++)
    {
        cout<<"column "<<i+1<<":";
        cout<<"element: "<<Min_El[i][0]<<" ";
        cout<<"i: "<<Min_El[i][1]+1<<" ";
        cout<<"j: "<<Min_El[i][2]+1;
        cout<<endl;
    }
    cout<<endl;
    cout<<"Min element: "<<min_matrix_el<<endl;
    cout<<"Min element i: "<<min_matrix_x+1<<endl;
    cout<<"Min element j: "<<min_matrix_y+1<<endl;
    return 0;
}
