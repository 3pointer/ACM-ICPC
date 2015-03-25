#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    long long  n, B;
    while(scanf("%lld%lld", &n, &B) != EOF)
    {
        long long ans = ((n - 1) % B) * ((n - 2) % B) * 2;
        ans %= B;
        printf("%lld\n", (ans + 2) % B);
    }
    return 0;
}
