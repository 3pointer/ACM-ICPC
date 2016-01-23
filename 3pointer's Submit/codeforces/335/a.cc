#include<bits/stdc++.h>
using namespace std;

const int N = 1001;
int main(){
    int ans = 0;
    int a, b, c;
    int x, y, z;
    int ta, tb, tc;
    cin >> a >> b >> c;
    cin >> x >> y >> z;
    ta = a - x;
    tb = b - y;
    tc = c - z;
    if (ta > 0)
        ans += ta / 2;
    if (tb > 0){
        ans += tb / 2;
    }
    if (tc > 0){
        ans += tc / 2;
    }

    //cout << ta << tb << tc;

    if (ta < 0 || tb < 0 || tc < 0){
        int tmp = ta + tb + tc + ans;
        printf("%d", tmp);
    }
    if (ans >= 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
