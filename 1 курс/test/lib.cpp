#include "head.h"

//����������
void build_tree(int v, int tl, int tr,int *a,int *tree,int *upd,int n)
{
    if(tl == tr) tree[v] = a[tl];
    else
    {
        int tm = (tl + tr) >> 1;
        build_tree(v + v, tl, tm,a,tree,upd,n);
        build_tree(v + v + 1, tm + 1, tr,a,tree,upd,n);
        tree[v] = tree[v + v] + tree[v + v + 1];
    }
}

//������ �� l..r
int query_tree(int v, int tl, int tr, int l, int r,int *a,int *tree,int *upd,int n)
{
    if(l > r) return 0;
    if(upd[v] != -1) return upd[v] * (r - l + 1); //���� ������� ���� ���������, �� ����� ��� �������� ������� = �������� � ������� * ����� �������. ��������� � ������� ��� ����������
    if(l == tl && r == tr) return tree[v];
    int tm = (tl + tr) >> 1;
    return query_tree(v + v, tl, tm, l, std::min(r, tm),a,tree,upd,n) + query_tree(v + v + 1, tm + 1, tr, std::max(l, tm + 1), r,a,tree,upd,n);
}

//������������ �� l..r = color
void update_tree(int v, int tl, int tr, int l, int r, int color,int *a,int *tree,int *upd,int n)
 {

   if(l > r) return;
    if(l == tl && tr == r)
    {
        upd[v] = color; //��������� ������� v
        tree[v] = color * (r - l + 1);
    }
    else
    {
        upd[v] = -1; //������ �������(������� v) �� ���������, ��������� ��� ����������
        int tm = (tl + tr) >> 1;
        update_tree(v + v, tl, tm, l, std::min(r, tm), color,a,tree,upd,n);
        update_tree(v + v + 1, tm + 1, tr, std::max(l, tm + 1), r, color,a,tree,upd,n);
        tree[v] = tree[v + v] + tree[v + v + 1];
    }
}
