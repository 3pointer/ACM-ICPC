#include <stdio.h>
#define lson l, m, s << 1
#define rson m + 1, r, s << 1 | 1

const int N = 50005;
int sum[N << 2];

void pushup(int s)
{
    sum[s] = sum[s << 1] + sum[s << 1 | 1];
}

void build(int l, int r, int s)
{
    if (l == r)
    {
        scanf("%d", &sum[s]);
        return ;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(s);
}

void update(int p, int add, int l, int r, int s)
{
    if (l == r)
    {
        sum[s] += add;
        return ;
    }
    int m = (l + r) >> 1;
    if (p <= m)
        update(p, add, lson);
    else
        update(p, add, rson);
    pushup(s);
}

int query(int ll, int rr, int l, int r, int s)
{
    if(ll <= l && r <= rr)
    {
        return sum[s];
    }
    int m = (l + r) >> 1;
    int ans = 0;
    if (ll <= m)
        ans += query(ll, rr, lson);
    if (rr > m)
        ans += query(ll, rr, rson);
    return ans;
}
int main()
{
    int t;
    int a, b;
    int n;
    char str[10];
    int id = 1;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d", &n);
        printf("Case %d:\n", id ++);
        build(1, n, 1);
        while(scanf("%s", str) && str[0] != 'E')
        {
            scanf("%d%d", &a, &b);
            if (str[0] == 'Q')
                printf("%d\n", query(a, b,1, n, 1));
            if (str[0] == 'A' || str[0] == 'S')
            {
                if (str[0] == 'A')
                {
                    update(a, b, 1, n, 1);
                }
                else
                {
                    update(a, -b, 1, n, 1);
                }
            }
        }
    }
    return 0;
}

