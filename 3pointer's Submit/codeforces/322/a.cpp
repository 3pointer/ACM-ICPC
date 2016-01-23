/*************************************************************************
	> File Name: a.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年09月28日 星期一 16时52分08秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a, b;
int main(){
    cin >> a >> b;
    int maxx = max(a, b);
    int minn = min(a, b);
    cout << minn << " " << (maxx - minn) / 2 << endl;
    return 0;
}
