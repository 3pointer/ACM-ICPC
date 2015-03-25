#include <stdio.h>
#include <stdlib.h>
#define N 50010

int a[N];
int b[N];
int sum[N];

int n, w, h;
int main()
{
    sum[0] = 0;
    int ans, ansi;
    int ans2, ans2i;
    while(scanf("%d%d%d", &n, &w, &h) != EOF){
        sum[0] = 0;
        ans = 1000000;
        ans2 = 1000000;
        for (int i = 1; i <= n; i ++){
            scanf("%d", &a[i]);
            b[i] = a[i];
            sum[i] = sum[i - 1] + a[i];
        }

        if (sum[n] / n < h){
            printf("-1\n");
            continue;
        }

        for (int i = w; i <= n; i ++){
            if (abs(sum[i] - sum[i - w] - w * h) < ans){
                ans = sum[i] - sum[i - w] - w * h;
                ansi = i - w + 1;
            }
        }
        for (int i = 1; i <= n; i ++){
            a[i] -= h;
            if (a[i] < 0)
                a[i] = -a[i];
        }
        int tmp = 0;
        for (int i = 1; i <= n; i ++){
            tmp += b[i];
            if (i % w == 0) {
                if (ans2 > tmp){
                    ans2 = tmp;
                }
                tmp = 0;
            }
        }
        int res = 0;
        if (ans < ans2){
            for (int i = ansi; i <= w; i ++){
                if (b[i] - h < 0)
                    res += h - b[i];
            }
        }
        else{
            res = ans2;
        }
        printf("%d\n", res);
    }

    return 0;
}
