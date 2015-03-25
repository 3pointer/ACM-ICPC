#include <stdio.h>

int a[110];

int main()
{

    for (int i = 0; i <= 100; i++)
        a[i] = i;
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        m --;
        m %= n;
        printf("%d\n", a[m]);
    }
    return 0;
}

