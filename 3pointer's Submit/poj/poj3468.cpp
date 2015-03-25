#include <stdio.h>
#define lson l, m, s << 1
#define rson m + 1, r, s << 1 | 1

const int N = 100010;
long long add[N << 2];
long long sum[N << 2];

void pushup(int s)
{
    sum[s] = sum[s << 1] + sum[s << 1 | 1];
}

void pushdown(int s, int m)
{
    if (add[s])
    {
        add[s << 1] += add[s];
        add[s << 1 | 1] += add[s];
        sum[s << 1] += (m - (m >> 1)) * add[s];
        sum[s << 1 | 1] += (m >> 1) * add[s];
        add[s] = 0;
    }
}

void build(int l, int r, int s)
{
    add[s] = 0;
    if (l == r)
    {
        scanf("%lld", &sum[s]);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(s);
}

void update(int ll, int rr, int val, int l, int r, int s)
{
    if (ll <= l && r <= rr)
    {
        add[s] += val; 
        sum[s] += val * (r - l + 1);
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

long long query(int ll, int rr, int l, int r, int s)
{
    if (ll <= l && r <= rr)
    {
        return sum[s];
    }
    pushdown(s, r - l + 1);
    int m = (l + r) >> 1; 
    long long ans = 0;
    if (ll <= m)
        ans += query(ll, rr, lson);
    if (rr > m)
        ans += query(ll, rr, rson);
    return ans;
}

int main()
{
    int n, m;
    int a, b;
    int c;
    char str[5];
    while(scanf("%d%d", &n, &m) != EOF)
    {
        build(1, n, 1); 
        while(m --)
        {
            scanf("%s %d %d", str, &a, &b);
            if (str[0] == 'Q')
                printf("%lld\n", query(a, b, 1, n, 1));
            else
            {
                scanf("%d", &c);
                update(a, b, c, 1, n, 1);
            }
        }
    }
    return 0;
}
