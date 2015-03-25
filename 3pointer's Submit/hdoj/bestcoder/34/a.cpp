#include <stdio.h>
#define N 200
int num[N];
int mon[N];

int main()
{
    int n, m;
    int x;
    int ans;
    while(scanf("%d%d", &n, &m) != EOF) {
        ans = 10000000;
        for (int i = 0; i < m; i ++) {
            x = 0;
            scanf("%d%d", &num[i], &mon[i]);
            if (n % num[i]){
                x ++;       
            }
            x += n / num[i];
            x *= mon[i];
            if (ans > x)
                ans = x;
        }
        printf("%d\n", ans);
    }

    return 0;
}
