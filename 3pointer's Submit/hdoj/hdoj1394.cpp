#include <stdio.h>
#include <string.h>
#define lson l, m, s << 1
#define rson m + 1, r, s << 1 | 1

const int N = 5555;
int time[N << 2];
int val[N];

void pushup(int s)
{
    time[s] = time[s << 1] + time[s << 1 | 1];
}

void update(int p, int l, int r, int s)
{
    if (l == r)
    {
        time[s] ++;
        return ;
    }
    int m = (l + r) >> 1;
    if (p <= m)
        update(p, lson);
    else 
        update(p, rson);
    pushup(s);
}

int query(int ll, int rr, int l, int r, int s)
{
    if (ll <= l && r <= rr)
    {
        return time[s];
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
    int n;
    while(scanf("%d", &n) != EOF)
    {
        memset(time, 0, sizeof(time));
        int sum = 0;
        for (int i = 1; i <= n; i++) 
        {
            scanf("%d", &val[i]);
            val[i] ++;
            sum += query(val[i], n, 1, n, 1); // *1
            update(val[i], 1, n, 1);
        }
        int ans = sum;
        for (int i = 1; i <= n; i++)
        {
            sum += n - val[i] - (val[i] - 1);
            if (ans > sum)
                ans = sum;
        }
        printf("%d\n", ans);
    }
    return 0;
}
