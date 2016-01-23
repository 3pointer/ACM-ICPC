#include<bits/stdc++.h>
using namespace std;

int num[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int nsum[10];
int psum[10];

long long fun(int x){

    long long ans = 0;
    while(x){
        int tmp = x % 10;
        ans += num[tmp];
        x /= 10;
    }
    return ans;
}
int main(){
    int a, b;
    cin >> a >> b;

    psum[0] = num[0];
    for (int i = 1; i < 10; i ++){
        psum[i] = psum[i - 1] + num[i];
    }

    nsum[9] = num[9];
    for (int i = 8; i >= 0; i --){
        nsum[i] = nsum[i + 1] + num[i];
    }

    long long ans = 0;
    for (int i = a; i <= b; i ++){
        ans += fun(i);
    }
    cout << ans << endl;
    return 0;
}
