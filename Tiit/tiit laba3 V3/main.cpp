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
struct Vec_temp
{
    vector< vector<char> > Set_C;
};



int main()
{
    setlocale(LC_ALL,"Russian");
    vector<char> temp;
    int j=1;
    char c;
    int check_Set=0;
    bool check=true;
    cout<<"¬ведите количество множеств: ";
    int N;
    cin>>N;
    Set_of_sets *A;
    A=new Set_of_sets[N];
    /*   while(i<N)
       {
           cout<<"¬ведите множество "<<i+1<<":
       cin>>A[0].Set_tmp;
       }*/
    for ( int i=0; i<N; i++)
    {
        cout<<"¬ведите множество "<<i+1<<": ";
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



        //  A[e].Set.reserve(A[e].set_power);
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
                // c=A[e].Set_tmp[j];
                temp.push_back(A[e].Set_tmp[j]);
                if(A[e].Set_tmp[j]!=',')
                {
                    if(check_Set==0)
                    {
                        check=false;
                        A[e].Set.push_back(temp);
                        temp.clear();
                    }
                }
                j++;
            }
            j++;

        }
    }


///----------------------------------------------------------------------------------
    int box=0;
    Vec_temp *B;
    B=new Vec_temp[N];

    for(int i=0; i<N; i++)
    {
        B[i].Set_C=A[i].Set;
    }



    for(int e=0; e<N; e++)
    {
        check_Set=0;
        for(int i=0; i<B[e].Set_C.size(); i++)
            for(int j1=0; j1<B[e].Set_C[i].size(); j1++)
            {
                if(B[e].Set_C[i][j1]=='{') check_Set++;
                if(B[e].Set_C[i][j1]=='}') check_Set--;
                if(B[e].Set_C[i][j1]=='<') check_Set++;
                if(B[e].Set_C[i][j1]=='>' ) check_Set--;
                if(B[e].Set_C[i][j1]!='{' && B[e].Set_C[i][j1]!='}' && B[e].Set_C[i][j1]!='<' && B[e].Set_C[i][j1]!='>' && B[e].Set_C[i][j1]!=',')
                {
                    box=B[e].Set_C[i][j1];
                    box=box+check_Set;
                    B[e].Set_C[i][j1]=box;
                }

            }

    }


//int l=0,r=0;


    for(int e=0; e<N; e++)
    {
        for(int i=0; i<B[e].Set_C.size(); i++)
        {
            temp.clear();
            for(int g=0; g<B[e].Set_C[i].size(); g++)
            {
                if(B[e].Set_C[i][g]=='<')
                {
                    g++;
                    while(B[e].Set_C[i][g]!='>')
                    {
                      /*  if(B[e].Set_C[i][g]!='{')
                        {l=g;
                         r=g;
                            while(B[e].Set_C[i][r]!='}')
                            {

                            }
                        }*/
                        temp.push_back(B[e].Set_C[i][g]);
                        g++;
                    }
                }
            }
            for(int j1=0; j1<B[e].Set_C[i].size(); j1++)
            {
                for(int j2=0; j2<B[e].Set_C[i].size(); j2++)
                {
                    if(B[e].Set_C[i][j1]<B[e].Set_C[i][j2])
                    {
                        swap(B[e].Set_C[i][j1],B[e].Set_C[i][j2]);
                    }
                }
            }
            for(int k=0; k<temp.size(); k++) B[e].Set_C[i].push_back(temp[k]);
        }
    }




///----------------------------------------------------------------------------------



    int e=1;
    bool check_per=true;
    vector<int> Peresechenie;
    for(int i=0; i<A[0].set_power; i++)
    {
        e=1;

        while(e<N)
        {
            check_per=false;
            for(int j1=0; j1<A[e].set_power; j1++)
            {
                if(B[0].Set_C[i]==B[e].Set_C[j1])
                {
                    check_per=true;
                    break;
                }
            }
            if(!check_per) break;
            e++;
        }
        if(check_per) Peresechenie.push_back(i);
    }

    cout<<endl;





    cout<<"{";
    for(int i=0; i<Peresechenie.size(); i++)
    {
        for(int j1=0; j1<A[0].Set[Peresechenie[i]].size(); j1++) cout<<A[0].Set[Peresechenie[i]][j1];
        if(i!=Peresechenie.size()-1) cout<<",";
    }
    cout<<"}";



    return 0;
}
