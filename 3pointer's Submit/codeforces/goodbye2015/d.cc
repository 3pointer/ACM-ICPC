#include<bits/stdc++.h>

using namespace std;

const int N = 5555;

char s[N];
int f[N][N];
int dp[N][N];

int main(){
    int n;
    cin >> n;
    scanf("%s", s);

    for (int i = n; i >= 0; i --){
        for (int j = n; j >= 0; j --){
            if (i == n || j == n) f[i][j] = 0;
            else if (s[i] == s[j]) f[i][j] = f[i + 1][j + 1] + 1;
            else f[i][j] = 0;
        }
    }

    for (int i = 0; i <= n; i ++){
        for (int j = 0; j <= n; j ++){
            printf("%d\t", f[i][j]);
        }
        cout << endl;
    }

    cout << s << endl;


    return 0;
}
