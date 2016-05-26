#include <iostream>
#include<vector>

using namespace std;

struct Set_of_sets
{
    char Set_tmp[300];
    vector< vector<char> > Set;
    int set_power=0;
    int size_Set_tmp=0;
};


int main()
{  setlocale(LC_ALL,"Russian");
    int j=1;
    char c;
    int check_Set=0;
    bool check=true;
    cout<<"Введите количество множеств: ";
    int N;
    cin>>N;
    Set_of_sets *A;
    A=new Set_of_sets[N];
 /*   while(i<N)
    {
        cout<<"Введите множество "<<i+1<<":
    cin>>A[0].Set_tmp;
    }*/
    for ( int i=0; i<N; i++)
    {
        cout<<"Введите множество "<<i+1<<": ";
        cin>>A[i].Set_tmp;
    }




   for ( int e=0; e<N; e++)
   {
    check_Set=0;
   for(int i=0; i<300; i++)
    {
        A[e].size_Set_tmp++;
        if(A[e].Set_tmp[i]=='{') check_Set++;
        if(A[e].Set_tmp[i]=='}' && check_Set!=0) check_Set--;
        if(A[e].Set_tmp[i]=='<') check_Set++;
        if(A[e].Set_tmp[i]=='>' ) check_Set--;
        if(A[e].Set_tmp[i]=='}' && check_Set==0) break;
    }
    check_Set=0;
    for(int i=1; i<A[e].size_Set_tmp-1; i++)
    {
        if(A[e].Set_tmp[i]=='{') check_Set++;
        if(A[e].Set_tmp[i]=='}') check_Set--;
        if(A[e].Set_tmp[i]=='<') check_Set++;
        if(A[e].Set_tmp[i]=='>' ) check_Set--;
        if(A[e].Set_tmp[i]!=',')
        {
            if(check_Set==0) A[e].set_power++;
        }
    }
    check_Set=0;


    cout<<A[0].set_power;
   // A[e].Set.reserve(A[e].set_power);
    A[e].Set.reserve(3);
    cout<<endl<<endl;
    cout<<A[e].Set.size();
    j=1;
    check_Set=0;
    check=true;
    for(int i=0; i<A[e].set_power; i++)
    {
        check=true;
        while(check && j!=A[e].size_Set_tmp-1)
        {
            if(A[e].Set_tmp[j]=='{') check_Set++;
            if(A[e].Set_tmp[j]=='<') check_Set++;
            if(A[e].Set_tmp[j]=='}') check_Set--;
            if(A[e].Set_tmp[j]=='>' ) check_Set--;
            c=A[e].Set_tmp[j];
            A[e].Set[i].push_back(c);
            if(A[e].Set_tmp[j]!=',')
            {
                if(check_Set==0) check=false;
            }
            j++;
        }
        j++;

    }
}

cout<<endl<<endl;
cout<<A[0].Set.size();
cout<<endl<<endl;
cout<<A[0].Set[0].size();


    return 0;
}
