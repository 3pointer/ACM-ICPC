#include <stdio.h>
#include <string.h>
#include <stack>
#define M 200000
#define N 9000

using namespace std;

struct node
{
    int next, v;
}e[M];

int n, m;
int tot;
int t;
int cnt;
int head[N];
int belong[N];
int dfn[N];
int low[N];
int instack[N];
stack<int> s;
int map[N][N];
int ind[N];
int col[N];
int confilct[N];

void init()
{
    memset(head, -1, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(ind, 0, sizeof(ind));
    cnt = 0;
    tot = 0;
    t = 0;
}
void addedge(int a, int b)
{
    e[tot].v = b;
    e[tot].next = head[a] ++;
    head[a] = tot ++;
}

void tarjan(int u)
{
    dfn[u] = low[u] = t ++; 
    s.push(u);
    instack[u] = 1;

    for (int i = head[u]; i != -1; i = e[i].next)
    {
        if (!dfn[e[i].v])
        {
            tarjan(e[i].v);
            low[u] = min(low[u], low[e[i].v]);
        }
        else if (instack[e[i].v])
            low[u] = min(low[u], dfn[e[i].v]);
    }
    int v;
    if (dfn[u] == low[u])
    {
        cnt ++;
        do
        {
            v = s.top();
            s.pop();
            instack[v] = 0;
            belong[v] = cnt;
        }while(u != v);
    }
}
void build_dag()
{
    for (int u = 0; u < 2 * n; u ++)
    {
        for (int i = head[u]; i != -1; i = e[i].next)
        {
            if (belong[u] != belong[e[i].v])
                map[belong[e[i].v]][belong[u]] = 1;
        }
    }
    for (int u = 1; u <= cnt; u ++)
        for (int v = 1; v <= cnt; v ++)
            if (map[u][v])
                ind[v] ++;
}

void topsort()
{
    for (int i = 1; i <= cnt; i ++)
        if (ind[i] == 0)
            s.push(i);
    while(!s.empty())
    {
        int cur = s.top(); 
        s.pop();
        if (!col[cur])
        {
            col[cur] = 1;
            col[confilct[cur]] = 2;
        }
        for (int v = 1; v <= cnt; v ++)
            if (map[cur][v])
                if (-- ind[v] == 0)
                    s.push(v);
    }
}

void solve()
{
    while(!s.empty())
        s.pop();
    for (int i = 0; i < 2 * n; i ++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 0; i < n; i++)
    {
        if (belong[2 * i] == belong[2 * i + 1])
        {
            puts("bad luck");
            return ;
        }
        confilct[belong[2 * i]] = belong[2 * i + 1];
        confilct[belong[2 * i + 1]] = belong[2 * i];
    }
    memset(map, 0, sizeof(map));
    memset(ind, 0, sizeof(ind));
    build_dag();
    memset(col, 0, sizeof(col));
    while(!s.empty())
        s.pop();
    topsort();
    for (int i = 2; i < 2 * n; i += 2)
    {
        if (i != 2)
            printf(" ");
        if (col[belong[i]] == col[belong[0]])
            printf("%dw", i / 2);
        else
            printf("%dh", i / 2);
    }
    printf("\n");
}
int main()
{
    while(scanf("%d%d", &n, &m) && n + m)
    {
        init();    
        int a, b;
        int ax, bx;
        char c, d;
        for (int i = 0; i < m; i ++)
        {
            scanf("%d%c%d%c", &a, &c, &b, &d);
            if (c == 'h')
            {
                a = a * 2 + 1;
                ax = a ^ 1;
            }
            else
            {
                a = a * 2;
                ax = a ^ 1;
            }
            if (d == 'h')
            {
                b = b * 2 + 1;
                bx = b ^ 1;
            }
            else
            {
                b = b * 2;
                bx = b ^ 1;
            }
            addedge(a, bx);
            addedge(b, ax);
        }
        addedge(0, 1);
        solve();
    }
    return 0;
}
