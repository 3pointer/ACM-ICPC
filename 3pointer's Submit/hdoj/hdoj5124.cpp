#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 200101

struct node
{
    int point;
    bool j;
    bool operator < (const node p) const
    {
        return point < p.point;
    }
}e[N];

inline int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int t;
    int n;
    scanf("%d", &t);
    while(t--)
    {
        //memset(e, 0, sizeof(e));
        scanf("%d", &n);
        for (int i = 0; i < 2 * n; i+=2)
        {
            scanf("%d", &e[i].point);
            e[i].j = 0;
            scanf("%d", &e[i + 1].point);
            e[i + 1].point++;
            e[i + 1].j = 1;
        }
        sort(e, e + 2 * n);
        int num = 0;
        int ans = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            if (e[i].j == 0)
                num ++;
            else
                num --;
            ans = max(ans, num);
        }
        printf("%d\n", ans); 
    }
    return 0;
}
