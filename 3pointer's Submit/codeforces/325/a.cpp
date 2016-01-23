#include<bits/stdc++.h>
using namespace std;
#define N 111
int a[N];
int main(){

    int n;
    cin >> n;
    int s = -1, e = 0;

    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i ++){
        if (a[i] == 1){
            s = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i --){
        if (a[i] == 1){
            e = i;
            break;
        }
    }
    if (s == -1){
        cout << a[0] << endl;
        return 0;
    }

    int ans = e - s + 1;
    int flag = 0;
    for (int i = s + 1; i <=e; i ++){
        if (a[i] == 0 && a[i - 1] == 0){
            ans --;
            flag = 1;
        }
        if (a[i] == 1){
            if (flag == 1)
                ans --;
            flag = 0;
        }
    }
    cout << ans << endl;

    return 0;
}
