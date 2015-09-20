/*************************************************************************
> File Name: b.cpp
> Author: 
> Mail: 
> Created Time: 2015年09月19日 星期六 19时09分59秒
************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;
#define N 1010
#define M 1000000007

int a[N];
int dp[N][N];
int main(){
    int t;
    cin >> t;
    int n, p;
    while(t --){
        cin >> n >> p;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i ++){
            cin >> a[i];
            if (a[i] > 0)
                a[i] %= p;
            else 
                a[i] = a[i] % p + p; //mod p 构成群
        }
        dp[0][0] = 1;
        for (int i = 1; i <= n; i ++){
            for (int j = 0; j < p; j ++){
                if (a[i] <= j)
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - a[i]]) % M;
                else
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - a[i] + p]) % M;
            }
        }
        cout << dp[n][0] << endl;
    }
    return 0;
}
