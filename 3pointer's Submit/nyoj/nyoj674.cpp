#include <stdio.h>
#include <string.h>
#define N 600
#define M 1010
#define INF 0x3f3f3f3f

int head[N];
int root[N];
int tot;
int dp[N][N];
int n, m;

struct node
{
    int to, next;
}e[M];

inline int min(int a, int b)
{
    return a < b ? a : b;
}

void init()
{
    memset(head, -1, sizeof(head));
    memset(root, 0, sizeof(root));
    memset(dp, 0, sizeof(dp));
    tot = 0;
}

void add(int a, int b)
{
    e[tot].next = head[a];
    e[tot].to = b;
    head[a] = tot++;
}

void dfs(int u)
{
    for (int i = head[u]; i != -1; i = e[i].next)    
    {
        int v = e[i].to;
        dp[u][1] = 0;
	    dp[u][0] = 1;
        dfs(v);
        for (int j = m; j >= 1; j --)
        {
            dp[u][j] ++;
            for (int k = 1; k < j; k++)
                dp[u][j] = min(dp[u][j], dp[u][j - k] + dp[v][k]);
        }
    }
}

int main()
{
    int t;
    int a, b;
    int casee = 1;
    scanf("%d", &t);
    while(t --)
    {
        init();
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n - 1; i ++)
        {
            scanf("%d%d", &a, &b);
            add(a, b);
            root[b] = 1;
        }
        int ans;
        for (int i = 1; i <= n; i++)
        {
            if (root[i] == 0)
            {
                ans = 1;
                break;
            }               
        }
        dfs(ans);
        ans = dp[ans][m];
        for (int i = 1; i <= n; i++)
        {
            if (ans > dp[i][m] + 1)
                ans = dp[i][m] + 1;
        }
        printf("case #%d: %d\n", casee++, ans); 
    }
    return 0;
}
