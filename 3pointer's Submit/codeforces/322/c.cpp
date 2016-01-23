/*************************************************************************
	> File Name: c.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年09月28日 星期一 17时30分09秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define N 110010

int a[N];

int cmp(const int & x, const int & y){
    return (x % 10) > (y % 10);
}

int main(){
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i ++){
        scanf("%d", &a[i]);
    }
    sort(a, a + n, cmp);

    for (int i = 0; i < n; i ++){
        int cut = 10 - a[i] % 10;
        if (cut <= k){
            a[i] += cut;
            k -= cut;
        } else {
            break;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i ++){
        int cut = 100 - a[i];
            ans += cut;
    }

    if (ans > k){
        ans = k - k % 10;
    }

    int sum = 0;
    for (int i = 0; i < n ; i ++){
        sum += a[i] / 10;
    }
    cout << sum + ans / 10 << endl;
    return 0;
}
