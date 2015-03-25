#include <stdio.h>
#include <math.h>

int ans = 100000000;
int n;

void dfs(int m, int posr, int posh, int s, int v)
{
    if (s + (2 * (n - v) * 1.0 / posr) >= ans)
        return;
    if (v > n)
        return;
    if (m > 0 && posh == 0)
        return;
    if (m > 0 && posr == 0)
        return;
    if (m == 0 && v != n)
        return;
    if (m == 0 && v == n)
    {
        if (ans > s)
            ans = s;
        return;
    }
    for (int i = posr; i >= m; i --)
        for (int j = posh; j >= m; j --)
            dfs(m - 1, i - 1, j - 1, s + 2 * i * j, v + i * i * j);
}

int main()
{
    int m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        ans = 100000000;
        for (int i = sqrt(n); i >= m; i --)
        {
            for (int j = n * 1.0 / (i * i); j >= m; j --)
            dfs(m - 1, i - 1, j - 1, 2 * i * (i + j) - i * i, i * i * j);
        }
        if (ans == 100000000)
            printf("0\n");
        else 
            printf("%d\n", ans);
    }
}
