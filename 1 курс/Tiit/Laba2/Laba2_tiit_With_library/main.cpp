#include "EC.h"
int main()
{
    int prov;
    setlocale(LC_ALL,"Russian");
    system("CLS");
    cout<<"���������� ������:  ";
    int n;
    cin>>n; // ���������� ������
    prov=Create_E_Cycle(n);
    // cin.get();
    //cin.get();
    if(prov==-1)cout<<"���� �� �������� ���������.";
    cout<<endl;
    return(0);

}
