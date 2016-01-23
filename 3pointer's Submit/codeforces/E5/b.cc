#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int ans1, ans = 0;
    int x;
    for (int i = 0; i < n; i ++){
        ans1 = 0x3f3f3f3f;
        for (int j = 0; j < m; j ++){
            scanf("%d", &x);
            ans1 = min(ans1, x);
        }
        ans = max(ans, ans1);
    }
    cout << ans ;
    return 0;
}
