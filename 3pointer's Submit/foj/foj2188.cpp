#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

#define N 210
int n;
typedef struct node{
    int x, y, dir;
    int rx, ry;
    int step;
}Node;

int vis[N][N][2];

int bfs(Node s){
    queue<Node>q;
    q.push(s);

    while(!q.empty()){
        Node cur = q.front();
        q.pop();
        Node next;
        if (cur.dir == 1){
            int x = cur.x;
            int y = cur.y;
            for (int i = 0; i <= x; i ++){
                for (int j = 0; j <= y; j ++){
                    if (i + j > n || i + j == 0)
                        continue;
                    if ((i < j && i != 0) || (x - i < y - j && i != x) || (cur.rx + i < cur.ry + j && cur.rx + i != 0))
                        continue;
                    if (vis[x - i][y - j][0])
                        continue;
                    vis[x - i][y - j][0] = 1;
                    next.dir = -1;
                    next.step = cur.step + 1;
                    next.x = cur.x - i;
                    next.y = cur.y - j;
                    next.rx = cur.rx + i;
                    next.ry = cur.ry + j;
                    if (next.x == 0 && next.y == 0)
                        return next.step;
                    q.push(next);
                }
            }
        }
        else{
            int x = cur.rx;
            int y = cur.ry;
            for (int i = 0; i <= x; i ++){
                for(int j = 0; j <= y; j ++){
                    if (i + j > n || i + j == 0)
                        continue;
                    if ((i < j && i != 0) || (x - i < y - j && i != x) || (cur.x + i < cur.y + j && cur.x + i != 0))
                        continue;
                    if (vis[x - i][y - j][1])
                        continue;
                    vis[x - i][y - j][1] = 1;
                    next.dir = 1;
                    next.step = cur.step + 1;
                    next.rx = cur.rx - i;
                    next.ry = cur.ry - j;
                    next.x = cur.x + i;
                    next.y = cur.y + j;
                    q.push(next);
                }
            }
        }
    }
    return -1;
}

int main(){
    int x, y;
    while(scanf("%d%d%d", &x, &y, &n) != EOF){
        memset(vis, 0, sizeof(vis));
        Node b;
        b.x = x;
        b.y = y;
        b.rx = 0;
        b.ry = 0;
        b.dir = 1;
        b.step = 0;
    
        printf("%d\n", bfs(b));
    }

    return 0;
}

