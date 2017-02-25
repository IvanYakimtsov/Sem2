#include <iostream>
#include<cmath>
#include<stdio.h>

using namespace std;
double f(double x) //возвращает значение функции f(x) = x^2-2
{
    return log(x)-5*sin(x)*sin(x);
}
double df(float x) //возвращает значение производной
{
    return 1/x-10*sin(x)*cos(x);
}
double d2f(float x) // значение второй производной
{
    return 10*pow(sin(x),2)-10*pow(cos(x),2)-pow(x,-2);
}

int main()
{
    int exit = 0, i=0;//переменные для выхода и цикла
    double x0,xn;// вычисляемые приближения для корня
    double a, b, eps;// границы отрезка и необходимая точность

        i=0;
        cout<<"Please input [a;b]\n=>";
        cin>>a>>b; // вводим границы отрезка, на котором будем искать корень
        cout<<"\nPlease input epsilon\n=>";
        cin>>eps; // вводим нужную точность вычислений
        if (a > b) // если пользователь перепутал границы отрезка, меняем их местами
        {
            x0 = a;
            a = b;
            b = x0;
        }
        for(a;a<=b;a=a+0.1)
       {
   if (f(a)*f(a+0.1)<0) // если знаки функции на краях отрезка одинаковые, то здесь нет корня

        {
            x0  = a; // для выбора начальной точки проверяем f(x0)*d2f(x0)>0 ?

            xn = x0-f(x0)/df(x0); // считаем первое приближение
            while(fabs(x0-xn) > eps) // пока не достигнем необходимой точности, будет продолжать вычислять
            {
                x0 = xn;
                xn = x0-f(x0)/df(x0); // непосредственно формула Ньютона

            }
            cout<<"\nRoot = "<<xn; // вывод вычисленного корня
            cout<<"Prov "<<f(xn);
        }
       }

    return 0;
}
