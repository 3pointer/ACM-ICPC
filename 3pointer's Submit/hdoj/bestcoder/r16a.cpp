#include <stdio.h>
#include <iostream>
using namespace std;
#define M 1000000007

long long  a[447010];

int main()
{
    int n;
    int t;
    long long sum = 0;
    scanf("%d", &t);
    while(t --)
    {
        sum = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            //scanf("%I64d", &a[i]);
            scanf("%lld", &a[i]);
            sum += (((((n - i + 1) * i)%M) * a[i])%M);
            sum %= M;
        }
        //printf("%I64d\n", sum);
        printf("%lld\n", sum);
    }
    return 0;
}
