#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

struct data
{
	char* key;
	char* value;
	int flag : 5;
};

struct Hash
{
	data ID;
	unsigned  long long v;
	unsigned address;
};

enum flags{ C = 1, U = 2, T = 4, L = 8, D = 16 };
typedef Hash* Hash_TABLE;
data* MEMORY[0x33];


bool add_into_table(data* info);

unsigned  long long into_num_form(const char* pointer_to_key);
unsigned square_form(const unsigned& key);
char* find(char* key_string);
bool Delete(char* key_string);
void print(Hash D);


int main(int argc, char *argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "russian");
	for (int i = 0; i < 51; ++i)
	{
		MEMORY[i] = new data;
		*MEMORY[i] = { "", "", 0x0 };
	}
	data **table = new data*[20];

	table[0] = new data;  *table[0] = { "͸���", "������", 0x0 };
	table[1] = new data;  *table[1] = { "���", "������", 0x0 };
	table[2] = new data;  *table[2] = { "��������", "��������", 0x0 };
	table[3] = new data;  *table[3] = { "��������", "��������", 0x0 };
	table[4] = new data;  *table[4] = { "�����", "������", 0x0 };
	table[5] = new data;  *table[5] = { "�����", "������", 0x0 };
	table[6] = new data;  *table[6] = { "�����", "�����", 0x0 };
	table[7] = new data;  *table[7] = { "���", "������", 0x0 };
	table[8] = new data;  *table[8] = { "���������", "���", 0x0 };
	table[9] = new data;  *table[9] = { "���", "������", 0x0 };
	table[10] = new data;  *table[10] = { "����", "������", 0x0 };
	table[11] = new data;  *table[11] = { "�����", "������", 0x0 };
	table[12] = new data;  *table[12] = { "�����", "����", 0x0 };
	table[13] = new data;  *table[13] = { "�����������", "�����", 0x0 };
	table[14] = new data;  *table[14] = { "�������", "������", 0x0 };
	table[15] = new data;  *table[15] = { "���", "��������", 0x0 };
	table[16] = new data;  *table[16] = { "����", "�����", 0x0 };
	table[17] = new data;  *table[17] = { "����", "��������", 0x0 };
	table[18] = new data;  *table[18] = { "������", "�����", 0x0 };
	table[19] = new data;  *table[19] = { "�����", "������", 0x0 };

	for (int i = 0; i < 20; ++i)
		add_into_table(table[i]);
	char dial;
	while (true)
	{
		cout << endl << "1 - �������� ����\n2 - ����� ��������\n3 - ������� ����\n4 - �������� �������\n5 - �����\n";
		cin >> dial;
		char *k = new char;
		char *v = new char;
		data* Data;
		switch (dial)
		{
		case '1':
			cout << setw(11) << "����:";
			fflush(stdin);
			cin.getline(k, 100);
			fflush(stdin);
			cout << setw(11) << "��������:";
			cin.getline(v, 100);
			fflush(stdin);
			Data = new data;
			*Data = { k, v, 0x0 };
			if (!add_into_table(Data))
				cout << "���� ��� ���� � �������" << endl;
			break;
		case '2':
			cout << setw(11) << "����:"; cin >> k;
			v = find(k);
			if (v)
				cout << setw(11) << "��������:" << v;
			else
				cout << "���� ��� � �������" << endl;
			break;
		case '3':
			cout << setw(11) << "����:"; cin >> k;
			if (Delete(k))
				cout << "�������\n";
			else
				cout << "���� ����������� � �������";
			break;
		case '4':
			cout << setw(4) << "addr|" << setw(15) << "Key" << '|' << setw(15) << "value" << '|'<<
			" C | U | T | L |" << endl <<endl;
			for (int i = 0; i < 51; ++i)
				print({ *MEMORY[i], 0, i });
			break;
		case '5':
			exit(0);
		}
	}
	system("pause");
	return 0;
}

bool add_into_table(data* info)
{
	unsigned long long v = into_num_form(info->key);
	unsigned address = square_form(v);
	Hash *row = new Hash ({ *info, v, address });
	if (MEMORY[row ->address]->flag & U)
	{
		if (!strcmp(MEMORY[row->address]->key, info->key))
			return false;
		MEMORY[row ->address]->flag |= C;
		MEMORY[row ->address]->flag &= 0X1B;
		for (int i = row ->address + 1;; ++i)
		{
			if (MEMORY[i]->flag & U)
			{
				if (!strcmp(MEMORY[i]->key, info->key))
					return false;
				MEMORY[i]->flag &= 0X1B;
				continue;
			}
			MEMORY[i] = info;
			row ->address = i;
			MEMORY[i]->flag = L | U | T;
			break;
		}
	}
	else
	{
		MEMORY[row ->address] = info;
		MEMORY[row ->address]->flag = L | U | T;
	}
	return true;
}

char* find(char* key_str)
{
	unsigned num_form = into_num_form(key_str);
	unsigned addr = square_form(num_form);
	if (MEMORY[addr]->flag & C)
	for (; !(MEMORY[addr]->flag & T); ++addr)
	{
		if (MEMORY[addr]->key != key_str)
			continue;
		return MEMORY[addr]->value;
	}
	return strcmp(MEMORY[addr]->key, key_str) ? NULL : MEMORY[addr]->value;
}

bool Delete(char* key_str)
{
	unsigned num_form = into_num_form(key_str);
	unsigned addr = square_form(num_form);
	for (; strcmp(MEMORY[addr]->key, key_str); ++addr);
	if (MEMORY[addr]->flag & !U)
		return false;
	if (MEMORY[addr]->flag & C & T)
	{
		if (MEMORY[addr + 1]->flag & T);
		else MEMORY[addr + 1]->flag |= C;
		*MEMORY[addr] = { "", "", 0x0 };
		return true;
	}
	if (MEMORY[addr]->flag & T & U)
	{
		if (MEMORY[addr - 1]->flag & C)
			MEMORY[addr - 1]->flag &= 0X1D;
		MEMORY[addr - 1]->flag |= T;
		*MEMORY[addr] = { "", "", 0x0 };
		return true;
	}
	if (MEMORY[addr]->flag & U)
	{
		*MEMORY[addr] = { "", "", 0x0 };
		return true;
	}
	return false;
}

unsigned  long long into_num_form(const char* key_ptr)
{
	unsigned  long long result(0), length = strlen(key_ptr);
	int n = 0;
	for (int i = 0; i < length; ++i)
	{
		n = -1*(int)key_ptr[i];
		result += n * pow(2, length - i);
	}
	return result;
}

unsigned square_form(const unsigned& number)
{
	unsigned long long n = number * number;
	int a = n % 51;
	return a;
}
void print(Hash D)
{
	cout << setw(4) << D.address << '|' << setw(15) << D.ID.key << '|' << setw(15) << D.ID.value << '|';
	(D.ID.flag & C) ? cout << " 1 |" : cout << " 0 |";
	(D.ID.flag & U) ? cout << " 1 |" : cout << " 0 |";
	(D.ID.flag & T) ? cout << " 1 |" : cout << " 0 |";
	(D.ID.flag & L) ? cout << " 1 |" : cout << " 0 |";
	cout << endl;
}
