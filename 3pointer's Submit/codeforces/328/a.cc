#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
char ma[10][10];

int main(){
    int ansb = 0;
    int answ = 8;

    for (int i = 0; i < 8; i ++)
            scanf("%s", ma[i]);
    for (int i = 0; i < 8; i ++){
        for (int j = 0; j < 8;j ++){
            if (ma[i][j] == 'B'){
                int flag = 0;
                for (int k = i + 1; k < 8; k ++)
                    if (ma[k][j] == 'W'){
                        flag = 1;
                        break;
                    }
                if (flag == 0) ansb = max(ansb, i);
            }
            if (ma[i][j] == 'W'){
                int flag = 0;
                for (int k = i - 1; k >= 0; k --)
                    if (ma[k][j] == 'B'){
                        flag = 1;
                        break;
                    }
                if (flag == 0) answ = min(answ, i);
            }
        }
    }
    if (7 - ansb < answ){
        cout << 'B' << endl;
    }
    else
        cout << 'A' << endl;

    return 0;
}
