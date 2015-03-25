#include <stdio.h>
#include <algorithm>
#include <string.h>
#define N 200011
#define lson l, m , s << 1
#define rson m + 1, r , s << 1 | 1

using namespace std;

int maxx[N << 2];
int ch[N << 2];
int ans[N << 2][2];
struct node
{
    int li, num;
    bool operator < (const node x) const
    {
        return li < x.li;
    }
}line[N << 2];

inline int max(int a, int b)
{
    return a > b ? a : b;
}

void pushup(int s)
{
    maxx[s] = max(maxx[s << 1], maxx[s << 1 | 1]);
}

void pushdown(int s, int m)
{
    if (ch[s])
    {
        ch[s << 1] += ch[s];
        ch[s << 1 | 1] += ch[s];
        maxx[s << 1] += ch[s];
        maxx[s << 1 | 1] += ch[s];
        ch[s] = 0;
    }
}

void update(int ll, int rr, int val, int l, int r, int s)
{
    if (ll <= l && r <= rr)
    {
        ch[s] += val;
        maxx[s] += val;
        return ;
    }
    pushdown(s, r - l + 1);
    int m = (l + r) >> 1;
    if (ll <= m)
    update(ll, rr, val, lson);
    if (rr > m)
    update(ll, rr, val, rson);
    pushup(s);
}

int main()
{
    int t;
    int a, b;
    int n;
    scanf("%d", &t);
    while(t --)
    {
        memset(maxx, 0, sizeof(maxx));
        memset(ch, 0, sizeof(ch));

	memset(ans, 0, sizeof(ans));
	memset(line, 0, sizeof(line));
        scanf("%d", &n);
        for (int i = 0 ; i < n ; i++)
        {
            scanf("%d%d",&ans[i][0],&ans[i][1]);
            line[i*2].li = ans[i][0],line[i*2].num = -(i+1);
            line[i*2+1].li = ans[i][1],line[i*2+1].num = i+1;
        }

        sort(line,line+n*2);
        int tp = 1;
        int temp = line[0].li;

        for(int i = 0; i < 2 * n; i++)
        {
            if(line[i].li != temp)  
            {
                tp++;
                temp = line[i].li;
            }
            if(line[i].num < 0)
            ans[-line[i].num-1][0] = tp;
            else
            ans[line[i].num-1][1] = tp;
        }
        for (int i = 0; i < n; i++)
        update(ans[i][0],ans[i][1] , 1, 1, tp, 1);
        printf("%d\n", maxx[1]);
    }
    return 0;
}
