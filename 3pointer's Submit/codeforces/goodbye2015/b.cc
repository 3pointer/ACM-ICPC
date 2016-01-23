#include<bits/stdc++.h>

using namespace std;

const int N = 1001;

int tmp[N];

int cou;

void fun(long long x){
    if (x == 0){
        return ;
    }
    fun(x >> 1);
    tmp[cou ++] = x & 1;
}

long long fun2(){
    long long ans = 0;
    long long tp = 1;
    for (int i = cou - 1; i >= 0; i --){
        if (tmp[i] == 1)
            ans += tp;
        tp <<= 1;
    }
    return ans;
}

int main(){

    long long a, b;
    cin >> a >> b;

    cou = 0;

    fun(a);
    for (int i = cou; i <= 1000; i ++){
        tmp[i] = 1;
    }
    int ans = 0;
    for (int i = 0; i < cou; i ++){
        if (tmp[i] == 0){
            ans ++;
        }
    }
    if (ans > 1){
        for (int i = cou - 1; i > 0; i --){
            if (tmp[i] == 0){
                tmp[i] = 1;
                ans --;
            }
            if (ans == 1){
                break;
            }
        }
    }
    if (ans == 0){
        for (int i = cou; i >= 2; i --){
            tmp[i] = tmp[i - 1];
        }
        tmp[1] = 0;
        cou ++;
    }

    long long na = fun2();
    long long res = 0;
    while(na <= b){
        res ++;
        for (int i = 0; i < 100; i ++){
            if (i == cou - 1){
                swap(tmp[cou - 1], tmp[1]);
                cou ++;
                na = fun2();
                break;
            }
            if (tmp[i] == 0){
                swap(tmp[i], tmp[i + 1]);
                na = fun2();
                break;
            }

        }
    }
    cout << res << endl;


    return 0;
}
