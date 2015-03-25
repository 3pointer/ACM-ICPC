#include <stdio.h>
#define lson l, m, s << 1
#define rson m + 1, r, s << 1 | 1

const int N = 50010;
int Max[N << 2];
int col[N << 2];

inline int max(int a, int b)
{
    return a > b? a : b;
}

void pushup(int s)
{
    Max[s] = max(Max[s << 1], Max[s << 1 | 1]);
}

void pushdown(int s)
{
    if (col[s])
    {
        col[s] = 0;
        col[s << 1] = col[s << 1 | 1] = 0;
        Max[s << 1] = max(Max[s << 1], Max[s]);
        Max[s << 1 | 1] = max(Max[s << 1 | 1], Max[s]);
    }
}

void build(int l, int r, int s)
{
    Max[s] = 0;
    if (l == r)
    {
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}

void update(int ll, int rr, int val, int l, int r, int s)
{
    if (ll <= l && r <= rr)
    {
        Max[s] = max(Max[s], val);
        return;
    }
    int m = (l + r ) >> 1;
    if (ll <= m)
        update(ll, rr, val, lson);
    if (rr > m)
        update(ll, rr, val, rson);
}

int query(int l, int r, int s)
{
    if (l == r)
    {
        return Max[s];
    }
    Max[s << 1] = max(Max[s << 1], Max[s]);
    Max[s << 1 | 1] = max(Max[s << 1 | 1], Max[s]);

    int m = (l + r) >> 1;
    return query(l, m, s << 1) + query(m + 1, r, s << 1 | 1);
}

int main()
{
    int n, m;
    int x, y, z;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        build(1, n, 1);
        while(m --)
        {
            scanf("%d%d%d", &x, &y, &z);
            update(x + 1, y, z, 1, n, 1);
        }
        printf("%d\n", query(1, n, 1)); 
    }
    return 0;
}
