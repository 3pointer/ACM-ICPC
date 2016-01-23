#include<bits/stdc++.h>

using namespace std;


bool fun(int x){
    int ans = 0;
    int b;
    while(x){
        b = x & 1;
        if (b == 0)
            ans ++;
        x >>= 1;
    }
    return ans == 1;
}
int main(){
    int n = 1000000;
    for (int i = 0; i < n; i ++){
        if (fun(i)){
            printf("%d\t", i);
        }
    }

    return 0;
}
