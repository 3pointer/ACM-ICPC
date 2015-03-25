/*************************************************************************
	> File Name: 523A.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年03月19日 星期四 17时42分40秒
 ************************************************************************/

#include<iostream>
#include <stdio.h>
using namespace std;

char t[110][110];
char a[210][210];

int main()
{
    int w, h;
    while(cin >> w >> h){
        for (int i = 0; i < h; i ++){
            getchar();
            for (int j = 0; j < w; j ++) {
                cin >> t[i][j];
            }
        }
        for (int i = 0; i < 2 * w; i ++){
            for (int j = 0; j < 2 * h; j ++){
                a[i][j] = t[j / 2][i / 2];
            }
        }
        for (int i = 0; i < 2 * w; i ++) {
                for (int j = 0; j < 2 * h; j ++){
                    cout<<a[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
