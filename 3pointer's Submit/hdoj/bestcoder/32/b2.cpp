#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 4000007
typedef long long ll;

struct node
{
    int head[M]; 
    int next[500002];
    ll S[500002];
    int tot;
    void add(ll s)
    {
        int tmp = abs(s) % M;
        S[tot] = s;
        next[tot] =head[tmp];
        head[tmp] = ++tot;
    }
    int que(ll s)
    {
        for (int i = head[abs(s) % M]; i != -1 ; i = next[i])
            if (S[i] == s)
                return 1;
        return 0;
    }
    void cl()
    {
        memset(head, -1, sizeof(head));
        tot = 0;
    }
}h1, h2;
ll a[1000011];
ll su[1000011];

int main()
{
    int t, cas;
    int n;
    ll k;
    scanf("%d", &t);
    for (cas = 1; cas <= t; cas ++)
    {
        h1.cl();
        h2.cl();
        scanf("%d %lld", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        int flag = 0;
        su[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i & 1)
                su[i] = su[i - 1] + a[i];
            else
                su[i] = su[i - 1] - a[i];
        }
        for (int i = 0; i <= n; i++)
        {
            if (i & 1)
                h1.add(su[i]);
            else
                h2.add(su[i]);
        }
        for (int i = 1; !flag && i <= n; i++)
        {
            if (h1.que(su[i] - k)) flag = 1;
            if (h2.que(su[i] - k)) flag = 1;
        }
        if (flag)
            printf("Case #%d: Yes.\n", cas);
        else
            printf("Case #%d: No.\n", cas);
    }
    return 0;
}
