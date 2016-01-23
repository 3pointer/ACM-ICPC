#include<vector>
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

const int N = 1001;
int a[N];
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }
    vector<int> v;
    v.push_back(a[0]);
    for (int i = 0; i < n; i ++){
        int x = a[i];
        if (x > v.back()){
            v.push_back(x);
        } else {
            *lower_bound(v.begin(), v.end(), x) = x;
        }
    }
    printf("%d\n", n - v.size());

    return 0;
}
