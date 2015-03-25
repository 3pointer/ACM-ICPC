#include <stdio.h>
#include <string.h>
#define lson l, m, s << 1
#define rson m + 1, r, s << 1 | 1
#define N 1000001
long long sum[N << 2];
long long sum2[N + 10];
int val[N];

void pushup(int s)
{
    sum[s] = sum[s << 1] + sum[s << 1 | 1];
}

void build(int l, int r, int s)
{
    if (l == r)
    {
        sum[s] = val[l];
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(s);
}

long long query(int ll, int rr, int l, int r, int s)
{
    if (ll <= l && r <= rr)
    {
        return sum[s];
    }
    int m = (l + r) >> 1;
    int su = 0;
    if (ll <= m)
        su += query(ll, rr, lson);
    if (rr > m)
        su += query(ll, rr, rson);
    return su;

}
int main()
{
    int t;
    int n;
    long long k;
    int cas = 0;
    scanf("%d", &t);
    while(t --)
    {
        cas ++;
        int flag = 0;
        memset(sum2, 0, sizeof(sum2));
        scanf("%d%lld", &n, &k); 
        scanf("%d", &val[1]);
        sum2[1] = val[1];
        for (int i = 2; i <= n; i++)
        {
            scanf("%d", &val[i]);
            sum2[i] = sum2[i - 2] + val[i];
        }
        build(1, n, 1);

        if (flag == 1)
            printf("Case #%d: Yes.\n", cas);
        else
            printf("Case #%d: No.\n", cas);
        
    }
    return 0;
}
