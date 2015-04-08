/*************************************************************************
	> File Name: c.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年04月01日 星期三 16时21分04秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n;
int a[10];

int main(){
    cin >> n;
    for (int i = 0; i < n; i ++)
        cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n; i ++){
        ans = ans ^ a[i];
    }
    int t = 1;
    while(!(t & ans)){
        t <<= 1;
    }

    int p = 0;
    int q = 0;

    for (int i = 0; i < n; i ++){
        if (a[i] & t){
            p ^= a[i];
        }else {
            q ^= a[i];
        }
    }
    cout << q * p << endl;
 
    return 0;
}
