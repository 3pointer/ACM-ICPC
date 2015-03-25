 
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define N 110

int n, m, t;
char map[N][N];
int dp[N][N][9];
int dir[4][2] =  {0, 1, 0, -1, 1, 0, -1, 0};
int co;
int cod;
int pxd[N];
int pyd[N];
int px[N];
int py[N];

typedef struct node
{
    int x, y, c;
}NODE;

bool ok(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m || map[x][y] == 'X')
        return 0;
    return 1;
}

void change(int i, int j)
{
    co = 0;
    int x = i; 
    int y = j;
    while(x >= 0)
    {
        x --;
        if (ok(x, y) && map[x][y] != 'D')
        {
            px[co] = x;
            py[co++] = y;
        }
        else break;
    }
    x = i; 
    y = j;
    while(x < n)
    {
        x ++;
        if (ok(x, y) && map[x][y] != 'D')
        {
            px[co] = x;
            py[co++] = y;
        }
        else break;
    }
    x = i; 
    y = j;
    while(y >= 0)
    {
        y --;
        if (ok(x, y) && map[x][y] != 'D')
        {
            px[co] = x;
            py[co++] = y;
        }
        else break;
    }
    x = i; 
    y = j;
    while(y < m)
    {
        y ++;
        if (ok(x, y) && map[x][y] != 'D')
        {
            px[co] = x;
            py[co++] = y;
        }
        else break;
    }
}
void changed(int i, int j)
{
    cod = 0;
    int x = i; 
    int y = j;
    while(x >= 0)
    {
        x --;
        if (ok(x, y)&&map[x][y] != 'E')
        {
            pxd[cod] = x;
            pyd[cod++] = y;
        }
        else break;
    }
    x = i; 
    y = j;
    while(x < n)
    {
        x ++;
        if (ok(x, y)&&map[x][y] != 'E')
        {
            pxd[cod] = x;
            pyd[cod++] = y;
        }
        else break;
    }
    x = i; 
    y = j;
    while(y >= 0)
    {
        y --;
        if (ok(x, y)&&map[x][y] != 'E')
        {
            pxd[cod] = x;
            pyd[cod++] = y;
        }
        else break;
    }
    x = i; 
    y = j;
    while(y < m)
    {
        y ++;
        if (ok(x, y)&&map[x][y] != 'E')
        {
            pxd[cod] = x;
            pyd[cod++] = y;
        }
        else break;
    }
}

void show()
{
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            printf("%c", map[i][j]);
        printf("\n");
    }
}
int bfs(NODE s)
{
    queue<NODE>q;
    q.push(s);
    memset(dp, -1, sizeof(dp));
    dp[s.x][s.y][s.c] = 0;
    while(!q.empty())
    {
        NODE cur = q.front();  
        q.pop();
        if (cur.c == 3)
            return dp[cur.x][cur.y][3];
        for (int i = 0; i < 4; i++)
        {
            NODE temp;
            temp.x = cur.x + dir[i][0];
            temp.y = cur.y + dir[i][1];
            if (ok(temp.x, temp.y))
            {
                int c = cur.c;
                for (int j = 0; j < co; j++)
                {
                    if (temp.x == px[j] && temp.y == py[j])
                        c |= 2;
                }
                for (int j = 0; j < cod; j++)
                {
                    if (temp.x == pxd[j] && temp.y == pyd[j])
                        c |= 1;
                }
                if (dp[temp.x][temp.y][c] != -1)
                    continue;
                dp[temp.x][temp.y][c] = dp[cur.x][cur.y][cur.c] + 1;
                temp.c = c;
                q.push(temp);
            }    
        }
    }
    return -1;
}
int main()
{
    NODE start;
    NODE D, E;
    int cou = 1;
    while(scanf("%d%d%d", &n, &m, &t) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%s", map[i]);
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] == 'S')
                {
                    start.x = i;
                    start.y = j;
                    start.c = 0;
                } 
                if (map[i][j] == 'D')
                {
                    D.x = i;
                    D.y = j;
                }
                if (map[i][j] == 'E')
                {
                    E.x = i;
                    E.y = j;
                }
            }
        }
        changed(D.x, D.y);
        change(E.x, E.y);
        px[co] = E.x;
        py[co++] = E.y;
        pxd[cod] = D.x;
        pyd[cod++] = D.y;
        map[D.x][D.y] = map[E.x][E.y] = 'X';
        for (int j = 0; j < co; j++)
        {
            if (start.x == px[j] && start.y == py[j])
            start.c |= 2;
        }
        for (int j = 0; j < cod; j++)
        {
            if (start.x == pxd[j] && start.y == pyd[j])
            start.c |= 1;
        }
        int ans = bfs(start);
        printf("Case :%d\n", cou++);
        if (ans > t)
            ans = -1;
        printf("%d\n", ans);
    }
}        
