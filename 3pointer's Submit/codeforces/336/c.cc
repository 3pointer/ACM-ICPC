#include<bits/stdc++.h>

using namespace std;

const int N = 1000100;

int a[N];
int b[N];

pair<int, int> v[N];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++){
        scanf("%d", &a[i]);
        scanf("%d", &b[i]);
        v[i] = make_pair(a[i], b[i]);
    }

    if (n == 1){
        cout << 0 << endl;
        return 0;
    }

    sort(v, v + n);

    int ans = 0;
    int tmp = v[n - 1].first - v[n - 1].second;
    for (int i = n - 2; i >= 0; i --){
        if (v[i].first >= tmp){
            ans ++;
        }
        else {
            tmp = min(tmp, v[i].first - v[i].second);
        }
    }
    int ans2 = 1;
    tmp = v[n - 2].first - v[n - 2].second;
    for (int i = n - 3; i >= 0; i --){
        if (v[i].first >= tmp){
            ans2 ++;
        }
        else {
            tmp = min(tmp, v[i].first - v[i].second);
        }
    }
    cout << min(ans, ans2) << endl;

    return 0;
}

