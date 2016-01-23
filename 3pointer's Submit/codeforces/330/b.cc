#include<bits/stdc++.h>
using namespace std;

const int N = 2000000;
const int M = 1e9+ 7;
long long a[N];
long long b[N];
long long c[N];
int main(){
    int n;
    int k;
    cin >> n >> k;
    int l = n / k;
    for (int i = 0; i < l; i ++){
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < l; i ++){
        scanf("%lld", &b[i]);
    }

    long long MOD = 1;
    for (int i = 0; i < k; i ++){
        MOD *= 10;
    }

    for (int i = 0; i < l; i ++){
        c[i] = MOD / a[i] + 1;
        for (int k = 1; k <= MOD / 10; k *= 10){
            c[i] -= ((b[i] + 1) * k / a[i] - (b[i]) * k / a[i]);
            if ((b[i] * k) % a[i] == 0)
                c[i] --;
            if (((b[i] + 1) * k) % a[i] == 0)
                c[i] ++;
            }
        }
    long long ans = 1;
    for (int i = 0 ; i < l; i ++){
        cout << c[i] << endl;
        ans = (ans * c[i]) % M;
    }
    cout << ans << endl;

    return 0;
}
