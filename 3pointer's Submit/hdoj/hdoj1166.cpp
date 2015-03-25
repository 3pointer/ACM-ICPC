#include <stdio.h>
#define N 50010

struct node
{
    int l, r;
    int num;
}tree[N * 4];

int val[N];

void build(int l, int r, int s)
{
    tree[s].l = l;
    tree[s].r = r;
    if (l == r)
    {
        tree[s].num = val[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, s * 2);
    build(mid + 1, r, s * 2 + 1);
    tree[s].num = tree[s * 2].num + tree[s * 2 + 1].num;
}

int request(int l, int r, int s)
{
    if (tree[s].l == l && tree[s].r == r)
    {
        return tree[s].num;
    }
    if (l >= tree[s * 2 + 1].l)
        return request(l, r, s * 2 + 1);
    if (r <= tree[s * 2].r)
        return request(l, r, s * 2);
    int rl, rr;
    int mid = (tree[s].l + tree[s].r) >> 1;
    rl = request(l, mid, s * 2);
    rr = request(mid + 1, r, s * 2 + 1);
    return rr + rl;
}

void update(int l, int num, int s)
{
    if (tree[s].l == tree[s].r)
    {
        tree[s].num += num;
        return;
    }
    int mid = (tree[s].l + tree[s].r) >> 1;
    if (l > mid)
        update(l, num, s * 2 + 1);
    else 
        update(l, num, s * 2);
    tree[s].num = tree[s * 2].num + tree[s * 2 + 1].num;
}

int main()
{
    int t;
    int a, b;
    int n;
    char str[10];
    int id = 1;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &val[i]);
        build(1, n, 1);
        printf("Case %d:\n", id ++);
        while(scanf("%s", str) && str[0] != 'E')
        {
            scanf("%d%d", &a, &b);
            if (str[0] == 'Q')
            {
                printf("%d\n", request(a, b, 1));
            }
            if (str[0] == 'A' || str[0] == 'S')
            {
                if (str[0] == 'A')
                {
                    update(a, b, 1);
                }
                else
                {
                    update(a, -b, 1);
                }
            }
        }
    }
    return 0;
}
