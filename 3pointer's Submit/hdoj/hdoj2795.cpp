#include <stdio.h>
#define lson l, m, s << 1
#define rson m + 1, r, s << 1 | 1

const int N = 200010;
int Max[N * 4];
int h, w, n;
inline int max(int a, int b)
{
    return a > b? a : b;
}

void pushup(int s)
{
    Max[s] = max(Max[s << 1], Max[s << 1 | 1]);
}

void build(int l, int r, int s)
{
    if (l == r)
    {
        Max[s] = w;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(s);
}

int query(int x, int l, int r, int s)
{
    if (l == r)
    {
        Max[s] -= x;
        return l;
    }
    int m = (l + r) >> 1;
    int ans = 0;
    if (Max[s << 1] >= x)
        ans = query(x, lson);
    else
        ans = query(x, rson);
    pushup(s);
    return ans;
}

int main()
{
    int x;
    while(scanf("%d%d%d", &h, &w, &n) != EOF)
    {
        build(1, n, 1);
        if (h > n)
            h = n;
        while(n --)
        {
            scanf("%d", &x);
            if (Max[1] < x)
                puts("-1");
            else
                printf("%d\n", query(x, 1, h, 1));
        }
    }
}
