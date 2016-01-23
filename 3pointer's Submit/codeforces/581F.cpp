/*************************************************************************
	> File Name: 581F.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年09月30日 星期三 22时35分53秒
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;
#define N 5010
#define INF 0x3f3f3f3f

struct node{
    int next, to;
}e[N << 2];

int head[N];
int tot;
int dp[N][N][2];
int du[N];

void init(){
    memset(head, -1, sizeof(head));
    memset(du, 0, sizeof(du));
    tot = 0;
}

void addedge(int a, int b){
    e[tot].next = head[a];
    e[tot].to = b;
    head[a] = tot++;

    e[tot].next = head[b];
    e[tot].to = a;
    head[b] = tot++;
}

int dfs(int u, int fa){
    if(du[u] == 1){
        dp[u][1][1] = dp[u][0][0] = 0;
        dp[u][1][0] = dp[u][0][1] = INF;
        return 1;
    }

    int total = 0;
    dp[u][0][1] = 0;
    dp[u][0][0] = 0;

    for (int i = head[u]; i != -1; i = e[i].next){
        int v = e[i].to;
        if (v == fa)
            continue;
        int now = dfs(v, u);
        total += now;
        for (int j = total; j >= 0; j --){
            int temp0 = INF;
            int temp1 = INF;
            for (int k = 0; k <= now; k ++){
                temp0 = min(temp0, min(dp[u][j - k][0] + dp[v][k][0], dp[u][j - k][0] + dp[v][k][1] + 1));
                temp1 = min(temp1, min(dp[u][j - k][1] + dp[v][k][1], dp[u][j - k][1] + dp[v][k][0] + 1));
            }
            dp[u][j][0] = temp0;
            dp[u][j][1] = temp1;
        }
    }
    return total;
}

int main(){
    int n;
    int a, b;
    cin >> n;
    init();
    for (int i = 1; i < n; i ++){
        cin >> a >> b;
        addedge(a, b);
        du[a] ++, du[b] ++;
    }
    
    int root, cnt = 0;
    for (int i = 1; i <= n; i ++){
        if (du[i] > 1)
            root = i;
        else
            cnt ++;
    }

    memset(dp, INF, sizeof(dp));
    dfs(root, -1);
    cout << min(dp[root][cnt/2][1], dp[root][cnt/2][0]) << endl;
    return 0;
}
