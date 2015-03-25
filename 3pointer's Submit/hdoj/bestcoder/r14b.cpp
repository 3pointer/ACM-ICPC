#include <stdio.h>
int a[100][100];
int ma;
int main()
{
    int n, m, x, y;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        x = 0;
        y = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &a[i][j]);
                if (a[i][j])
                {
                    if (x < i)
                        x = i;
                    if (y < j)
                        y = j;
                }
            }
        printf("%d\n", y * 2 + (x - 2)* 2);

    }
}
