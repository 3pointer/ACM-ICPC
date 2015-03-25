#include <stdio.h>
#define N 1010

int dp[N];
int cont[N];
int a[N];

int main()
{
    int t, n;
    int maxx;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]); 

        maxx = -1;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = 1;
            cont[i] = 1;
            for (int j = 1; j < i; j++)
            {
                if (a[j] < a[i])
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        cont[i] = cont[j];
                    }
                    else if (dp[j] + 1 == dp[i])
                    {
                        cont[i] += cont[j];
                    }
                }
            }
            if (maxx < dp[i])
                maxx = dp[i];
        }
        int ans = 0;
        for  (int i = 1; i <= n; i++)
            if (maxx == dp[i])
                ans += cont[i];
	    if (ans <= 0)
	        printf("%d\n", maxx);
        else if (ans > 1)
            printf("%d\n", maxx);
        else
            printf("%d\n", maxx - 1);
    }
    return 0;
}
