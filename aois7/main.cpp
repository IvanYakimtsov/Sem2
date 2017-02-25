#include <iostream>
#include <bitset>
#include <vector>
#include <random>
#include <algorithm>
#include <sstream>
#include <windows.h>
#include <conio.h>
using namespace std;
const int m = 8;
const int n = 8;

bool compare(vector<bool> a, vector<bool> s);
int convertBinaryToDecimal(long long n)
{
	int decimalNumber = 0, i = 0, remainder;
	while (n != 0)
	{
		remainder = n % 10;
		n /= 10;
		decimalNumber += remainder*pow(2, i);
		++i;
	}
	return decimalNumber;
}
int convert(vector<bool> a)
{
	stringstream ss;

	for (unsigned i = 0; i<n; ++i)
		ss << a[i];

	int result;
	ss >> result;
	result = convertBinaryToDecimal(result);
	return result;
}
void print_vocab(vector< vector<bool> > v)
{
	for (int i = 0; i<m; i++)
	{
		std::cout << i + 1 << "| ";
		for (int j = 0; j<n; j++)
			std::cout << v[i][j] << " ";
		std::cout << "| " << convert(v[i]);
		std::cout << endl;
	}
}

vector< vector<bool> > sort(vector< vector<bool> > v)
{
	for (int i = 0; i < m - 1; i++) {
		bool swapped = false;
		for (int j = 0; j < m - i - 1; j++)
			if (compare(v[j], v[j + 1]))
			{
				swap(v[j], v[j + 1]);
				swapped = true;
			}
		if (!swapped)
			break;
	}
	return v;
}
vector< vector<bool> > sort_from_max(vector< vector<bool> > v)
{
	for (int i = 0; i < m - 1; i++)
	{
		bool swapped = false;
		for (int j = 0; j < m - i - 1; j++)
			if (!compare(v[j], v[j + 1]))
			{
				swap(v[j], v[j + 1]);
				swapped = true;
			}
		if (!swapped)
			break;
	}
	return v;
}
bool FunctionG(bool ai, bool si, bool li, bool gi){
	return (gi || (!ai && si && !li));
}
bool FunctionL(bool ai, bool si, bool li, bool gi){
	return (li || (ai && !si && !gi));
}
bool compare(vector<bool> a, vector<bool> s) {
	bool g = 0, l = 0;
	vector <bool> g_vect;
	vector <bool> l_vect;
	for (int i = 0; i < 79; i++)
		std::cout << "-";
	std::cout << endl;
	std::cout << " A: ";
	for (vector<bool>::iterator it = a.begin(); it != a.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "Sj: ";
	for (vector<bool>::iterator it = s.begin(); it != s.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	for (int i = 0; i<n; i++)
	{
		g = FunctionG(a[i], s[i], l, g);
		g_vect.push_back(g);
		l = FunctionL(a[i], s[i], l, g);
		l_vect.push_back(l);
		if (g == 0 && l == 1)
		{
			std::cout << " g: ";
			for (vector<bool>::iterator it = g_vect.begin(); it != g_vect.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << '\n';

			std::cout << " l: ";
			for (vector<bool>::iterator it = l_vect.begin(); it != l_vect.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << '\n';
			return true; //A>S
		}
		if (g == 1 && l == 0)
		{
			std::cout << " g: ";
			for (vector<bool>::iterator it = g_vect.begin(); it != g_vect.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << '\n';

			std::cout << " l: ";
			for (vector<bool>::iterator it = l_vect.begin(); it != l_vect.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << '\n';
			return false; //A<S
		}
	}
	if (g == 0 && l == 0)
	{
		std::cout << " g: ";
		for (vector<bool>::iterator it = g_vect.begin(); it != g_vect.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << " l: ";
		for (vector<bool>::iterator it = l_vect.begin(); it != l_vect.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	return false;
}

vector< vector<bool> > init_vocab(){
	vector< vector<bool> > vocab(m, vector<bool>(n));
	for (int i = 0; i<m; i++)
		for (int j = 0; j<n; j++)
			vocab[i][j] = rand() % 2;
	return vocab;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	vector< vector<bool> > vocab = init_vocab();
	vector< vector<bool> > start_vocab = vocab;
	char kod;
	while (true)
	{
		for (int i = 0; i < 79; i++)
			std::cout << "=";
		std::cout << endl;
		std::cout << " 1. Просмотр\n";
		std::cout << " 2. Сортировка (по возрастанию)\n";
		std::cout << " 3. Сортировка (по убыванию)\n";
		std::cout << " 4. Перезаписать\n";;
		std::cout << " 0. Выход\n";
		for (int i = 0; i < 79; i++)
			std::cout << "=";
		std::cout << endl;
		kod = _getch();
		switch (kod)
		{
		case '1':
			print_vocab(start_vocab);
			break;
		case '2':
			vocab = sort(vocab);

			for (int i = 0; i < 79; i++)
				std::cout << "=";
			std::cout << endl;
			std::cout << "Отсортированный словарь:\n";
			print_vocab(vocab);
			break;
		case '3':
			vocab = sort_from_max(vocab);
			for (int i = 0; i < 79; i++)
				std::cout << "=";
			std::cout << endl;
			std::cout << "Отсортированный словарь:\n";
			print_vocab(vocab);
			break;
		case '4':
			start_vocab = init_vocab();
			vocab = start_vocab;
			std::cout << " Словарь перезаписан.\n";
			break;
		case '0':
			return 0;
			break;
		}
	};
	return 0;
}
