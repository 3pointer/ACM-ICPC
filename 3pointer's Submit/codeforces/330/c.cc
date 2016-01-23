#include<bits/stdc++.h>
using namespace std;

int a[200100];
long long sum[200100];
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
    }

    sort(a + 1, a + n + 1);
    int l = n - 2;
    int v = (n - 2) % 2 + (n - 2) / 2;
    int u = l - v;

    for (int i = 1; i <= n; i ++){
        sum[i] = sum[i - 1] + a[i];
    }

    int le = 1;
    int ri = n;
    for (int i = 0; i < v; i ++){
        if (sum[ri] - sum[ri - 1] > sum[le + 1] - sum[le]){
            ri --;
        } else {
            le ++;
        }
    }

    cout << sum[ri] - sum[le] <<endl;

    return 0;
}
