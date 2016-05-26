#include "Huffman.h"
map<char,int> m;
ifstream f("1.txt", ios::out | ios::binary);
int count=0;
//----------------------------------------------------------------------------
vector<bool> code;
map<char,vector<bool> > table;
//----------------------------------------------------------------------------
//---------------------------------------------------------------------
void Create_Map()
{
 ////// ������� ������� ��������

	while (!f.eof())
	{ char c = f.get();
	   m[c]++;}

}
//----------------------------------------------------------------------------
list<Node*> Create_List()
{list<Node*> t;
  ////// ���������� ��������� ���� � ������ list
for( map<char,int>::iterator itr=m.begin(); itr!=m.end(); ++itr)
   {
      Node *p = new Node;
      p->c = itr->first;
      p->a = itr->second;
      t.push_back(p);      }
return t;

}
//----------------------------------------------------------------------------
void Create_output_file()
{
    f.clear(); f.seekg(0); // ���������� ��������� ����� � ������ �����

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


list<Node*> Create_Tree(list<Node*> t)
{
  //////  ������� ������
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

void output_on_screen(Node *p )
{
    ///// ���������� �� ����� output.txt � �������������� �������
    Node *root1=p;
	ifstream F("output.txt", ios::in | ios::binary);

	setlocale(LC_ALL,"Russian"); // ���� ������� ������� ������������ � ��������� ������


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

