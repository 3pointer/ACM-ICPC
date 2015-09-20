#include <stdio.h>
#include <string.h>

const int max(int a, int b){
    return  a > b ? a : b;
}

int a[200][200];
int dp[200][200][200];
int n, m, k;
int ans;

int main(){
    while(scanf("%d%d%d", &n, &m, &k) != EOF){
        memset(dp, 0, sizeof(dp));
        ans = 0;
        for (int i = 1; i <= n; i ++){
            for (int j = 1; j <= m; j ++){
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = 1; i <= n; i ++){
            for (int j = 1; j <= m; j ++){
                for (int x = k; x >= 0; x --){
                    dp[i][j][x] = max(dp[i][j-1][x], dp[i-1][j][x]);
                    if (x >= a[i][j])
                        dp[i][j][x] = max(dp[i][j][x], max(dp[i-1][j][x-a[i][j]] + a[i][j], dp[i][j-1][x-a[i][j]] + a[i][j]));
                    ans = max(ans, dp[i][j][x]);
                }
            }
        }
            //ans = max(ans, dp[n][m][x]);
        printf("%d\n", ans);
    }
    return 0;
}
