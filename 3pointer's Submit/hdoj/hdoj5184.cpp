#include <stdio.h>
#define M 1000000007
#define AXN 2000010

long long f[AXN];
long long r[AXN];

long long fpow(long long a, int b)
{
    long long tmp = a;
    long long ans = 1;
    while(b)
    {
        if (b & 1)
            ans *= tmp;
        tmp *= tmp;
        b >>= 1;
    }
    return ans;    
}

void init()
{
    f[0] = 1;
    for (int i = 1; i < AXN; i++)
        f[i] = f[i - 1] * i % M;
    r[AXN - 1] = fpow(f[AXN - 1], M - 2);
    for (int i = AXN - 2; i >= 0; i --)
        r[i] = r[i + 1] * (i + 1) % M;
}

int main()
{
    int n;
    int a, b;
    char ch;
    
    while(scanf("%d", &n) != EOF)
    {
        getchar();
        init();
        a = 0;
        b = 0;
        while(scanf("%c", &ch) && ch != '\n')
        {
            if (ch == '(')
                a++;
            if (ch == ')')
                b++;
        }
        int m = n / 2;
        int p = m - b;
        int q = m - a;
        if (n & 1 == 1 || a < b)
            printf("0\n");
        else
            printf("%lld\n",(f[p + q] * (p + 1 - q) * (r[q] * r[p + 1] % M) % M));
    }
    return 0;
}
