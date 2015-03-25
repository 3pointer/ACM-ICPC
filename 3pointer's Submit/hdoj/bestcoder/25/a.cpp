#include <stdio.h>
#include <string.h>
#define N 500
#define M 150001

int tot;
int val[N];
int vis[N];
bool ma[N][N];

int main()
{
    int n, m;
    int a, b;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        memset(ma, false, sizeof(ma));
        while(m --)
        {
            scanf("%d%d", &a, &b);
            ma[b][a] = true;
        }
        for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
        {
            ma[i][j] |= ma[i][k] * ma[k][j];
        }
        int flag = 0;
        for (int i = 1; i <= n; i ++)
            if (ma[i][i] == 1)
                flag = 1;
        if (flag == 1)
            puts("NO");
        else
            puts("YES");
    }
    return 0;
}
