#include <stdio.h>
#include <stdlib.h>
#define lson l, m, s << 1
#define rson m + 1, r, s << 1 | 1

const int N = 200020;
int pos[N];
int val[N];
int seq[N];
int num[N << 2];
int id;

void build(int l, int r, int s)
{
    num[s] = r - l + 1;
    if (l == r)
    {
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}

void update(int p, int l, int r, int s)
{
    num[s] --; 
    if (l == r)
    {
        id = l;
        return;
    }
    int m = (l + r) >> 1;
    if (num[s << 1] >= p)
        update(p, lson);
    else
    {
        p -= num[s << 1];
        update(p, rson);
    }
}



int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        build(0, n - 1, 1);
        for (int i = 1; i <= n; i++) 
            scanf("%d%d", &pos[i], &val[i]);
        for (int i = n; i >= 1; i--)
        {
            update(pos[i] + 1, 1, n, 1);        
            seq[id] = val[i];
        }
        printf("%d", seq[1]);
        for (int i = 2; i <= n; i++)
            printf(" %d", seq[i]);
        printf("\n");
    }
    return 0;
}
