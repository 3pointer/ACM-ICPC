#include <stdio.h>

int ri[30];
int le[30];
int up[30];
int main()
{
    int n;
    int t;
    ri[1] = 1;
    le[1] = 1;
    up[1] = 1;
    for (int i = 2; i <= 22; i++)
    {
        ri[i] = ri[i - 1] + up[i - 1];
        le[i] = le[i - 1] + up[i - 1];
        up[i] = up[i - 1] + ri[i - 1] + le[i - 1];
    }
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d", &n);
        printf("%d\n", up[n] + le[n] + ri[n]);
    }

    return 0;
}
