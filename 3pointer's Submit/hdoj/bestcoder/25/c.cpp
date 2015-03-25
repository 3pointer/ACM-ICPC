#include <stdio.h>
#include <string.h>
#define N 50001
#define M 150001

struct node
{
    int to, next;
}e[M];
int head[N];
int tot;
int dp[N];
int val[N];
int vis[N];

void init()
{
    memset(val, 0, sizeof(val));
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    memset(head, -1, sizeof(head));
    tot = 0;
}

void addedge(int a, int b)
{
    e[tot].to = b;
    e[tot].next = head[a];
    head[a] = tot ++;
}

void f(int x)
{
    vis[x] = 1;
    if (val[x] != 0)
        dp[x] ++;
    for (int i = head[x]; i != -1; i = e[i].next)
    {
        int v = e[i].to;
        if (!vis[v])
        {
            f(v);
            dp[x] += dp[v];
        }
    }
}

int main()
{
    int n, m;
    int a, b;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        init();
        for (int i = 1; i < n; i++) 
        {
            scanf("%d%d", &a, &b);
            addedge(a, b);
            addedge(b, a);
        }
        while(m --)
        {
            scanf("%d %d", &a, &b);
            val[a] = b;
        }
        f(1);
        for (int i = 1; i <= n; i ++)
            printf("%d ", dp[i]);
    }
    return 0;
}
