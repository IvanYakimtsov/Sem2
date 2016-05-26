#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
struct Vertex
{
    short int color,previousVertex,number,cycle,color1;
};
vector<int> p_o_c;
void DFS(bool **Matrix,Vertex *Graph,int n,int i)
{
    Graph[i].color1=2;
    for(int j=0; j<n; j++)
    {
        if(Matrix[i][j] && j!=Graph[i].previousVertex && Graph[j].color1==1)
        {
            Graph[j].previousVertex=Graph[i].number;
            DFS(Matrix,Graph,n,j);
        }
    }
    Graph[i].color1=3;
}

//----------------------------------------------------------------------------------------------------------------------------
Print_cycle(Vertex *Graph,int i,int j,bool **Matrix)
{
    Graph[i].cycle++;
    i=Graph[i].previousVertex;
    while(i!=j)
    {

        if(Matrix[i][j])
        {
            Graph[i].cycle++;
            i=j;
        }
        else
        {
            Graph[i].cycle++;
            i=Graph[i].previousVertex;
        }
    }
}

void cycle(bool **Matrix,Vertex *Graph,int n,int i)
{
    Graph[i].color=2;
    for(int j=0; j<n; j++)
    {
        if(Matrix[i][j] && j!=Graph[i].previousVertex && Graph[j].color==1)
        {
            Graph[j].previousVertex=Graph[i].number;
            cycle(Matrix,Graph,n,j);
        }
        if(Matrix[i][j] && j!=Graph[i].previousVertex && Graph[j].color==2)
        {
            Graph[j].cycle++;
            Print_cycle(Graph,i,j,Matrix);
        }
    }
    Graph[i].color=3;
}

//----------------------------------------------------------------------------------------------------------------------------


bool check_connection(bool **Matrix,Vertex *Graph,int n,int i)
{
    bool check=true;
    for(int i=0; i<n; i++) Graph[i].color1=1;
    DFS(Matrix,Graph,n,i);
    for(int i=0; i<n; i++)
    {
        if(Graph[i].color1==1)
        {
            check=false;
            break;
        }
    }
    for(int i=0; i<n; i++) Graph[i].color1=1;
    if(check) return 1;
    else return 0;
}


int find_vertex(Vertex *Graph, int i, int j, bool **Matrix,int dont_del_i)
{
    bool check;
    int max=0,del_i;
    max=0;
    if(Graph[j].cycle>max && j!=dont_del_i)
    {
        for(int temp=0;temp<p_o_c.size();temp++)
        {if(j==p_o_c.at(temp)){check=false;break;}
        else check=true;}
        if(check)
        {max=Graph[j].cycle;
        del_i=Graph[j].number;}
    }
    if(Graph[i].cycle>max && i!=dont_del_i)
    {
        for(int temp=0;temp<p_o_c.size();temp++)
        {if(i==p_o_c.at(temp)){check=false;break;}
        else check=true;}
        if(check)
        {max=Graph[i].cycle;
        del_i=Graph[i].number;}
    }
    // cout<<"перва€ проверка поиска точек "<<del_i<<" "<<endl;
    i=Graph[i].previousVertex;
    while(i!=j)
    {

        if(Matrix[i][j])
        {
            if(Graph[i].cycle>max && i!=dont_del_i)
            {
                for(int temp=0;temp<p_o_c.size();temp++)
                {
                    if(i==p_o_c.at(temp)) {check=false;break;}
                    else check=true;
                }
                if(check)
                {max=Graph[i].cycle;
                del_i=Graph[i].number;}
            }
            i=j;
        }
        else
        {
            if(Graph[i].cycle>max && i!=dont_del_i)
            {
                for(int temp=0;temp<p_o_c.size();temp++)
                {
                    if(i==p_o_c.at(temp)){check=false;break;}
                    else check=true;
                }
                if(check)
                {max=Graph[i].cycle;
                del_i=Graph[i].number;}
            }
            i=Graph[i].previousVertex;
        }
    }

    //cout<<endl<<"втора€ проверка поиска точек "<<del_i<<" "<<endl;
    return del_i;

}



