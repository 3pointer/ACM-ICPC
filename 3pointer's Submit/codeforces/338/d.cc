#include<bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;
const int N = 200010;
int p[N];
int a[N];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++){
        scanf("%d", &a[i]);
        p[a[i]] ++;
    }
    long long ans = 1;
    for (int i = 0; i < n; i ++){
        ans *= a[i]


    }


    return 0;
}
