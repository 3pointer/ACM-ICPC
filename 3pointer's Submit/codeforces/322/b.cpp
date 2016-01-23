/*************************************************************************
	> File Name: b.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年09月28日 星期一 17时06分48秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
#define N 200010

int a[N];
int b[N];

int main(){

    int n;
    cin >> n;
    for (int i = 0; i < n; i ++){
        scanf("%d", &a[i]);
    }
    int maxx = a[n - 1];
    int i = n - 1;
    b[n - 1] = 0;
    while(--i >= 0){ 
        maxx = max(maxx, a[i + 1]);
        b[i] = max(0, maxx + 1 - a[i]);
    }
    b[0] = max(0,maxx + 1  - a[0]);

    if (n == 1)
        b[0] = 0;
    for (i = 0; i < n; i ++){
        printf("%d ", b[i]);
    }
    cout << endl;

    return 0;
}
