#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

#define M 1000000007

long long dp[60][60];

int g(int i)
{
    return (int)pow(2, i) - 1;
}
int main()
{
    int n, m;
    dp[0][0] = dp[0][1] = dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 1; i <= 60; i ++)
        dp[i][1] = dp[1][i] = 1;
    for (int i = 2; i <= 55; i ++)
        for (int j = i; j <= 55; j++)
           dp[j][i] =  dp[i][j] = ((dp[i - 1][j] + dp[i][j - 1]) * g(i) + 1)%M;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        cout<<dp[n][m]<<endl;
    }
    return 0;
}
