/*************************************************************************
	> File Name: 372A.cpp
	> Author: 3pointer
	> Mail: 
	> Created Time: 2015年08月20日 星期四 09时09分09秒
 ************************************************************************/

#include<iostream>
#include <cstdio>
#include<algorithm>
using namespace std;
#define N 1001000

int a[N];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }

    sort(a, a + n);

    int ans = n;
    int mi = n / 2;
    for (int i = 0; i < n / 2; i ++){
        while(mi < n){
            if (a[i] * 2 <= a[mi]){
                //cout <<"******"<<a[i] << "***"<<  a[mi] << endl;
                ans --;
                mi ++;
                break;
            }
            else{
                mi ++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}

