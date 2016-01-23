#include<bits/stdc++.h>

const int N = 1011;
using namespace std;
int a[N];

int main(){
    int xn, xm, yn, ym;
    cin >> xn >> xm;
    int x;
    long long ans1 = 0;
    for (int i = 0; i < xn; i ++){
        cin >> a[i];
    }

    x = 1;
    for (int i = xn - 1; i >= 0; i --){
        ans1 += x * a[i];
        x *= xm;
    }
    //cout << ans1 << endl;
    cin >> xn >> xm;
    long long ans2 = 0;
    for (int i = 0; i < xn; i ++){
        cin >> a[i];
    }

    x = 1;
    for (int i = xn - 1; i >= 0; i --){
        ans2 += x * a[i];
        x *= xm;
    }

    //cout << ans2 << endl;
    if (ans1 == ans2){
        puts("=");
    } else if (ans1 > ans2){
        puts(">");
    } else {
        puts("<");
    }



    return 0;
}
