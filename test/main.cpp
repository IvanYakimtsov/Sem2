#include <iostream>

using namespace std;

double func(double a,int n){
return 1/2*(func(a,n--)+a/func(a,n--));
}

int main()
{
    int a,n;
    cin>>a>>n;
    cout<<func(a,n);
    return 0;
}
