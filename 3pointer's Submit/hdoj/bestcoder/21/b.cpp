#include<stdio.h>
#define M 1000000007
int vis[9999901];

int main()
{
    int n;
    long long ans;
    long long aans;
    long long  last = 1;
    long long lasta = 1;
    int lastnum = 100;
    while(scanf("%d", &n) != EOF)
    {
        if (n <= 100)
        {
            ans = 1;
            aans = 1;//437918130
            for (int i = 1; i <= n; i++)
            {
                ans *= i;
                ans %= M;
                aans *= ans;
                aans %= M;
            }
            printf("%lld\n", aans);
            continue;
        }
        if (vis[n - 100])
        {
            printf("%d\n", vis[n - 100]);
            continue;
        }
        ans = 437918130;
        aans = 148277692;
        for (int i = lastnum + 1; i <= n; i++)
        {
            ans *= i;
            ans %= M;
            aans *= ans;
            aans %= M;
            vis[i - 100] = (int)aans;
        }
        last = ans;
        lasta = aans;
        lastnum = n;
        printf("%lld\n", aans);
    }
    return 0;
}
