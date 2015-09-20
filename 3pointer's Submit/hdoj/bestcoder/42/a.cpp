/*************************************************************************
	> File Name: a.cpp
	> Author: 3pointer
	> Mail: 
	> Created Time: 2015年05月23日 星期六 19时02分57秒
 ************************************************************************/

#include<iostream>
#include <stdio.h>
using namespace std;

int a[31][31];

int main(){
    int n;

    while(scanf("%d", &n) != EOF){
        int sum = 0;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                scanf("%d", &a[i][j]), sum += a[i][j];
        printf("%d\n", n * 2 + sum);
    }


    return 0;
}
