#include "Huffman.h"


int main (int argc, char *argv[])
{setlocale(LC_ALL,"Russian");
Node* root;
cout<<"¬ведите им€ файла который вы хотите закодировать: ";
char name[40];
cin.getline(name, 40);
root=Create_Huffman_Tree(name);
int choise=0;
cout<<"ƒекодировать текст и вывести на экран?(1-да,2-нет)"<<endl;
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
