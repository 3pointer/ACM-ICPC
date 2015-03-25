#include <stdio.h>
#include <string.h>
#define N 10000
#define INF 0x3f3f3f3f
#define shift 10000

int a[22];
int dp[N];

inline int min(int a, int b)
{
    return a < b? a : b;
}
int main()
{
    int t;
    int n;
    int tar;
    scanf("%d", &t);
    while(t --)
    {
        memset(dp, INF, sizeof(dp));
        scanf("%d %d", &n, &tar);
        int ans = tar;
        int sum = 16 * shift;
        for (int i = 0; i < n; i ++)
            scanf("%d", &a[i]), sum += a[i], a[i] += shift;

        dp[0] = 0;
        for (int i = 0; i < n; i ++)
            for (int j = a[i]; j <= sum; j ++)
                    dp[j%shift] = min(dp[j%shift],dp[(j - a[i])%shift] + 1);
        while(dp[tar] == INF)
            tar ++;
        printf("%d %d\n", dp[tar], tar - ans);
    }
    

    return 0;
}
