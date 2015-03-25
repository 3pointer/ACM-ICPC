#include <stdio.h>
int a[5] = {1, 2, 4, 7, 15};
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int i;
        for (i = 4; i >= 0; i--)
        {
            if (n > a[i])
                break;
        }
        for (int j = i; j > 0; j--)
            printf("%d ", n - a[j]);
        printf("%d\n", n - a[0]);
    }
    return 0;
}
