#include<bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N];

int main(){
    int n;
    int k;
    cin >> n >> k;


    int sum = 0;
    for (int i = 0; i < n; i ++){
        scanf("%d", &a[i]);
        sum += a[i];
    }

    if (n == 1){
        cout << a[0] << endl;
        return 0;
    }
    if (n <= k){
        cout << a[n - 1] << endl;
        return 0;
    }

    int ans = 0;

    while(k > n / 2){
        ans = max(ans, a[n - 1]);
        sum -= a[n - 1];
        n --;
        k --;
    }
    int res = 0;
    int len = 0;
    int tmp = sum / k;
    for (int i = 0; i < n; i ++){
        if (res + a[i] < tmp){
            res += a[i];
            len ++;
        }
    }
    if (n - len <= k - 1){
        cout << a[n - 1] << endl;
        return 0;
    }

    for (int i = 2; i < len; i ++){
        ans = max(ans, a[n - 1]);
        n --;
    }
    sum = 0;
    for (int i = len ; i < n; i ++){
        sum += a[i];
    }


    cout << max(ans , min(sum, res + a[len])) << endl;
    return 0;
}
