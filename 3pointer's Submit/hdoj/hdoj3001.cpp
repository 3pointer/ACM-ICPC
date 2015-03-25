#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f

int p[200000];
int matp[20][20];
int dp[200000][12];
int vis[200000][12];
int n, m;

inline int min(int a, int b)
{
    return a < b ? a : b;
}
void initial()
{
    p[0] = 1;
    for (int i = 1; i <= 11; i ++)
        p[i] = p[i - 1] * 3;
    for (int i = 0; i <= p[11]; i ++)
    {
        int t = i;
        for (int j = 0; j < 10; j ++)
        {
            vis[i][j] = t % 3;
            t /= 3;
        }
    }
}

void init()
{
    memset(matp, INF, sizeof(matp));
    memset(dp, INF, sizeof(dp));
    for (int i = 0; i < n; i++) {
        dp[p[i]][i] = 0;
    }
}
int main()
{
    int a, b, c;
    int ans;
    initial();
    while(scanf("%d%d", &n, &m) != EOF)
    {
        ans = INF;
        init();
        while(m --)
        {
            scanf("%d%d%d", &a, &b, &c);
            a--, b--;
            if (c < matp[a][b])
                matp[a][b] = matp[b][a] = c;
        }
        for (int i = 0; i < p[n]; i++)
        {
            bool flag = 1;
            for (int j = 0; j < n; j++)
            {
                if (vis[i][j] == 0)
                    flag = 0;
                if (dp[i][j] == INF)
                    continue;
                for (int k = 0; k < n; k++)
                {
                    if (vis[i][k] >= 2)
                        continue;
                    if (matp[j][k] == INF)
                        continue;
                    dp[i + p[k]][k] = min(dp[i + p[k]][k], dp[i][j] + matp[j][k]);
                }
            }
            if (flag)
                for (int t = 0; t < n; t++)
                    ans = min(ans, dp[i][t]);
        }
        if (ans == INF)
            printf("-1\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
