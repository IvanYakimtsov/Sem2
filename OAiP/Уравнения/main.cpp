#include <iostream>
#include<cmath>
#include<stdio.h>

using namespace std;
double f(double x) //���������� �������� ������� f(x) = x^2-2
{
    return log(x)-5*sin(x)*sin(x);
}
double df(float x) //���������� �������� �����������
{
    return 1/x-10*sin(x)*cos(x);
}
double d2f(float x) // �������� ������ �����������
{
    return 10*pow(sin(x),2)-10*pow(cos(x),2)-pow(x,-2);
}

int main()
{
    int exit = 0, i=0;//���������� ��� ������ � �����
    double x0,xn;// ����������� ����������� ��� �����
    double a, b, eps;// ������� ������� � ����������� ��������

        i=0;
        cout<<"Please input [a;b]\n=>";
        cin>>a>>b; // ������ ������� �������, �� ������� ����� ������ ������
        cout<<"\nPlease input epsilon\n=>";
        cin>>eps; // ������ ������ �������� ����������
        if (a > b) // ���� ������������ ��������� ������� �������, ������ �� �������
        {
            x0 = a;
            a = b;
            b = x0;
        }
        for(a;a<=b;a=a+0.1)
       {
   if (f(a)*f(a+0.1)<0) // ���� ����� ������� �� ����� ������� ����������, �� ����� ��� �����

        {
            x0  = a; // ��� ������ ��������� ����� ��������� f(x0)*d2f(x0)>0 ?

            xn = x0-f(x0)/df(x0); // ������� ������ �����������
            while(fabs(x0-xn) > eps) // ���� �� ��������� ����������� ��������, ����� ���������� ���������
            {
                x0 = xn;
                xn = x0-f(x0)/df(x0); // ��������������� ������� �������

            }
            cout<<"\nRoot = "<<xn; // ����� ������������ �����
            cout<<"Prov "<<f(xn);
        }
       }

    return 0;
}
