#include<bits/stdc++.h>

using namespace std;

const int N = 1001;
char s[N][N];
long long dp[N][N];
long long up[N][N];
long long ri[N][N];

int main(){
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i ++){
        scanf("%s", s[i]);
    }
    for (int i = 0; i < h; i ++){
        for (int j = 0; j < w; j ++){
            if (s[i][j] == '.'){
                if (i >= 1 && s[i - 1][j] == '.') dp[i][j] += dp[i - 1][j] + 1, up[i][j] = 1;
                else if (i >= 1) dp[i][j] += dp[i - 1][j];
                if (j >= 1 && s[i][j - 1] == '.') dp[i][j] += dp[i][j - 1] + 1, ri[i][j] = 1;
                else if (j >= 1) dp[i][j] += dp[i][j - 1];
            }
            if (s[i][j] == '#') {
                if (i > 0) dp[i][j] += dp[i - 1][j];
                if (j > 0) dp[i][j] += dp[i][j - 1];
            }
            if (i >= 1 && j >= 1){
                dp[i][j] -= dp[i - 1][j - 1];
            }
        }
    }
    for (int i = 0; i < h; i ++){
        for (int j = 0; j < w; j ++){
        }
    }
    for (int i = 0; i < h; i ++){
        for (int j = 1; j < w; j ++){
            ri[i][j] += ri[i][j - 1];
        }
    }

    for (int i = 1; i < h; i ++){
        for (int j = 0; j < w; j ++){
            up[i][j] += up[i - 1][j];
        }
    }
    int q;
    int r1, r2, c1, c2;
    cin >> q;
    long long ans;
    while(q --){
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        r1 --, r2 --, c1 --, c2 --;
        ans = 0;
        ans += dp[r1][c2];
        ans += dp[r2][c1];
        ans -= dp[r1][c1];
        for (int i = 0; i < c2; i ++)
            if (s[r1][i] == '.')
                ans ++;
        ans -= up[r2][c1] - up[r1][c1];
        for (int i = 0; i < r2; i ++)
            if (s[i][c2] == '.')
                ans ++;
        ans -= ri[r1][c2] - ri[r1][c1];
        ans = -ans;
        ans += dp[r2][c2];
        cout << ans << endl;
    }

    return 0;
}
