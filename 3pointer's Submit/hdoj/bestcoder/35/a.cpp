#include <stdio.h>
#include <string.h>
#define N 24

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int c[N][N];
int main(){
    int n, m;
    for (int i = 0; i <= N; i ++)
        c[i][0] = c[i][i] = 1;
    for (int i = 1; i <= N; i ++)
        for (int j = 0; j <= i; j ++)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];

    while(scanf("%d%d", &n, &m) != EOF){
        int x = c[n][1] * c[m][1];        
        int y = c[n + m][n];
        int m = gcd(x, y);
        printf("%d/%d\n", x / m, y / m);
    }
    return 0;
}

