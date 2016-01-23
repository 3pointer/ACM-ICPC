#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int a[N];

long long gcd(long long a, long long b){
    return b == 0 ? a : gcd(b, a % b);
}
int main(){
    long long t, w, b;
    long long ans = 0;
    cin >> t >> w >> b;

    long long g = gcd(w, b);
    long long

    cout << ans << endl;
    return 0;
}
