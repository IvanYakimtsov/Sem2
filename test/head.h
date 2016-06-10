#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include <cstdio>
#include <algorithm>

#define MAXN 100007




void build_tree(int v, int tl,int tr,int *a,int *tree,int *upd,int n);
int query_tree(int v, int tl, int tr, int l, int r,int *a,int *tree,int *upd,int n);
void update_tree(int v, int tl, int tr, int l, int r, int color,int *a,int *tree,int *upd,int n);


#endif // HEAD_H_INCLUDED
