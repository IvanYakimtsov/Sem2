#ifndef HUFFMAN_H_INCLUDED
#define HUFFMAN_H_INCLUDED
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <fstream>
using namespace std;

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


struct MyCompare
{
    bool operator()(const Node* l, const Node* r) const { return l->a < r->a; }
};
void BuildTable(Node *root);
Node* Create_Huffman_Tree(char* name);
void Output_on_Screen(Node* root);


#endif // HUFFMAN_H_INCLUDED
