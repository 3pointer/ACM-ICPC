#include<bits/stdc++.h>
using namespace std;

int a[200][300];
int main(){
    int n;
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m * 2; j ++){
            scanf("%d", &a[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m * 2; j += 2){
            if (a[i][j] + a[i][j + 1])
                ans ++;
        }
    }
    cout << ans << endl;


    return 0;
}
