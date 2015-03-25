#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N  1100

struct node
{
    int f, s;
    int ans;
    int val;
}e[N];

int cmp(node a, node b)
{
    if (a.ans != b.ans)
        return b.ans < a.ans;
    else if (a.s != b.s)
        return a.s < b.s;
    else
        return 0;
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        memset(e, 0, sizeof(e));
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &e[i].f, &e[i].s);
            e[i].ans = e[i].f - e[i].s;
            e[i].val = i;
        }
        for (int j = 0; j < n - 1; j++)
            for (int i = 0; i < n - 1 - j; i++)
                if (e[i].ans < e[i + 1].ans || (e[i].ans == e[i + 1].ans && e[i].s > e[i + 1].s))
        {
            node t = e[i];
            e[i] = e[i + 1];
            e[i + 1] = t;
        }
        printf("%d", e[0].val);
        for (int i = 1; i < n; i++)
            printf(" %d", e[i].val);
        printf("\n");
    }
    return 0;
}
