/*************************************************************************
	> File Name: dinic.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年05月09日 星期六 20时12分53秒
 ************************************************************************/

#include <string.h>
#include<iostream>
#include <queue>
using namespace std;
#define N 1000
#define M 10000

struct node{
    int to, next;
    int cap;
}e[M];

int pre[N];
int lev[N];
int head[N];
int tot;
queue<int>q;
int s, t;

void addedge(int a, int b, int c){
    e[tot].to = b;
    e[tot].next = head[a];
    e[tot].cap = c;
    head[a] = tot ++;
}


int bfs(){
    memset(lev, -1, sizeof(lev));
    q.push(s);
    lev[s] = 0;
    while(!q.empty()){
        int cur = q.front(); 
        q.pop();

        for (int i = head[cur]; i != -1; i = e[i].next){
            int to = e[i].to;
            if (lev[to] == -1 && e[i].cap > 0){
                lev[to] = lev[cur] + 1;
                pre[to] = cur;
                q.push(to);
            }
        }
    }
    
    return lev[t] != -1;
}

int dfs(int x, int flow){
    int a;
    if (x == t){
        return flow;
    }
    for (int i = head[x]; i != -1; i = e[i].next){
        int to = e[i].to;
        if (e[i].cap && lev[to] == lev[x] + 1 && (a = dfs(to, min(flow, e[i].cap)))){
            e[i].cap -= a;
            e[i^1].cap += a;
            return a;
        }
    }
    return 0;
}


int dinic(){
    int ansc = 0;
    int tmp;
    while(bfs()){
        while(tmp = dfs(s, 0x3f3f3f3f))
            ansc += tmp;
    }
    return ansc;
}

int main(){


}