void removing_vertex(Vertex *Graph, int delited_vertex,bool **Matrix,int *n,bool **Matrix_Copy,int i,int j)
{
    int N=*n;
    int N1=*n;
    int i_temp=delited_vertex;
    int j_temp=delited_vertex;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            Matrix_Copy[i][j]=Matrix[i][j];
        }


    for(int j=0; j<N; j++)
    {
        while(i_temp<N-1)
        {
            swap(Matrix_Copy[i_temp][j],Matrix_Copy[i_temp+1][j]);
            i_temp++;
        }

        i_temp=delited_vertex;
    }
    for(int i=0; i<N; i++)
    {
        while(j_temp<N-1)
        {
            swap(Matrix_Copy[i][j_temp],Matrix_Copy[i][j_temp+1]);
            j_temp++;
        }

        j_temp=delited_vertex;
    }
    N1=N1-1;
    if(check_connection(Matrix_Copy,Graph,N1,0))
    {
         //cout<<endl<<"подтвержденно удаление точки "<<delited_vertex<<endl;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
            {
                Matrix[i][j]=Matrix_Copy[i][j];
            }

        *n=*n-1;
        //cout<<delited_vertex<<endl;
    }
    else
    {
        //cout<<endl<<"сработал поиск новой вершины"<<endl;
        p_o_c.push_back(delited_vertex);
        removing_vertex (Graph, find_vertex (Graph,i,j,Matrix,delited_vertex),Matrix,n,Matrix_Copy,i,j);
        //cout<<endl<<find_vertex (Graph,i,j,Matrix,delited_vertex)<<"+"<<endl;
    }


}

void removing_cycle(bool **Matrix,Vertex *Graph,int *n,int i,bool **Matrix_Copy)
{

    Graph[i].color=2;
    for(int j=0; j<*n; j++)
    {
        if(Matrix[i][j] && j!=Graph[i].previousVertex && Graph[j].color==1)
        {
            Graph[j].previousVertex=Graph[i].number;
            removing_cycle(Matrix,Graph,n,j,Matrix_Copy);
        }
        if(Matrix[i][j] && j!=Graph[i].previousVertex && Graph[j].color==2)
        {
            // cout<<endl<<"сработало удаление цикла"<<endl;
            removing_vertex (Graph,find_vertex (Graph,i,j,Matrix,-1),Matrix,n,Matrix_Copy,i,j);
            break;

        }
    }
    Graph[i].color=3;
}

void Graph_to_Tree(bool **Matrix,Vertex *Graph,int *n,int i,bool **Matrix_Copy)
{
    bool check_cicle=true;
    // while(check_cicle(Matrix,Graph,*n,i))
    while(check_cicle)
    {
        for(int i=0; i<*n; i++) Graph[i].color=1;
        for(int i=0; i<*n; i++) Graph[i].previousVertex=0;
        for(int i=0; i<*n; i++) Graph[i].cycle=0;
        cycle(Matrix,Graph,*n,0);
      //  for(int i=0; i<*n; i++) cout<<Graph[i].cycle<<" ";
      //  cout<<endl;
        // cout<<endl;
        check_cicle=false;
        for(int i=0; i<*n; i++)
        {
            if(Graph[i].cycle!=0)
            {
                check_cicle=true;
                break;
            }
        }
        if(check_cicle)
        {
            for(int i=0; i<*n; i++) Graph[i].color=1;
            removing_cycle(Matrix,Graph,n,0,Matrix_Copy);
        }
    }


}

int main()
{
    p_o_c.push_back(-1);
    FILE* fi = fopen("4.txt","r"); //‘айл с матрицей смежности
    setlocale(LC_ALL,"Russian");
    int N=0;
    /*cout<<"¬ведите количество вершин: ";
    cin>>N;*/
    fscanf(fi,"%d",&N);
    Vertex *Graph;
    Graph = new Vertex[N];
    bool **Matrix;
    Matrix = new bool *[N];
    for(int i=0; i<N; i++) 	Matrix[i] = new bool [N];
    bool **Matrix_Copy;
    Matrix_Copy = new bool *[N];
    for(int i=0; i<N; i++) 	Matrix_Copy[i] = new bool [N];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            Matrix_Copy[i][j]=0;
        }
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            //cin>>Matrix[i][j];
            fscanf(fi,"%d",&Matrix[i][j]);
        }



    for(int i=0; i<N; i++) Graph[i].color=1;
    for(int i=0; i<N; i++) Graph[i].number=i;
    for(int i=0; i<N; i++) Graph[i].previousVertex=0;
    for(int i=0; i<N; i++) Graph[i].cycle=0;
    cycle(Matrix,Graph,N,0);
    for(int i=0; i<N; i++) Graph[i].color=1;
    // cout<<"”даленные точки: "<<endl;
    // removing_cycle(Matrix,Graph,&N,0,Matrix_Copy);
    Graph_to_Tree(Matrix,Graph,&N,0,Matrix_Copy);
    cout<<"ћатрица после удалени€ точек:"<<endl;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<Matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    for(int i=0; i<p_o_c.size(); i++) cout<<p_o_c.at(i)<<" ";





    for(int i=0; i<N; i++)  delete []Matrix[i];			// ќсвобождение пам€ти
    delete []Matrix;
    delete []Graph;


    return 0;
}
