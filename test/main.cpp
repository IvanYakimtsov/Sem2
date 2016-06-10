#include <cstdio>
#include "head.h"
#include <algorithm>

#define MAXN 100007





int main()
{

    int  a[MAXN], tree[4 * MAXN], upd[4 * MAXN], n;
    FILE *f = fopen("input.txt","rt"); //файл
    fscanf(f, "%d", &n); //читаем из файла
    for(int i = 0; i < n; i++) fscanf(f, "%d", a + i);
    for(int i = 0; i < 4 * MAXN; i++) upd[i] = -1; //Изначально все отрезки(вершины) не обновлены

    build_tree(1, 0, n - 1,a,tree,upd,n); //построим дерево для массива a[0 .. n - 1], корень = 1,
    int q, type, x, l, r;
    fscanf(f, "%d", &q); //сколько запросов


      for(int i=0;i<10; i++)
      {
        fscanf(f,"%d%d%d",&type,&l,&r);
        if(type == 1)
        {


      printf("%d\n", query_tree(1, 0, n - 1, l - 1, r - 1,a,tree,upd,n));
        }
       else if(type == 2)
       {
           fscanf(f, "%d%d", &x,&type,&l,&r );
update_tree(1, 0, n - 1, l - 1 , r - 1 , x ,a,tree,upd,n );

        }
    }

    fclose(f);

    return 0;
}
