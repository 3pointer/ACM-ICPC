/*************************************************************************
	> File Name: 359c.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年09月24日 星期四 17时08分06秒
 ************************************************************************/

#include<iostream>
#include<map>
#include <cstdio>
using namespace std;
#define N 100005
#define M 1000000007

long long a[N];
map<long long, int>w;

long long quick_mul(long long a, long long b){
    a %= M;
    long long res = 1;
    while(b){
        if (b & 1)
            res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}

long long quick_mod(long long a,long long b)
{
        long long ans = 1;
        a %= M;
        while(b)
    {
                if(b&1)
        {
                        ans = ans * a % M;
                        b--;
                    
        }
                b >>= 1;
                a = a * a % M;
            
    }
        return ans;

}

int main(){
    long long n, x;
    long long s = 0;
    w.clear();
    scanf("%I64d %I64d", &n, &x);
    for (int i = 0; i < n; i ++){
        scanf("%I64d", &a[i]);
        s += a[i];
        w[a[i]] ++;
    }
    int i = a[n - 1];

    while(w[i] % x == 0){
        w[i - 1] += w[i] / x;
        i --;
    }
    if (i < 0)
        i = 0;
    printf("%I64d", quick_mul(x, s - i));
    return 0;
}
