#include <stdio.h>
#define N 100
int f[1000];
int main()
{
    f[1] = 1;
    f[2] = 1;
    int a, b;
    scanf("%d%d", &a, &b);
    for (int i = 3; i <= N; i++)
        f[i] = a * f[i-1] % 7 + b * f[i-2] % 7;
    for (int i = 1; i <= N; i++)
        printf("%d\t", f[i]);
}

