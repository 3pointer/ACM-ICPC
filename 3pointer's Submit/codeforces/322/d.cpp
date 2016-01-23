/*************************************************************************
	> File Name: d.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年09月28日 星期一 17时59分03秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
#define N 121

int x1, x2, x3, y1, y2, y3;
int a[N][N];

int main(){
    int flag = 0;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int max1 = max(x1, y1);
    int max2 = max(x2, y2);
    int max3 = max(x3, y3);
    int min1 = min(x1, y1);
    int min2 = min(x2, y2);
    int min3 = min(x3, y3);
    int sum1 = x1 * y1;
    int sum2 = x2 * y2;
    int sum3 = x3 * y3;
    int sum = sum1 + sum2 + sum3;
    int i;
    for (i = 1; i * i <= sum; i ++){
        if (i * i == sum){
            flag = 1;
            break;
        }
    }

    if (flag){
        if (y1 == i){
            swap(x1, y1);
        }
        if (y2 == i){
            swap(x2, y2);
        }
        if (y3 == i){
            swap(x3, y3);
        }
        if (x1 == i && x2 == i && x3 == i){
            cout << i << endl;
            for (int k = 0; k < y1; k ++){
                for (int j = 0; j < i; j ++){
                    printf("A");
                }
                printf("\n");
            }
            for (int k = 0; k < y2; k ++){
                for (int j = 0; j < i; j ++){
                    printf("B");
                }
                printf("\n");
            }
            for (int k = 0; k < y3; k ++){
                for (int j = 0; j < i; j ++){
                    printf("C");
                }
                printf("\n");
            }
            return 0;
        }

        int sd = 0;
        if (x2 == i){
            sd = 1;
            swap(x1, x2);
            swap(y1, y2);
        } else if (x3 == i) {
            sd = 2;
            swap(x1, x3);
            swap(y1, y3);
        } 
        if (x1 != i){
            cout << -1 << endl;
            return 0;
        }
        if (y2 == i - y1){
            swap(x2, y2);
        }
        if (y3 == i - y1){
            swap(x3, y3);
        }
        if (x2 != i - y1 || x3 != i - y1){
            cout << -1 << endl;
        } else {
            cout << i << endl;
            for (int k = 0; k < y1; k ++){
                for (int j = 0; j < i; j ++){
                    putchar('A' + sd);
                }
                printf("\n");
            }
            for (int k = 0; k < i - y1; k ++){
                for (int j = 0; j < y2; j ++){
                    if (sd != 1){
                        putchar('B');
                    } else {
                        putchar('A');
                    }
                }
                for (int j = 0; j < y3;j ++){
                    if (sd != 2){
                        putchar('C');
                    } else {
                        putchar('A');
                    }
                }
                printf("\n");
            }
        }
    } else {
        cout << -1 << endl;
    }
    return 0;
}
