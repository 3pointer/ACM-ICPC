#include <stdio.h>

long long f(long long a, long long b)
{
    if (a < b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    if (b == 0)
        return 0;
    long long cou = 0;
    cou += a / b;
    return cou + f(b, a % b);
}
int main()
{
    long long a, b;
    while(scanf("%I64d%I64d", &a, &b) != EOF)
    //while(scanf("%lld%lld", &a, &b) != EOF)
    {
        long long c = f(a, b); 
        printf("%lld\n", c);
    }
    return 0;
}
