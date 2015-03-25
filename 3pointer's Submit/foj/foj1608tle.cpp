#include <stdio.h>
#include <algorithm>
#define lson l, m, s << 1
#define rson m + 1, r, s << 1 | 1

using namespace std;

const int N = 50010;
int sum[N << 2];
int add[N << 2];

struct node
{
    int s, t, ef;
}p[500100];

int cmp(const node & a, const node & b)
{
    return a.ef < b.ef;
}

void pushup(int s)
{
    sum[s] = sum[s << 1] + sum[s << 1 | 1];
}

void pushdown(int s)
{
    if (add[s])
    {
        add[s] = 0;
        add[s << 1] = 1;
        add[s << 1 | 1] = 1; 
        sum[s << 1] = sum[s << 1 | 1] = 0;
    }
}
void build(int l, int r, int s)
{
    add[s] = 0;
    sum[s] = r - l + 1;
    if (l == r)
    {
        return ;
    }
    int m = (l + r ) >> 1;
    build(lson);
    build(rson);
    //pushup(s);
}

void update(int ll, int rr, int l, int r, int s)
{
    if (ll > r || rr <= l)
        return;
    if (ll <= l && r <= rr)
    {
        add[s] = 1;    
        sum[s] = 0;
        return;
    }
    pushdown(s);
    int m = (l + r) >> 1;
    if (ll <= m)
        update(ll, rr, lson);
    if (rr > m)
        update(ll, rr, rson);
    pushup(s);
}

int query(int ll, int rr, int l, int r, int s)
{
    if (ll > r || rr <= l)
        return 0;
    if (ll <= l && r <= rr)
    {
        return sum[s]; 
    }
    pushdown(s);
    int ans = 0;
    int m = (l + r ) >> 1;
    if (ll <= m)
        ans += query(ll, rr, lson);
    if (rr > m)
        ans += query(ll, rr, rson);
    return ans;
}

int main()
{
    int n, m;
    int a, b, c;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        build(1, n, 1);
        for (int i = 0; i < m ; i++)
            scanf("%d%d%d", &p[i].s, &p[i].t, &p[i].ef);

        sort(p, p + m, cmp);
        
        int ans = 0;
        for (int i = m - 1; i >= 0; i--)
        {
            ans += p[i].ef * query(p[i].s + 1, p[i].t, 1, n, 1);
            update(p[i].s + 1, p[i].t, 1, n, 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
