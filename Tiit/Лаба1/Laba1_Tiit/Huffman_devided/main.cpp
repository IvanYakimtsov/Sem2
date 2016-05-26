#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <fstream>
using namespace std;

//----------------------------------------------------------------------------
class Node
{
	public:
	 int a;
	 char c;
	 Node *left, *right;

	 Node(){left=right=NULL;}

	 Node(Node *L, Node *R)
	 {  left =  L;
	    right = R;
	    a = L->a + R->a;  }
};

//----------------------------------------------------------------------------
struct MyCompare
{
    bool operator()(const Node* l, const Node* r) const { return l->a < r->a; }
};
//----------------------------------------------------------------------------

map<char,int> m;
ifstream f("1.txt", ios::out | ios::binary);
int count=0;
//----------------------------------------------------------------------------
vector<bool> code;
map<char,vector<bool> > table;
//----------------------------------------------------------------------------
void BuildTable(Node *root)
{
    if (root->left!=NULL)
                      { code.push_back(0);
                      BuildTable(root->left);}

    if (root->right!=NULL)
                       { code.push_back(1);
                       BuildTable(root->right);}

    if (root->left==NULL && root->right==NULL) table[root->c]=code;

    code.pop_back();
}
//---------------------------------------------------------------------
void Create_Map()
{
 ////// считаем частоты символов

	while (!f.eof())
	{ char c = f.get();
	   m[c]++;}

}
//----------------------------------------------------------------------------
list<Node*> Create_List()
{list<Node*> t;
  ////// записываем начальные узлы в список list
for( map<char,int>::iterator itr=m.begin(); itr!=m.end(); ++itr)
   {
      Node *p = new Node;
      p->c = itr->first;
      p->a = itr->second;
      t.push_back(p);      }
return t;

}
//----------------------------------------------------------------------------
list<Node*> Create_Tree(list<Node*> t)
{
  //////  создаем дерево
  while (t.size()!=1)
  {
     t.sort(MyCompare());

     Node *SonL = t.front();
     t.pop_front();
     Node *SonR = t.front();
     t.pop_front();

     Node *parent = new Node(SonL,SonR);
     t.push_back(parent);

  }
  return t;
}
//----------------------------------------------------------------------------
void Create_output_file()
{
    f.clear(); f.seekg(0); // перемещаем указатель снова в начало файла

	ofstream g("output.txt", ios::out | ios::binary);
     char buf=0;
    while (!f.eof())
    { char c = f.get();
	  vector<bool> x = table[c];
	  for(int n=0; n<x.size(); n++)
	   {buf = buf | x[n]<<(7-count);
	    count++;
	    if (count==8) { count=0;   g<<buf; buf=0; }
       }
    }
    g.close();
    f.close();
}
//----------------------------------------------------------------------------
void output_on_screen(Node *p )
{
    ///// считывание из файла output.txt и преобразование обратно
    Node *root1=p;
	ifstream F("output.txt", ios::in | ios::binary);

	setlocale(LC_ALL,"Russian"); // чтоб русские символы отображались в командной строке


	count=0; char byte;
	byte = F.get();
	while(!F.eof())
	{   bool b = byte & (1 << (7-count) ) ;
		if (b) p=p->right; else p=p->left;
		if (p->left==NULL && p->right==NULL) {cout<<p->c; p=root1;}
		count++;
		if (count==8) {count=0; byte = F.get();}
	}

F.close();
}
int main (int argc, char *argv[])
{list<Node*> t;
Create_Map();
t=Create_List();
t=Create_Tree(t);
Node *root = t.front();   //root - указатель на вершину дерева
////// создаем пары 'символ-код':
BuildTable(root);
////// ¬ыводим коды в файл output.txt
Create_output_file();

output_on_screen(root);




	return 0;
}
