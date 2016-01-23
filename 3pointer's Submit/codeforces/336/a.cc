#include<bits/stdc++.h>

using namespace std;
const int N = 10001;

int a[N];
int b[N];

struct node{
    int f, s;
}no[N];

int cmp(const node & a, const node  b){
    if (a.f == b.f){
        return a.s > b.s;
    }
    return a.f > b.f;
}

int main(){
    int n;
    int s;
    cin >> n >> s;
    for (int i = 0; i < n; i ++){
        cin >> a[i] >> b[i];
        no[i].f = a[i];
        no[i].s = b[i];
    }

    sort(no, no + n, cmp);
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n - i - 1; j ++){
            if (a[j] < a[j + 1]){
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                tmp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = tmp;
            }
        }
    }

    int ans = 0;
    ans += s - no[0].f;
    int tmp = ans;
    ans += (no[0].s - tmp > 0) ? no[0].s - tmp : 0;
    tmp = ans;
    for (int i = 1; i < n; i ++){
        ans += no[i - 1].f - no[i].f;
        tmp = ans;
        ans += (no[i].s - tmp > 0) ? no[i].s - tmp : 0;
        tmp = ans;
        //cout << " ans " << ans << endl;
    }
    cout << ans + no[n - 1].f << endl;
    return 0;
}
