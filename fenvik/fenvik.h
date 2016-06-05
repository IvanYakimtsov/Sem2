#ifndef FENVIK_H_INCLUDED
#define FENVIK_H_INCLUDED

#include <iostream>
#include <vector>
using namespace std;

struct fen
{
    vector<int>f;
};

//extern fen *a;
//extern fen *t;


void FenvikSum(int,int,fen *t,fen *a);
void FenvikAdd(int,int,fen *t,fen *a);
void FenvikCreate(int,fen *t,fen *a);



#endif // FENVIK_H_INCLUDED
