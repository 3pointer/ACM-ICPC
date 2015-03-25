#include <stdio.h>

int a[10000000];
int p[500000];
int tot;

int main()
{
    int n;
    for (int i = 2; i <= 2000000; i++)
    {
        if (a[i] == 0)
            p[tot++] = i;
        for (int j = 0; j < tot && p[j] * i < 2000000; j++)
        {
            a[p[j] * i] = 1;
            if (i % p[j] == 0)
                break;
        }
    }

    int x;
    int i;
    int j;

    while(scanf("%d", &n) != EOF)
    {
        if (a[n] == 0)
        {
            printf("0\n");
        }
        else
        {
            for (i = n; a[i] != 0; i--);
            for (j = n; a[j] != 0; j++);
            printf("%d\n", j - i); 
        }
    }
    return 0;
}
