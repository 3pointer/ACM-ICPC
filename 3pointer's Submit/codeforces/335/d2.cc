#include<algorithm>
#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

const int N = 100010;


pair<int, int>  q[N];
pair<int, int>  ans[N];
pair<pair<int, int>, int > e[N];

int main(){

    int n, m;
    int a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i ++){
        scanf("%d%d", &a, &b);
        e[i] = {{a, -b}, i};
    }

    sort(e, e+m);

    int cur = 0;
    int t = 0;
    int h = 0;
    for (int i = 0; i < m; i ++){
        int ti = e[i].second;
        int tmp = e[i].first.second;
        if (tmp == -1){
            ans[ti] = {0, ++ cur};
            if (t < n){
                for (int j = 1; j < cur; j ++){
                    q[t ++] = {j, cur};
                }
            }
        } else {
            if (h == t){
                cout << -1 << endl;
                return 0;
            }
            ans[ti] = q[h ++];
        }
    }
    for (int i = 0; i < m; i ++){
        printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
    }
    return 0;
}
