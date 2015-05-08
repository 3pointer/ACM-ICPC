/*************************************************************************
	> File Name: tarjan.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年05月08日 星期五 16时10分39秒
 ************************************************************************/

#include<iostream>
using namespace std;

void tarjanD(int u){
    low[u] = dfn[u] = ++ cnt;
    vis[u] = 1;
    s.push(u);

    for (int i = head[u]; i != -1; i = e[i].next){
        int t = e[i].to;
        if (!dfn[t]){
            tarjan(t);
            low[u] = min(low[u], low[t]);
        } else {
            low[u] = min(low[u], dfn[t]);
        }
    }
    if (dfn[u] == low[u]){
        bcnt ++; 
        do{
            j = s.pop(); 
            vis[j] = 0;
            belong[j] = bcnt;
        }while(u != v)
    }
}

void tarjanB(int u, int pre){
    low[u] = dfn[u] = ++id;
    s.push(u);
    for (int i = head[u]; i != -1; i = e[i].next){
        int t = e[i].to;
        if (t == pre)
            continue;
        if (!dfn[t]){
            cnt ++;
            tarjanB(t, u);
            low[u] = min(low[u], low[v]);
            if (u != pre && dfn[u] <= low[t]){
                cut_p[u] = true;
                sub[u] +=;
            }
            if (dfn[u] < low[t]){
                cut_e[i] = true;
            }
        } else {
            low[u] = min(low[u], dfn[t]);
        }
    }
    if (dfn[u] == low[u]){
        do{
            bcc ++;
            v = s.pop();
            belong[v] = bcc;
        }while(u != v);
    }
    if (u == pre && cnt > 1){
        cut_p[u] = true;
        sub[u] = cnt - 1;
    }
}
