#include<bits/stdc++.h>

using namespace std;

const int N = 100010;
int a[N];
int d[N];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i ++){
        d[a[i]] = d[a[i] - 1] + 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++){
        ans = max(d[i], ans);
    }
    cout << n - ans << endl;
    return 0;
}
