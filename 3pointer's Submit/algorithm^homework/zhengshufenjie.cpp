#include <stdio.h>
#include <string.h>

bool a[100000000];
int p[10000000];
int vis[100000];
int tot;
int sum;


int main()
{
    a[0] = 1;
    a[1] = 0;
    for (int i = 2; i <= 100000000; i++)
    {
        if (a[i] == 0)
            p[tot ++] = i;
        for (int j = 0; j < tot && p[j] * i <= 100000000; j++)
        {
            a[p[j] * i] = 1;
            if (i % p[j] == 0)
                break;
        }
    }
    printf("%d\n", p[tot - 1]);
    int n;
    int cou;
    int i;
    while(scanf("%d", &n) != EOF)
    {
        cou = 0;
        memset(vis, 0, sizeof(vis));
        while(n >= 50000 || a[n] == 1) 
        {
            for (i = 0; i < tot; i++)
            {
                if (n < p[i])
                    break;
                if (n % p[i] == 0)
                {
                    while (n % p[i] == 0)
                    {
                        vis[cou] ++;
                        n /= p[i];
                    }
                    sum += vis[cou];
                    cou++;
                }
            }
        }
        for (int i = 0; i < cou; i++)
            printf("%d\t",vis[i]);
        printf("%d\n", sum);
    }
    return 0;
}
