#include<bits/stdc++.h>
using namespace std;

const int N = 2000000;
const int M = 1e9+ 7;
int a[N];
int b[N];
int c[N];
int main(){
    int n;
    int k;
    cin >> n >> k;
    int l = n / k;
    for (int i = 0; i < l; i ++){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < l; i ++){
        scanf("%d", &b[i]);
    }

    int MOD = 1;
    for (int i = 0; i < k; i ++){
        MOD *= 10;
    }

    for (int i = 0; i < l; i ++){
        c[i] = (MOD - 1) / a[i] + 1;
        c[i] -= ((b[i] + 1) * MOD / 10 / a[i] - (b[i]) * MOD / 10 / a[i]);
        if ((b[i] * MOD / 10) % a[i] == 0){
            c[i] --;
        }
        if (((b[i] + 1) * MOD / 10) % a[i] == 0){
            c[i] ++;
        }
    }
    long long ans = 1;
    for (int i = 0 ; i < l; i ++){
        ans = (ans * c[i]) % M;
    }
    cout << ans << endl;

    return 0;
}
