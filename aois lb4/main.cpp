#include <iostream>
#include <conio.h>

using namespace std;

void init();

void minimi();

void change();

void table();

int main()
{
	setlocale(LC_ALL, "RUS");

	cout << "ОДC-3:" << endl;
	table();
	cout << endl;

	init();

	cout << endl << endl;

	minimi();

	cout << endl << endl;

	change();
	_getch();
}

void init()
{
	cout << "P=(x1+x2+x3)*(x1+x2+!x3)*(x1+!x2+x3)*(!x1+x2+x3)" << endl;
	cout << "S=(x1+x2+x3)*(x1+!x2+!x3)*(!x1+x2+!x3)*(!x1+!x2+x3)" << endl;
}

void minimi()
{
	cout << "         Минимизация функции P:" << endl;
	cout << "  |x1" << endl;
	cout << "  |____________________________" << endl;
	cout << "1 |   0  |      |      |      |" << endl;
	cout << "  |______|______|______|______|" << endl;
	cout << "0 |   0  |   0  |      |   0  |" << endl;
	cout << "  |______|______|______|______|_______" << endl;
	cout << "     00     01     11     10      x2x3" << endl << endl;

	cout << "P=(x1+x2)*(x1+x3)*(x2+x3)" << endl << endl;

	cout << "         Минимизация функции S:" << endl;
	cout << "  |x1" << endl;
	cout << "  |____________________________" << endl;
	cout << "1 |      |   0  |      |   0  |" << endl;
	cout << "  |______|______|______|______|" << endl;
	cout << "0 |   0  |      |   0  |      |" << endl;
	cout << "  |______|______|______|______|_______" << endl;
	cout << "     00     01     11     10      x2x3" << endl << endl;

	cout << "S=(x1+x2+x3)*(x1+!x2+!x3)*(!x1+x2+!x3)*(!x1+!x2+x3)" << endl;
}

void change()
{
	cout << "Выразим S через P: \n!P=!x1*!x2*!x3+!x1*!x2*x3+!x1*x2*!x3+x1*!x2*!x3\nP*=!x1*!x2*x3+!x1*x2*!x3+x1*!x2*!x3" << endl;
	cout << "S=(!P+x1*x2*x3)*(x1+x2+x3)" << endl;
}

void table()
{
	cout << "         Таблица истинности" << endl;
	cout << "_____________________________________" << endl;
	cout << "|x1 | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 1 |" << endl;
	cout << "|___|___|___|___|___|___|___|___|___|" << endl;
	cout << "|x2 | 0 | 0 | 1 | 1 | 0 | 0 | 1 | 1 |" << endl;
	cout << "|___|___|___|___|___|___|___|___|___|\n";
	cout << "|x3 | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 |\n";
	cout << "|___|___|___|___|___|___|___|___|___|\n";
	cout << "|S  | 0 | 1 | 1 | 0 | 1 | 0 | 0 | 1 |\n";
	cout << "|___|___|___|___|___|___|___|___|___|\n";
	cout << "|P  | 0 | 0 | 0 | 1 | 0 | 1 | 1 | 1 |\n";
	cout << "|___|___|___|___|___|___|___|___|___|";

}
