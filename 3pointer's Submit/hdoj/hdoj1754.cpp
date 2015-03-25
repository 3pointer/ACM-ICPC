#include <stdio.h>
#define lson l, m, s << 1 
#define rson m + 1, r, s << 1 | 1 
const int N = 200010;

int Max[N << 2];
inline int max(int a, int b)
{
    return a < b? b : a;
}

void pushup(int s)
{
    Max[s] = max(Max[s << 1], Max[s << 1 | 1]);
}

void build(int l, int r, int s)
{
    if (l == r)
    {
        scanf("%d", &Max[s]);
        return ;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(s);
}

void update(int p, int score, int l , int r, int s)
{
    if (l == r)
    {
        Max[s] = score;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m)
        update(p, score, lson);
    else
        update(p, score, rson);
    pushup(s);
}

int query(int ll, int rr, int l, int r, int s)
{
    if (ll <= l && r <= rr)
    {
        return Max[s];
    }
    int m = (l + r) >> 1;
    int ans = 0;
    if (ll <= m)
        ans = max(ans, query(ll, rr, lson));
    if (rr > m)
        ans = max(ans, query(ll, rr, rson));
    return ans;
}

int main()
{
    int n, m;
    char str[3];
    int a, b;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        build(1, n, 1); 
        while(m --)
        {
            scanf("%s", str);
            scanf("%d%d", &a, &b);
            if (str[0] == 'Q')
                printf("%d\n", query(a, b, 1, n, 1));
            else
                update(a, b, 1, n, 1);
        }
    }
    return 0;
}
