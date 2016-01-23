#include<bits/stdc++.h>
using namespace std;
#define N 60

int dp[N][2];
int b[N];
int a[N];

int main(){
    int n;
    cin >> n;
    for (int i = 2 ; i <= n; i ++){
        cin >> dp[i][0];
        dp[i][0] += dp[i - 1][0];
    }

    for (int i = 2; i <= n; i ++){
        cin >> dp[i][1];
        dp[i][1] += dp[i - 1][1];
    }

    for (int i = 1; i <= n; i ++){
        cin >> b[i];
    }


    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j < i; j ++){
            int tmp = 0;
            tmp += dp[i][0] + dp[j][0];
            tmp += dp[n][1] - dp[i][1] + dp[n][1] - dp[j][1];
            tmp += b[i] + b[j];
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;

    return 0;
}
