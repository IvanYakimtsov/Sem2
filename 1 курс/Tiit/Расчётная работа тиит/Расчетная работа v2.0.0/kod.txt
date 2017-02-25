#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
struct Vertex
{
    short int color,previousVertex,number,cycle,color1;
};



void sort_cicle(Vertex *Graph,int n)
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) if(Graph[j].cycle<Graph[i].cycle)
            {
                swap(Graph[i],Graph[j]);
            }

}
void sort_number(Vertex *Graph,int n)
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) if(Graph[j].number>Graph[i].number)
            {
                swap(Graph[i],Graph[j]);
            }

}




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



void removing_vertex(Vertex *Graph, int delited_vertex,bool **Matrix,int *n,bool **Matrix_Copy,int *position)
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
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
            {
                Matrix[i][j]=Matrix_Copy[i][j];
            }

        *n=*n-1;
    }
    else
    {
        *position=*position+1;
        removing_vertex (Graph,Graph[*position].number,Matrix,n,Matrix_Copy,position);
    }


}

void Graph_to_Tree(bool **Matrix,Vertex *Graph,int *n,int i,bool **Matrix_Copy,int N)
{

    bool check_cicle=true;
    int position=0;
    while(check_cicle)
    {
        position=0;
        sort_number(Graph,N);
        for(int i=0; i<*n; i++) Graph[i].color=1;
        for(int i=0; i<*n; i++) Graph[i].previousVertex=0;
        for(int i=0; i<*n; i++) Graph[i].cycle=0;
        cycle(Matrix,Graph,*n,0);
        check_cicle=false;
        for(int i=0; i<*n; i++)
        {
            if(Graph[i].cycle!=0)
            {
                check_cicle=true;
                break;
            }
        }
        sort_cicle(Graph,*n);
        if(check_cicle)
        {
            for(int i=0; i<*n; i++) Graph[i].color=1;
            removing_vertex (Graph,Graph[position].number,Matrix,n,Matrix_Copy,&position);
        }
    }


}

int main()
{
int test=0;
   FILE* fi;
    //cin.getline(name, 40);
    while(test<5)
   {
    switch(test)
    {
        case 0:{fi = fopen("1.txt","r");cout<<endl<<"test1"<<endl;break;}
        case 1:{fi = fopen("2.txt","r");cout<<endl<<"test2"<<endl;break;}
        case 2:{fi = fopen("3.txt","r");cout<<endl<<"test3"<<endl;break;}
        case 3:{fi = fopen("4.txt","r");cout<<endl<<"test4"<<endl;break;}
        case 4:{fi = fopen("5.txt","r");cout<<endl<<"test5"<<endl;break;}
    }
    setlocale(LC_ALL,"Russian");
    int N=0;
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
    Graph_to_Tree(Matrix,Graph,&N,0,Matrix_Copy,N);
    cout<<"Матрица после удаления точек:"<<endl;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<Matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;






    for(int i=0; i<N; i++)  delete []Matrix[i];			// Освобождение памяти
    delete []Matrix;
    delete []Graph;
    test++;
   }
    return 0;
    return 0;
}
