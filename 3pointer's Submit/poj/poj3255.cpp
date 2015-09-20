/*************************************************************************
	> File Name: poj3255.cpp
	> Author: 3pointer
	> Mail: 
	> Created Time: 2015年05月25日 星期一 15时10分10秒
 ************************************************************************/

#include<iostream>
#include<queue>
#include<stdio.h>
#include<string.h>
using namespace std;
#define N 55100
#define INF 0x3f3f3f3f

int vis[N];
int head[N];
int tot;
int n, m;
struct node{
    int to, next, w;
}e[N << 3];

void init(){
    memset(head, -1, sizeof(head));
    tot = 0;
}

void addedge(int a, int b, int c){
    e[tot].next = head[a];
    e[tot].to = b;
    e[tot].w = c;
    head[a] = tot ++;
}


void spfa(int * dis, int s){
	queue<int>q;
    dis[s] = 0;
    vis[s] = 1;
    q.push(s);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        vis[cur] = 0;

        for (int i = head[cur]; i != -1; i = e[i].next){
            if (dis[e[i].to] > dis[cur] + e[i].w){
                dis[e[i].to] = dis[cur] + e[i].w;
                if (vis[e[i].to] == 0){
                    q.push(e[i].to);
                    vis[e[i].to] = 1;
                }
            }
        }
    }
}
int main(){
    int dis1[N];
    int dis2[N];
    int a, b, c;
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        memset(dis1, INF, sizeof(dis1));
        memset(dis2, INF, sizeof(dis2));
        for (int i = 1; i <= m; i ++){
            scanf("%d%d%d", &a, &b, &c);
            addedge(a, b, c);
            addedge(b, a, c);
        }
        spfa(dis1, 1);
        spfa(dis2, n);
        int mmin = INF;
        int mmmin = INF;
        for (int i = 1; i <= n; i ++){
            for (int j = head[i]; j != -1; j = e[j].next){
                int tmp = dis1[i] + e[j].w + dis2[e[j].to];
                if (mmin > tmp){
                    mmmin = mmin;
                    mmin = tmp;
                } else if (mmmin > tmp && mmin < tmp){
                    mmmin = tmp;
                }
            }
        } 
        printf("%d\n", mmmin);
    }
    return 0;
}
