#include<bits/stdc++.h>

using namespace std;

const int N = 100010;
int du[N];
vector<pair<int, int> >v;
int vis[N];
long long ans;
long long dp[N];

//void dfs(int x, int pre,  int cur){
//    ans = max(ans, cur * du[x]);
//
//    for (auto i = 0; i < v[x].size(); i ++){
//        int to = v[x][i];
//        if (to < x){
//            continue;
//        }
//        dfs(to, x, cur + 1);
//    }
//}

int main(){
    int a, b;
    int n;
    int m;
    cin >> n;
    cin >> m;
    while(m --){
        scanf("%d%d", &a, &b);
        if (a > b)
            swap(a, b);
        v.push_back(make_pair(a, b));
        du[a] ++;
        du[b] ++;
    }
    sort(v.begin(), v.end());
    for (auto i = v.begin(); i != v.end(); i ++){
        //cout << i -> second << " " << i -> first << endl;
        dp[i->second] = max(dp[i->second], dp[i->first] + 1);
    }
    for (int i = 1; i <= n; i ++){
        ans = max(ans, dp[i] * du[i] + du[i]);
    }
    cout << ans;

    return 0;
}
