#include<bits/stdc++.h>

using namespace std;

const int N = 500100;

string a, b;
int v[N];
int main(){

    cin >> a;
    cin >> b;

    int lena = a.length();

    int lenb = b.length();

    int tmp = 0;
    int cnt = 0;

    int x = lenb - lena + 1;

    for (int i = 0; i < x; i ++){
        tmp += b[i] - '0';
    }
    v[0] = tmp;
    for (int i = x; i < lenb; i ++){
        tmp = v[cnt];
        ++cnt;
        tmp += b[i] - '0';
        tmp -= b[i - x] - '0';
        v[cnt] = tmp;
    }

    long long ans = 0;
    for (int i = 0; i < lena; i ++){
        if (a[i] == '0'){
            ans += v[i];
        } else {
            ans += x - v[i];
        }
    }
    cout << ans << endl;

    return 0;
}

