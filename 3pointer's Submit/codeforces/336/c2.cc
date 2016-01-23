#include<bits/stdc++.h>

using namespace std;
const int N = 100100;
pair<int, int> p[N];
int dp[N];

int main(){
    int n;

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> p[i].first >> p[i].second;
    }
    dp[1] = 1;
    sort(p + 1, p + 1 + n);
    for (int i = 2; i <= n; i ++){
        int least = p[i].first - p[i].second;
        int pos = lower_bound(p + 1, p + n + 1, make_pair(least, 0)) - p;
        cout << pos - 1 << endl;
        dp[i] = dp[pos - 1] + 1;
        cout << dp[i] << endl;
    }
    cout << n - *max_element(dp + 1, dp + 1 + n);
    return 0;
}

