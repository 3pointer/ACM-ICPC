#include<stdio.h>
#include<string.h>
#include <queue>
#define N 501
#define M 100001
#define min(a,b) a<b?a:b
using namespace std;
double map[12][1200];
double ans;
struct node
{
    int to, cap, next;
    double w;
}e[M];
int ek;
int head[N];
double dis[N];
int vis[N];
int pre[N];


void init()
{
    ek = 0;
    memset(head, -1, sizeof(head));
}

void addedge(int a, int b, double c, int d)
{
    e[ek].to = b;
    e[ek].w = c;
    e[ek].next = head[a];
    e[ek].cap = d;
    head[a] = ek++;
    
    e[ek].to = a;
    e[ek].w = -c;
    e[ek].next = head[b];
    e[ek].cap = 0;
    head[b] = ek++;
}
bool spfa(int s, int t)
{
    queue<int>q;
    memset(vis, 0, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    for (int i = s; i <= t; i++)
        dis[i] = -1000000;
    dis[s] = 0;
    vis[s] = 1;
    q.push(s);
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        vis[cur] = 0;
        for (int i = head[cur]; i != -1; i = e[i].next)
        {
            if (e[i].cap && dis[e[i].to] < dis[cur] + e[i].w)
            {
                dis[e[i].to] = dis[cur] + e[i].w;
                pre[e[i].to] = i;
                if (!vis[e[i].to])
                {
                    vis[e[i].to] = 1;
                    q.push(e[i].to);
                }
            }
        }
    }
    return dis[t] != -1000000;
}
double dfs(int s, int t)
{
    double answ = 0;
    int delta = 1;
    while(spfa(s,t))
    {
        /*
        delta = INF;
        for (int i = pre[t]; i != -1; i = pre[e[i^1].to])
            delta = min(delta, e[i].cap);
        */
        for (int i = pre[t]; i != -1; i = pre[e[i^1].to])
        {
            e[i].cap -= delta;
            e[i^1].cap += delta;
        }
        answ += dis[t] * delta;
    }
    return answ;
}
double fun(int h, int l, int n, int m)
{
    init();
    for (int i = 1; i <= n; i++)
        addedge(0, i, 0, 1);
    for (int i = 1; i <= m; i++)
        addedge(i + n, 2 * n + 1, 0, 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            addedge(i, j + n, map[i][j + l - 1], 1);
    return dfs(0, 2 * n + 1);
}
/*
void fun2(int i, int n, double c)
{
    if (i == n)
    {
        if (tmp <= c)
            tmp = c;
        return;
    }

    for (int j = 1; j <= nn; j++)
    {
        if (!visit[j])
        {
            visit[j] = 1;
            fun2(i + 1, n, c + map[j][i]);
            visit[j] = 0;
        }
    }
}
*/
int main()
{
    int t;
    int nn;
    int mm;
    int i;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas ++)
    {
        ans = 0;
        scanf("%d%d", &nn, &mm);
        for (i = 1; i <= nn; i++)
            for (int j = 1; j <= mm; j++)
                scanf("%lf", &map[i][j]);
        for (i = 1; i + nn <= mm; i += nn)
           ans += fun(1, i, nn, nn);
        if (mm - i + 1 > 0)     
            ans += fun(1, i, nn, mm - i + 1);
        printf("Case #%d: %.5lf\n",cas, ans);
    }
    return 0;
}
