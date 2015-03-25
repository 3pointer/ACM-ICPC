#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
#define N 22

double d[N+10][N+10];
int t[N];
int n, m, p, a, b;
double dp[1 << N][N];
inline double min(double a, double b)
{
    return a < b ? a : b;
}
void init()
{
    memset(d, -1, sizeof(d));
    for (int i = 0; i < (1 << n); i ++)
        for (int j = 0; j < m; j ++)
            dp[i][j] = INF;
    dp[(1 << n) - 1][a - 1] = 0;
}

int main()
{
    int x, y;
    double z;
    while(scanf("%d%d%d%d%d", &n, &m, &p, &a, &b) && a + b + p + m + n)
    {
        init();
        for (int i = 0; i < n; i ++)
            scanf("%d", &t[i]);
        while(p --)
        {
            scanf("%d%d%lf", &x, &y, &z);
            x--;
            y--;
            d[x][y] = d[y][x] = z;
        }
        double res = INF;
        //for (int i = 0; i < (1 << n); i ++)
        for (int i = (1 << n) - 1; i >= 0; i --)
        {
            res = min(res, dp[i][b - 1]);
            for (int j = 0; j < m; j ++)
            {
                for (int k = 0; k < n; k ++)
                {
                    if (i >> k & 1)
                    {
                        for (int jj = 0; jj < m; jj ++)
                            if (d[j][jj] >= 0)
                                dp[i & ~(1 << k)][jj] = min(dp[i & ~(1 << k)][jj], dp[i][j] + (double)(d[j][jj] * 1.0/t[k]));
                    }
                }
            }
        }
        if (res == INF)
            printf("Impossible\n");
        else
            printf("%.3f\n", res);
    }
    return 0;
}
