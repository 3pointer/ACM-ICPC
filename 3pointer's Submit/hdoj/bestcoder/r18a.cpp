#include <stdio.h>

int a[10010];
int p[3000];
int tot;
int vis[10000000];

int main()
{
    a[0] = a[1] = 1;
    for (int i = 2; i < 10000; i++)
    {
        if (a[i] == 0)
            p[tot ++ ] = i;            
        for (int j = 0; j < tot && i * p[j] <= 10000; j++)
        {
            a[p[j] * i] = 1;
            if (i % p[j] == 0)
                break;
        }
    }

    for (int i = 0; i < tot; i++) 
        for (int j = i; j < tot; j++)
            for (int k = j; k < tot; k++)
                vis[p[i] + p[j] + p[k]] ++;
    int cnt = 0;
    int n;
    scanf("%d", &n);
    for (int i = 0; p[i] <= n; i++)
    {
        for (int j = i; p[j] <= n - p[i]; j++)
        {
            int k = n - p[i] - p[j];
            if (k < p[j])
                break;
            if (a[k])
                cnt++;
        }
    }
    printf("%d\n", cnt);
    /*
    while(scanf("%d", &n) != EOF)
        printf("%d\n", vis[n]);
    */
    return 0;
}
