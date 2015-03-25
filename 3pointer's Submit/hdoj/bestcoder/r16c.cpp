#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define lson l, m, s << 1
#define rson m + 1, r, s << 1 | 1

const int N = 1010;
long long val[N];
long long sum[N << 2];
int flag;

void pushup(int s)
{
    sum[s] = sum[s << 1] ^ sum[s << 1 | 1];
}

void build(int l, int r, int s)
{
    if (l == r)
    {
        sum[s] = val[l];
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(s);
    if (sum[s] == 0)
        flag = 1;
}

void test(int l, int r, int s)
{
    printf("%lld\t", sum[s]);
    if (l == r)
        return;
    int m =(l + r) >> 1;
    test(lson);
    test(rson);
}

int main()
{
    int t;
    int n;
    scanf("%d", &t);
    while(t--)
    {
        flag = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
           // scanf("%I64d", &val[i]);
            scanf("%lld", &val[i]);
        sort(val + 1, val + n + 1);
        build(1, n, 1);
        test(1, n, 1);
        if (flag == 1)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}

