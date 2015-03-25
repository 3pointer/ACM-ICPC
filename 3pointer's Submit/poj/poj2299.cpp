#include <stdio.h>
#include <algorithm>
#define lson l, m, s << 1
#define rson m + 1, r, s << 1 | 1
#define N 500001
using namespace std;

int sum[N << 2];
struct node
{
    int v, order;
}a[N];
int aa[N];

void pushup(int s)
{
    sum[s] = sum[s << 1] + sum[s << 1 | 1];
}

void build(int l, int r, int s)
{
    if (l == r)
    {
        sum[s] = 0;
        return ;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(s);
}

void update(int p, int l, int r, int s)
{
    if (l == r)
    {
        sum[s] ++;
        return;
    }
    int m = (l + r) >> 1;
    if (p > m)
        update(p, rson);
    if (p <= m)
        update(p, lson);
    pushup(s);
}

int query(int ll, int rr, int l, int r, int s)
{
    if (ll <= l && r <= rr)
    {
        return sum[s];
    }
    int m = (l + r) >> 1;
    int res = 0;
    if (ll <= m)
        res += query(ll, rr, lson);
    if (rr > m)
        res += query(ll, rr, rson);
    return res;
}

void test(int l, int r, int s)
{
 //   printf("%d %d %d %d\n", sum[s], s, l, r);
    if (l == r)
    {
        printf("%d %d\n", l , sum[s]);
        return;
    }
    int m = (l + r) >> 1;
    test(lson);
    test(rson);
}

int cmp(node a, node b)
{
    return a.v < b.v;
}

int main()
{
    int n, m;
    while(scanf("%d", &n) && n)
    {
        for (int i = 1; i <= n; i++)      
            scanf("%d", &a[i].v), a[i].order = i;

        sort(a + 1, a + n + 1, cmp);

        for (int i = 1; i <= n; i++)
            aa[a[i].order] = i;

        build(1, n, 1); 

        long long ans = 0;
        for (int i = n; i >= 1; i--)
        {
            ans += (long long)query(1, aa[i], 1, n, 1);    
            update(aa[i], 1, n, 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
