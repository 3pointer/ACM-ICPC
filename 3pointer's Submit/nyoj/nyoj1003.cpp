#include <stdio.h>
int main()
{
    long long n;
    while(scanf("%lld", &n) != EOF)
    {
        if (n == 0)
        {
            printf("1\n");
            continue;
        }
        n --;
        n = (1 + n) * n / 2;
        n = n * 8 + 2;
        printf("%lld\n", n);
    }
    return 0;
}
