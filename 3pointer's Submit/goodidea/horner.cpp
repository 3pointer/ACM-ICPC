/*************************************************************************
	> File Name: horner.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年05月10日 星期日 20时22分49秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define N 1000
int horner(int a[], int x, int n){
    int v1 = a[n];
    for (int i = n - 1; i >= 0; i --){
        int v2 = v1 * x + a[i];
        v1 = v2;
    }
    return v1;
}

int main(){


    return 0;
}

