#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
enum mode{ plus, product };
string elements[6] = { "x1", "!x1", "x2", "!x2", "x3", "!x3" };
bool find_element(string a, string b, string c){
	int tmp1, tmp2;
	if ((tmp1 = a.find(b)) == -1||(tmp2=a.find(c))==-1)
		return false;
	if ((tmp1 = a.find(c)) == -1)
		return false;
	a[tmp1 + 1] = 'y';
	if ((tmp2 = a.find(b)) == -1)
		return false;
	return true;
}
bool find_el(string a, string b){
	int tmp;
	if ((tmp = a.find(b)) == -1)
		return false;
	if (tmp >= 1 && a[tmp - 1] == '!')
		return false;
	return true;
}
int kon(int a, int b){
	return a&b;
}
int dez(int a, int b){
	return a | b;
}
int main(){
	setlocale(LC_ALL, "RUSSIAN");
	///ifstream fin("input.txt");
	bool check(string, string);
	string find_1(string, string, mode&, int&);
	string exp;
	string sfirst, ssecond;
	int first, second;
	mode f, g;
	cin >> exp;
	cout << "Fi(x1,x2,x3)=" << exp << '=';
	sfirst = find_1(exp, "+", f, first);
	ssecond = find_1(exp, "*", g, second);
	cout << sfirst << '+' << ssecond << '=';
	if (sfirst.find('(') != -1)
	{
		string temp;
		int first1, second1, tmp;
		for (int i = 0; i < 6; i++)
			if (find_el(sfirst, elements[i]) == true)
			{
				first1 = sfirst.find(elements[i]);
				if (elements[i][0] == '!')
					(temp += elements[i][1]) += elements[i][2];
				else
					((temp += '!') += elements[i][0]) += elements[i][1];
				break;
			}
		temp += '*';
		for (int i = 0; i < 6; i++)
			if (find_el(sfirst, elements[i]) == true && sfirst.find(elements[i]) != first1)
			{
				if (elements[i][0] == '!')
					(temp += elements[i][1]) += elements[i][2];
				else
					((temp += '!') += elements[i][0]) += elements[i][1];
				second1 = sfirst.find(elements[i]);
				break;
			}
		sfirst = temp;
	}
	cout << sfirst << '+' << ssecond << endl;
	cout << "Fiñíäô(x1,x2,x3)=";
	string temp, result1;
	int position;
	for (int i = 1; i <= 3; i++)
		if (sfirst.find(i + '0') == -1)
		{
			switch (i){
			case 1: {
				result1="x1*" + sfirst + "+!x1*" + sfirst; break;
			}
			case 2:{
				if (sfirst.find(elements[0]) != -1)
					if (sfirst.find(elements[4]) != -1)
						result1= elements[0] + "*x2*" + elements[4] + '+' + elements[0] + "*!x2*" + elements[4];
					else
						result1= elements[0] + "*x2*" + elements[5] + '+' + elements[0] + "*!x2*" + elements[5];
				else
					if (sfirst.find(elements[4]) != -1)
						result1 = elements[1] + "*x2*" + elements[4] + '+' + elements[1] + "*!x2*" + elements[4];
					else
						result1=elements[1] + "*x2*" + elements[5] + '+' + elements[1] + "*!x2*" + elements[5];
				break;
			}
			case 3:{
				result1= sfirst + "*x3+" + sfirst + "*!x3"; break;
			}
			}
			break;
		}
	result1 += '+';
	for (int i = 1; i <= 3; i++)
		if (ssecond.find(i + '0') == -1)
		{
			switch (i){
			case 1: {
				result1+= "x1*" + ssecond + "+!x1*" + ssecond; break;
			}
			case 2:{
				if (find_el(ssecond, elements[0]) == true)
					if (find_el(ssecond, elements[4]) == true)
						result1+= elements[0] + "*x2*" + elements[4] + '+' + elements[0] + "*!x2*" + elements[4];
					else
						result1+= elements[0] + "*x2*" + elements[5] + '+' + elements[0] + "*!x2*" + elements[5];
				else
					if (find_el(ssecond, elements[4]) == true)
						result1+=elements[1] + "*x2*" + elements[4] + '+' + elements[1] + "*!x2*" + elements[4];
					else
						result1 += elements[1] + "*x2*" + elements[5] + '+' + elements[1] + "*!x2*" + elements[5];
				break;
			}
			case 3:{
				result1+= ssecond + "*x3+" + ssecond + "*!x3"; break;
			}
			}
			break;
		}
	cout << result1;
	cout << "\nFiêíô=";
	string mass[4];
	int tmp = 0;
	for (int i = 0; i < 6; i++)
		if (find_el(sfirst, elements[i]) == true)
			for (int j = 0; j < 6; j++)
				if (find_el(ssecond, elements[j]) == true&&i!=j)
					if (check(elements[i], elements[j]) == false)
						mass[tmp++] = elements[i] + '+' + elements[j];
					else
						mass[tmp++] = elements[j] + '+' + elements[i];
	int top = 4, pr1, pr2;
	int number[3] = { 0, 2, 4 };
	for (int k = 0; k < top; k++)
		for (int i : number)
			if (find_element(mass[k], elements[i], elements[i+1])==true)
			{
				for (int j = k; j < top - 1; j++)
					mass[j] = mass[j + 1];
				top--;
			}
	for (int i = 0; i < top; i++)
		cout << '(' << mass[i] << ")*";
	cout << "\b " << endl;
	string arr[6];
	cout << "Fiñêíô=";
	for (int k = 0; k < top; k++)
	{
		for (int i = 1; i <= 3; i++)
			if (mass[k].find(i + '0') == -1)
			{
				position = i;
				break;
			}
		switch (position){
		case 1: arr[2 * k] = "(x1+" + mass[k] + ')'; arr[2 * k + 1] = "(!x1+" + mass[k] + ')'; break;
		case 2: {
			if (find_el(mass[k], elements[0]) == true)
				if (find_el(mass[k], elements[4]) == true)
				{
					arr[2 * k] = '(' + elements[0] + "+x2+" + elements[4] + ')';
					arr[2 * k + 1] = '(' + elements[0] + "+!x2+" + elements[4] + ')';
				}
				else
				{
					arr[2 * k] = '(' + elements[0] + "+x2+" + elements[5] + ')';
					arr[2 * k + 1] = '(' + elements[0] + "+!x2+" + elements[5] + ')';
				}
			else
				if (find_el(mass[k], elements[4]) == true)
				{
					arr[2 * k] = '(' + elements[1] + "+x2+" + elements[4] + ')';
					arr[2 * k + 1] = '(' + elements[1] + "+!x2+" + elements[4] + ')';
				}
				else
				{
					arr[2 * k] = '(' + elements[1] + "+x2+" + elements[5] + ')';
					arr[2 * k + 1] = '(' + elements[1] + "+!x2+" + elements[5] + ')';
				}
			break;
		}
		case 3: arr[2 * k] = '(' + mass[k] + "+x3)"; arr[2 * k + 1] = '(' + mass[k] + "+!x3)"; break;
		}
	}
	int tp = 2 * top;
	for (int i = 0; i < tp; i++)
		for (int j = 0; j < tp; j++)
			if (i != j&&arr[i] == arr[j])
				for (int k = j; k < tp - 1; k++)
				{
					arr[k] = arr[k + 1];
					tp--;
				}
	string result;
	for (int i = 0; i < tp - 1; i++)
		result += arr[i] + '*';
	result += arr[tp - 1];
	cout << result << endl;
	int dl = result1.length();
	string nb[10];
	top = 0;
	for (int i = 0; i < dl; i++)
		if (result1[i] != '+')
		{
			if (result1[i] >= '0'&&result1[i] <= '3')
				if (i >= 2 && result1[i - 2] == '!')
					nb[top] += '0';
				else
					nb[top] += '1';
		}
		else
			top++;
	top++;
	int nbd[10] = { 0 };
	tp = 0;
	for (int i = 0; i < top; i++)
	{
		tp = 0;
		for (int j = 2; j >= 0; --j)
		{
			int sch = 1;
			for (int k = 0; k < tp; k++)
				sch *= 2;
			if (nb[i][j] == '1')
				nbd[i] += sch;
			tp++;
		}
	}
	for (int i = 0; i < top; i++)
		for (int j = top - 1; j > i; j--)
			if (nbd[j] < nbd[j - 1])
				swap(nbd[j], nbd[j - 1]);
	cout << "×: Fñíäô=\\/(";
	for (int i = 0; i < top; i++)
		cout << nbd[i] << ',';
	cout << "\b)\n";
	cout << "×: Fñêíô=/\\(";
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j < top; j++)
			if (nbd[j] == i)
				goto metka;
		cout << i << ',';
	metka:;
	}
	cout << "\b)\n";
	int razr[8] = { 128, 64, 32, 16, 8, 4, 2, 1 };
	int sch = 0;
	for (int i = 0; i < top; i++)
		sch += razr[nbd[i]];
	cout << "i      0   1   2   3   4   5   6   7\n"
		<<"x1     0   0   0   0   1   1   1   1\n"
		<<"x2     0   0   1   1   0   0   1   1\n"
		<<"x3     0   1   0   1   0   1   0   1\nFiñêíô ";
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j < top; j++)
			if (i == nbd[j])
			{
				cout << "1   ";
				goto met1;
			}
		cout << "0   ";
	met1:;
	}
	cout << endl << "Fiñêíô ";
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j < top; j++)
			if (i == nbd[j])
			{
				cout << "1   ";
				goto met;
			}
		cout << "0   ";
	met:;
	}
	cout << endl << "       ";
	cout << "128 64  32  16  8   4   2   1";
	cout << "\ni=" << sch;
	_getch();
	return 0;
}

string find_1(string exp, string sign, mode& f, int& first)
{
	string sfirst;
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
		{
			first = exp.find('(' + elements[i] + sign + elements[j] + ')');
			if (first == string::npos)
				continue;
			int ind = first;
			if (first - 1 >= 0 && exp[first - 1] != '!')
			{
				ind = first;
				sfirst += "!";
				while (exp[ind] != ')')
					sfirst += exp[ind++];
				sfirst += exp[ind];
			}
			else
			{
				ind = first + 1;
				while (exp[ind] != ')')
					sfirst += exp[ind++];
			}
			if (exp[ind + 1] == '*')
				f = product;
			else
				f = (mode)0;
			return sfirst;
		}
	return sfirst;
}
bool check(string a, string b){
	int p1, p2;
	if (a[0] == '!')
		p1 = a[2] - '0';
	else
		p1 = a[1] - '0';
	if (b[0] == '!')
		p2 = b[2] - '0';
	else
		p2 = b[1] - '0';
	return (p1 > p2) ? true : false;
}
