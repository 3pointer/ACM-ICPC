
#include<iostream>
using namespace std;
#include <string.h>
#include <stdio.h>
#define N 3000

int dp[N];
int up[N];
long long ans;
char s[N];
int top;
int stack[N];

int push(int i){
    while(top && up[stack[top - 1]] >= up[i]){
        top --;
    }
    stack[top ++] = i;
    if (top > 1)
        return stack[top - 2];
    return 0;
}

int main(){

    int n, m;
    int cou;

    while(scanf("%d%d", &n, &m) != EOF){
        ans = 0;
        memset(up, 0, sizeof(up));

        while(n --){
            scanf("%s", s + 1);
            dp[0] = 0;
            top = 0;

            for (int i = 1; i <= m; i ++){
                if (s[i] =='w'){
                    up[i] ++;
                } else {
                    up[i] = 0;
                }
                cou = push(i);
                dp[i] = dp[cou] + (i - cou) * up[i];
                ans += dp[i];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
