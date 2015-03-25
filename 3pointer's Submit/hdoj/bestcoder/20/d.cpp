#include <stdio.h>
#include<string.h>

const int N = 100000000;
int c1[N], c2[N], c3[N];
int n;

int lowbit(int x)
{
    return (x)&(-x);
}

void update(int x, int y, int z)
{
    int ty, tz;
    while(x <= n)
    {
        ty = y;
        while(ty <= n)
        {
            tz = z;
            while(tz <= n)
            {
                c1[x] += 1;
                c2[ty] += 1;
                c3[tz] += 1;
                tz += lowbit(tz);
            }
            ty += lowbit(ty);
        }
        x += lowbit(x);
    }
}

int sum(int x, int y, int z)
{
    int su = 0;
    int ty, tz;
    while(x)
    {
        ty = y;
        while(ty)
        {
            tz = z;
            while(tz)
            {
                su += c1[x];
                su += c2[ty];
                su += c3[tz];
                tz -= lowbit(tz);
            }
            ty -= lowbit(ty);
        }
        x -= lowbit(x);
    }
    return su;
}

int main()
{
    int t;
    int q;
    int a, x, y, z, x1, y1, z1;
    n = 6;
    scanf("%d", &t);
    while(t--)
    {
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        memset(c3, 0, sizeof(c3));
        scanf("%d", &q);
        while(q --)
        {
            scanf("%d", &a);
            if (a == 1)
            {
                scanf("%d%d%d", &x, &y, &z);
                update(x, y, z);
            }
            else
            {
                scanf("%d%d%d%d%d%d", &x, &y, &z, &x1, &y1, &z1);
                printf("%d\n", sum(x1, y1, z1) - sum(x - 1, y - 1, z - 1));
            }
        }
    }
    return 0;
}
