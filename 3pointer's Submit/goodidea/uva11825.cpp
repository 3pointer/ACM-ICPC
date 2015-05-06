#include <stdio.h>
#include <iostream>
#include <string.h>
#define N 100000
using namespace std;

int p[N];
int cover[N];
int f[N];

int main(){
    int n;
    int m, x;
    while(scanf("%d", &n) != EOF){
        memset(p, 0, sizeof(p));
        for (int i = 0; i < n; i ++){
            p[i] = 1 << i;
            scanf("%d", &m);
            while(m --){
                scanf("%d", &x);
                p[i] |= 1 << x;
            }
        }
        
        for (int s = 0; s < (1 << n); s ++){
            cover[s] = 0;
            
            for (int i = 0; i < n; i ++){
                if (s & 1 << i){
                    cover[s] |= p[i];
                }
            }
        }

        f[0] = 0;
        int a = (1 << n) - 1;
        for (int s = 1; s < (1 << n); s ++){
            f[s] = 0;
            for (int s0 = s; s0; s0 = (s0 - 1) & s)
            if (cover[s0] == a) {
                f[s] = max(f[s], f[s^s0] + 1);
            }
        }
        printf("%d\n", f[a]);
    }

    return 0;
}
