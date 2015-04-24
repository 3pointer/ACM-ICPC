#include<iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
#define N 10

int dp[N][2];
int digit[N];

int dfs(int len, bool state, bool fp){
    if (!len)
        return 1;
    if (!fp && dp[len][state] != -1)
        return dp[len][state];
    int ret = 0;
    int fpmax = fp ? digit[len] : 9;
    for (int i = 0; i <= fpmax; i ++){
        if (i == 4 || state && i == 2){
            continue;
        }
        ret += dfs(len - 1, i == 6, fp && i == fpmax);
    }
    if (!fp)
        dp[len][state] = ret;
    return ret;
    
}
int f(int x){
    int len = 0;
    while(x){
        digit[++ len] = x % 10;
        x /= 10;
    }
    return dfs(len, false, true);
}

int main(){
    int n, b, a;
    scanf("%d", &n);
    while(n --){
        memset(dp, -1, sizeof(dp));
        scanf("%d%d", &a, &b);
        printf("%d\n", f(b) - f(a));
    }
    return 0;
}
