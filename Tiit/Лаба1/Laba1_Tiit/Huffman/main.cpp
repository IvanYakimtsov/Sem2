#include "Huffman.h"
void Create_Huffman_Tree()
{list<Node*> t;
Create_Map();
t=Create_List();
t=Create_Tree(t);
Node *root = t.front();   //root - ��������� �� ������� ������
////// ������� ���� '������-���':
BuildTable(root);
////// ������� ���� � ���� output.txt
Create_output_file();

output_on_screen(root);

}

int main (int argc, char *argv[])
{


void Create_Huffman_Tree();



	return 0;
}
