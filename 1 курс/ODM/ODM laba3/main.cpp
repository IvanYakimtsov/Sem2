#include <iostream>
#include <vector>
#include <list>

using namespace std;

void peresechenie( vector <vector<int> > A,vector <vector<int> > B,int a,int b)
{
    vector <vector<int> > C;  ///c������ ��������� �
    //------------------------------------------------------------------------------

    for(int i=0; i<a; i++)///���� i ������ � ���������� � i �������
    {
        for(int j=0; j<b; j++)///���� j ������ b ���������� � j �������
        {
            if(A[i]==B[j])///���� i-� ������� ��������� A � j-� ������� ��������� B �����
            {

                C.push_back(A[i]);///��������� i-� ������� � ��������� C
                break;
            }

        }

    }
    ///��������� �- ����������� �������� � � �.
    cout<<endl;
    cout<<"�����������: "<<endl;//������� �����������
    cout<<"{";
    for (int i = 0; i < C.size(); i++)
    {
        cout<<"<";
        cout<<C[i][0];
        cout<<",";
        cout<<C[i][1];
        cout<<">";
    }
    cout<<"}"; ///������� �� ����� ��������� �
    cout<<endl<<"----------------------------------------------"<<endl;
}

void Obedinenie( vector <vector<int> > A,vector <vector<int> > B,int a,int b)///�������� �����������
{
    vector <vector<int> > C1(B); ///������ ��������� �1 ������ ��������� �.
    for(int i=0; i<a; i++) ///���� i ������ � ���������� � i �������
    {
        for(int j=0; j<b; j++) ///���� j ������ b ���������� � b �������
        {
            if(A[i]==C1[j])
            {
                C1[j][0]=0; ///�������� j ������� ��������� �1 �� 0.
                break;
            }

        }

    }
    vector <vector<int> > C(A); ///C������ ��������� � ������ ��������� �.
    for(int i_b=0; i_b<b; i_b++) if(C1[i_b][0]!=0)
        {
            C.push_back(C1[i_b]);  ///�������� �������� ��������� C1 �� ������ ���� � ��������� �.
        }
    ///---------------------------------------------------------------



    cout<<"�����������:"<<endl; ///�-����������� ��������.
    cout<<"{";
    for (int i = 0; i < C.size(); i++)
    {
        cout<<"<";
        cout<<C[i][0];
        cout<<",";
        cout<<C[i][1];
        cout<<">";
    }
    cout<<"}"; ///������� �� ����� ��������� �
    cout<<endl<<"----------------------------------------------"<<endl;


}
void Raznost( vector <vector<int> > A,vector <vector<int> > B,int a,int b) ///�������� ��������
{
    vector <vector<int> > C2(A);   ///������ ��������� �2 ������ ��������� �.
    for(int j=0; j<b; j++) ///���� j<b ����������� j �� �������
    {
        for(int i=0; i<a; i++) ///���� i<b ����������� i �� �������
        {
            if(B[i]==C2[j]) ///���� i-�� ������� ��������� A ����� j-��� �������� ��������� �2
            {
                C2[j][0]=0; ///�������� j ������� ��������� �2 �� 0
                break;
            }

        }

    }
    cout<<"��������:"<<endl;
      cout<<"{";
    for (int i = 0; i < C2.size(); i++)
    {
        if(C2[i][0]!=0)
        {cout<<"<";
        cout<<C2[i][0];
        cout<<",";
        cout<<C2[i][1];
        cout<<">";}
    }
    cout<<"}"; ///������� �������� �� �����
    cout<<endl<<"----------------------------------------------"<<endl;

}
void sem_razn( vector <vector<int> > A,vector <vector<int> > B,int a,int b) ///�������� �������������� ��������
{
    vector <vector<int> > C6(A); ///������� ��������� �6 ������ ��������� �
    for(int i=0; i<b; i++)
    {
        for(int j=0; j<a; j++)
        {
            if(B[i]==C6[j]) ///���� i-�� ������� ��������� B ����� j-��� �������� ��������� �6
            {
                C6[j][0]=0; ///�������� j ������� �6 �� 0
                break;
            }

        }

    }
    vector <vector<int> > C7(B); ///������� ��������� �7 ������ ��������� �
    for(int i=0; i<b; i++) ///���� i ������ b ����������� i �� 1
    {
        for(int j=0; j<a; j++) ///���� j ������ a ����������� j �� 1
        {
            if(A[i]==C7[j]) ///���� i-�� ������� ��������� � ����� j-��� �������� ��������� �7
            {
                C7[j][0]=0; ///�������� j ������� ��������� �7 �� 0
                break;
            }

        }

    }

    cout<<"�������������� ��������:"<<endl; ///������� �������������� �������� �� �����
  cout<<"{";
    for (int i = 0; i < C6.size(); i++)
    {
        if(C6[i][0]!=0)
        {cout<<"<";
        cout<<C6[i][0];
        cout<<",";
        cout<<C6[i][1];
        cout<<">";}
    }
    for (int i = 0; i < C7.size(); i++)
    {
        if(C7[i][0]!=0)
        {cout<<"<";
        cout<<C7[i][0];
        cout<<",";
        cout<<C7[i][1];
        cout<<">";}
    }
    cout<<"}"; ///������� �������������� �������� �� �����
    cout<<endl<<"----------------------------------------------"<<endl;
}



