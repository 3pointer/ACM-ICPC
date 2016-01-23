#include<bits/stdc++.h>

using namespace std;

long long ans;
long long a, b;

void dfs(long long x, long long cnt){
    if (x > b){
        return ;
    }

    if (a <= x && x <= b && cnt == 1)
        ans ++;

    if (cnt == 0){
        dfs(x * 2, cnt + 1);
    }
    dfs(x * 2 + 1, cnt);
}

int main(){
    cin >> a >> b;
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
