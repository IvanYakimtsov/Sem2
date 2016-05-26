#pragma once
#ifndef HUFFMAN_H_INCLUDED
#define HUFFMAN_H_INCLUDED

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
list<Node*> t;
map<char,int> m;
ifstream f("1.txt", ios::out | ios::binary);
int count=0;
//----------------------------------------------------------------------------
vector<bool> code;
map<char,vector<bool> > table;
//----------------------------------------------------------------------------

#endif // HUFFMAN_H_INCLUDED