void Composition( vector <vector<int> > A,vector <vector<int> > B,int a,int b) ///�������� ����������
{
  int tmp=a;
  if(b<a) tmp=b;
  vector <vector<int> > C9(A);///������� ��������� �8 ������ ��������� �
  for(int i=0;i<tmp;i++)
  {
      C9[i][1]=B[i][1]; ///�������� ������ ���������� i-�� ������� ������� �9 �� ������ ���������� i-�� ������� ������� �
  }
cout<<"���������� � � �:"<<endl;
   cout<<"{"; ///������� ���������� �� �����
    for (int i = 0; i < tmp; i++)
    {
        cout<<"<";
        cout<<C9[i][0];
        cout<<",";
        cout<<C9[i][1];
        cout<<">";
    }
    cout<<"}"; ///������� ���������� �� �����
    cout<<endl<<"----------------------------------------------"<<endl;
}


void inversion(vector <vector<int> > A) ///�������� ��������
{
  vector <vector<int> > C8(A); ///������� ��������� �8 ������ ��������� �
  for(int i=0;i<C8.size();i++)
  {
      swap(C8[i][0],C8[i][1]);
  }
  cout<<"�������� ������� �:"<<endl;
   cout<<"{"; ///������� �������� �� �����
    for (int i = 0; i < C8.size(); i++)
    {
        cout<<"<";
        cout<<C8[i][0];
        cout<<",";
        cout<<C8[i][1];
        cout<<">";
    }
    cout<<"}"; ///������� �������� �� �����
    cout<<endl<<"----------------------------------------------"<<endl;

}


int main()
{
    bool kol=true;
    setlocale(LC_ALL,"Russian");
    cout<<"������ �������� ��������� �: " ;
    int a;                                  ///������������ ������ �������� ��������� A (a)
    cin>>a;
    vector <vector<int> > A(a);
    cout<<"������ �������� ��������� �: ";
    int b;
    cin>>b;                                ///������������ ������ �������� ���������B (b)
    vector <vector<int> > B(b);
   int tmp1=0,tmp2=0;
    cout<<"������� ������� ��������� �: ";
    cout<<endl;
    for (int i = 0; i < a; i++)
    {
        cout<<i+1<<" "<<"������:";
        cout<<endl;
        tmp1=0;
        tmp2=0;
        cin>>tmp1;
        A[i].push_back(tmp1);
        cin>>tmp2;
        A[i].push_back(tmp2);
    }
    cout<<endl;
    cout<<"������� ������� ��������� B: ";
    cout<<endl;
    for (int i = 0; i < b; i++)
    {
        cout<<i+1<<" "<<"������:";
        cout<<endl;
        tmp1=0;
        tmp2=0;
        cin>>tmp1;
        B[i].push_back(tmp1);
        cin>>tmp2;
        B[i].push_back(tmp2);
    }
    cout<<"��������� �: ";
    cout<<"{";
    for (int i = 0; i < a; i++)
    {
        cout<<"<";
        cout<<A[i][0];
        cout<<",";
        cout<<A[i][1];
        cout<<">";
    }
    cout<<"}";
    cout<<endl;
    cout<<"��������� B: ";
    cout<<"{";
    for (int i = 0; i < b; i++)
    {
        cout<<"<";
        cout<<B[i][0];
        cout<<",";
        cout<<B[i][1];
        cout<<">";
    }
    cout<<"}";
    cout<<endl;
    ///---------------------------------------------------------------------------------------------------------

     int in;
    ///������������ �������� �������� ��� �����������-------------------------------------------------------------
        while(kol)
        {

            cout << "1.�������� ����������� ��." << endl;
            cout << "2.�������� ����������� ��." << endl;
            cout << "3.�������� �������� ��." << endl;
            cout << "4.�������� �������� �." << endl;
            cout << "5.�������� ���������� ��." <<endl;
            cout << "6.�������� �������������� ��������." << endl;
            cout << "7.��������� ���������." << endl;
            cin >> in;
            switch (in)
            {
            case 1:
        {
            peresechenie(A,B,a,b);    ///�����������
            break;
        }
            case 2:
        {
            Obedinenie(A,B,a,b);    ///�����������
            break;
        }
            case 3:
        {
            Raznost(A,B,a,b);    ///��������
            break;
        }
            case 4:
        {
            inversion(A);    ///��������
            break;
        }
            case 5:
        {
            Composition(A,B,a,b);    ///����������
            break;
        }
            case 6:
        {
            sem_razn(A,B,a,b);    ///�������������� ��������
            break;
        }
            case 7:
        {
            kol=false;    ///���������� ������
            break;
        }
            default:
        {
            cout<<"Error!! ";    ///������ ��� �����
            break;
        }
            }

        }
    ///---------------------------------------------------------------------------------------------------------




    return 0;
}
