#include <stdio.h>
#define M 1000000007
#define N 64

long long dp[N][N];

int main()
{
    dp[0][0] = dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i < N; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j <= i; j++)
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
    }

    return 0;
}
