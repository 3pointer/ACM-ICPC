#include<stdio.h>
#define M 1000000007
int vis[1000001];
int vis2[1000001];

int main()
{
    int n;
    long long ans;
    long long aans;
    long long last = 1;
    long long lasta = 1;
    int toti = 1;
    ans = last;
    aans = lasta;
    vis2[0] = vis[0] = 1;
    for (int i = 1; i <= 10000000; i++)
    {
        ans *= i;
        ans %= M;
        aans *= ans;
        aans %= M;
        if (i % 100 == 0)
        {
            vis2[toti] = (int) ans;
            vis[toti++] = (int)aans;
        }
    }
    while(scanf("%d", &n) != EOF)
    {
    int z = n / 100;
    ans = vis2[z];
    aans = vis[z];
    for (int i = z * 100 + 1; i <= n; i++)
    {
        ans *= i;
        ans %= M;
        aans *= ans;
        aans %= M;
    }
    printf("%d\n", (int)aans);
    }
return 0;

}
