#include <stdio.h>

int sum[5000100];
int asum[5000010];
int isp[5000550];
int p[2202000];
int tot;
void prime(){
    for (int i = 2; i < 5000550; i ++){
        if (isp[i] == 0){
            p[tot ++] = i;
        }
        for (int j = 0; j < tot && p[j] * i < 5000550; j ++){
            isp[p[j] * i] = p[j];    
            if (i % p[j] == 0){
                break;
            }
        }
    }
}

void work(){
    sum[1] = 0;
    asum[1] = 0;
    for (int i = 2; i < 5000001; i ++){
        if (isp[i] == 0){
            asum[i] = asum[i - 1] + 1;
            sum[i] = 1;
            continue;
        }
        sum[i] = sum[i / isp[i]] + 1;
        asum[i] = asum[i - 1] + sum[i];
    }
}
int t;
int a, b;
int main(){
    prime();
    work();
    scanf("%d", &t);
    while(t --){
        scanf("%d%d", &a, &b);
        printf("%d\n", asum[a] - asum[b]);
    }


    return 0;
}

