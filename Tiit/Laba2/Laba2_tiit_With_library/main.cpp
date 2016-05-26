#include "EC.h"
int main()
{
    int prov;
    setlocale(LC_ALL,"Russian");
    system("CLS");
    cout<<"Количество вершин:  ";
    int n;
    cin>>n; // Количество вершин
    prov=Create_E_Cycle(n);
    // cin.get();
    //cin.get();
    if(prov==-1)cout<<"Граф не является эйлеровым.";
    cout<<endl;
    return(0);

}
