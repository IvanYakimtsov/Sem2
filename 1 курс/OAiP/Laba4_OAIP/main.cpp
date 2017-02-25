// Akkerman.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>
#include <conio.h>
#include <fstream>
#include <iostream>

using namespace std;


int Ak(int m, int n)
{
    int a;
    if(m == 0)
        a = n + 1;
    else if(m > 0 && n == 0)
        a = Ak(m - 1, 1);
    else
        a = Ak(m - 1, Ak(m, n - 1));
    return a;

}
int main()
{
    setlocale(LC_ALL, "Russian");
    int n, m, y, nom;
    cout << "¬ведите m и n:" << '\n' ;
    cin >> m >> n;
    y = Ak(m, n);
    cout << "A(" << m << "," << n << ")=" << y << endl;

    return 0;
}

