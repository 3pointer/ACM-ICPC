#include <stdio.h>
int dp[40003];
int main()
{
    int n, m;
    int id;
    int f;
    int lnum = 0;
    int rnum = 0;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        lnum = rnum = 0;
        f = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &dp[i]);
            if (dp[i] == m)
                id = i;
        }
        for (int i = id; i >= 1; i --)
        {
            if (dp[i] > dp[id])
                f ++;
            if (dp[i] < dp[id])
                f --;
            if (f == 0)
               lnum ++; 
        }
        f = 0;
        for (int i = id; i <= n; i ++)
        {
            if (dp[i] > dp[id])
                f ++;
            if (dp[i] < dp[id])
                f --;
            if (f == 0)
               rnum ++; 
        }
        printf("%d\n",);
    }
}

