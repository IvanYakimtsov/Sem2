#include "Huffman.h"


int main (int argc, char *argv[])
{setlocale(LC_ALL,"Russian");
Node* root;
cout<<"������� ��� ����� ������� �� ������ ������������: ";
char name[40];
cin.getline(name, 40);
root=Create_Huffman_Tree(name);
int choise=0;
cout<<"������������ ����� � ������� �� �����?(1-��,2-���)"<<endl;
cin>>choise;
switch (choise)
{
  case 1:{Output_on_Screen(root);break;}
  case 2: break;
  default:{cout<<"error"; break;}
}
int choise1=0;
cout<<endl;


	return 0;
}
