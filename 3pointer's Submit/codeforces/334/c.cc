#include<bits/stdc++.h>

using namespace std;

const int N = 100100;
int a[N];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++){
        scanf("%1d", &a[i]);
    }

    int flag = a[0];
    int len = 1;
    for (int i = 1; i < n; i ++){
        if (a[i] != flag){
            flag = !flag;
            len ++;
        }
    }
    cout << min(n, len + 2) << endl;

    return 0;
}
