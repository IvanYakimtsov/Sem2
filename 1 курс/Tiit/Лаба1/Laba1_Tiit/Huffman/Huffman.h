#ifndef Huffman_H
#define Huffman_H
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
void BuildTable(Node *root);
void Create_Map();
list<Node*> Create_List();
list<Node*> Create_Tree(list<Node*> t);
void Create_output_file();
void output_on_screen(Node *p );


#endif // HUFFMAN_H_INCLUDED
