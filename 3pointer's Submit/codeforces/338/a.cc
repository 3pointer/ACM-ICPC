#include<bits/stdc++.h>

using namespace std;

const int N = 10001;

int vis[N];
int main(){
    int n;
    int m;
    int a;
    int x;
    cin >> n;
    cin >> m;
    int ans = 0;

    for (int i = 0; i < n; i ++){
        scanf("%d", &a);
        for (int j = 0; j < a; j ++){
            scanf("%d", &x);
            if (vis[x] == 0){
                ans ++;
                vis[x] = 1;
            }
        }
    }
    if (ans == m){
        puts("YES");
    }
    else
        puts("NO");

    return 0;
}
