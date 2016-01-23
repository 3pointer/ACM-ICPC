#include<bits/stdc++.h>

using namespace std;
const int N = 1001011;
int a[N];
int dp[N];

int main(){
    int n;

    cin >> n;
    for (int i = 0; i < n; i ++){
        scanf("%d", &a[i]);
    }

    int len = 0;
    int lm = 0, rm = 0;
    int mmin = a[0];
    int mmax = a[0];

    dp[0] = 1;

    for (int i = 1; i < n; i ++){
        if (mmin >= a[i]){
            mmin = a[i];
            lm = i;
        }
        if (mmax <= a[i]){
            mmax = a[i];
            rm = i;
        }
        if (mmax - mmin <= 1){
            dp[i] = dp[i - 1] + 1;
        } else if (i == rm){
            dp[i] = rm - lm;
            mmin = a[rm - 1];
            lm = rm - 1;
        } else if (i == lm){
            dp[i] = lm - rm;
            mmax = a[lm - 1];
            rm = lm - 1;
        }
    }
    for (int i = 0; i < n; i ++){
        cout << dp[i] << "\t";
        len = max(len, dp[i]);
    }
    cout << len << endl;
    return 0;
}
