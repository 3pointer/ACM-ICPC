#include <stdio.h>
#define N 1010

int n, t;
long long val[N];

int main()
{
    scanf("%d", &t);
    while(t --)
    {
        for (int i = 1; i <= n; i++)
            scanf("%lld", &val[i]);
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= n - i;j ++)
            {
                for (int k = j; k <= j + i; k ++)
                {
                     
                }
            }
        }
    }
    return 0;
}
