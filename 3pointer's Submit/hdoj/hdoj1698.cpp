#include <stdio.h>
#include <stdlib.h>
#define lson l, m, s << 1
#define rson m + 1, r, s << 1 | 1

const int N = 100100;
int sum[N << 2];
int col[N << 2];

void pushup(int s)
{
    sum[s] = sum[s << 1] + sum[s << 1 | 1];
}

void pushdown(int s, int m)
{
    if (col[s])
    {
        col[s << 1] = col[s << 1 | 1] = col[s];
        sum[s << 1] = (m - (m >> 1)) * col[s];
        sum[s << 1 | 1] = (m >> 1) * col[s];
        col[s] = 0;
    }
}
void build(int l, int r, int s)
{
    col[s] = 0;
    sum[s] = 1;
    if (l == r)
    {
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(s);
}
void test(int l, int r, int s)
{
        
    printf("%d %d %d %d\n", l, r, sum[s], col[s]);
    if (l == r)
        return;
    int m = (l + r ) >> 1;
    test(lson);
    test(rson);
}

void update(int ll, int rr, int val, int l, int r, int s)
{
    if (ll <= l && r <= rr)
    {
        sum[s] = val * (r - l + 1);
        col[s] = val;
        return;
    }
    pushdown(s, r - l + 1);
    int m = (l + r) >> 1;
    if (ll <= m)
        update(ll, rr, val, lson);
    if (rr > m)
        update(ll, rr, val, rson);
    pushup(s);
}
int main()
{
    int t;
    int n, m;
    int x, y, z;
    scanf("%d", &t);
    for (int i = 1; i <= t; i ++)
    {
        scanf("%d %d", &n, &m);
        build(1, n, 1);
        while(m --)
        {
            scanf("%d %d %d", &x, &y, &z);
            update(x, y, z, 1, n, 1);
            //test(1, n, 1);
        }
        printf("Case %d: The total value of the hook is %d.\n", i, sum[1]);
    }

    return 0;
}
