#include<stdio.h>
#include <stdlib.h>
#include<iostream>
#include <string.h>
using namespace std;

int a[200][200];
int dp[200][200][2];
int n, m, k;
int ans;

bool ok(int x, int y){
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}
int dfs(int x, int y, int state, int sum){
    if (sum > k){
        return 0;
    }
    dp[x][y][state] = max(dp[x][y][state],sum);

    if (ok(x - 1, y)){
        dfs(x - 1, y, 1, sum + a[x - 1][y]);
        dfs(x - 1, y, 0, sum);
        
    }
    if (ok(x, y - 1)){
        dfs(x, y - 1, 1, sum + a[x][y - 1]);
        dfs(x, y - 1, 0, sum);
    }
    return 0;
}
int dfs2(int x, int y, int state, int sum){
    if (dp[x][y][state] != -1){
        return dp[x][y][state];
    }
    if (sum > k){
        return 0;
    }
    if (x == n && y == m){
        ans = max(ans, sum);
        return 0;
    }

    if (ok(x + 1, y)){
        dfs(x + 1, y, 1, sum + a[x + 1][y]);
        dfs(x + 1, y, 0, sum);
        
    }
    if (ok(x, y + 1)){
        dfs(x, y + 1, 1, sum + a[x][y + 1]);
        dfs(x, y + 1, 0, sum);
    }
    return 0;
}
int main(){
    while(scanf("%d%d%d", &n, &m, &k) != EOF){
        memset(dp, -1, sizeof(dp));
        ans = 0;
        for (int i = 1; i <= n; i ++){
            for (int j = 1; j <= m; j ++){
                scanf("%d", &a[i][j]);
            }
        }
        dfs(n, m, 0, 0);
        dfs(n, m, 1, a[n][m]);
        int ans1 = dfs2(1, 1, 0, 0);
        int ans2 = dfs2(1, 1, 1, a[1][1]);
        printf("%d\n", max(ans1, ans2));
        
    }
    return 0;
}
