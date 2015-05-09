/*************************************************************************
	> File Name: hungury.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年05月09日 星期六 21时12分10秒
 ************************************************************************/

#include<iostream>
using namespace std;


//DAG

int dfs(int u){
    for (int i = head[u]; i != -1; i = e[i].next){
        int v = e[i].to;
        if (!vis[v]){
            vis[v] = 1;
            if (link[v] == -1 || dfs(link[v])){
                link[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int hungury(){
    int con = 0;
    memset(link, -1, sizeof(link));
    for (int i = 0; i < n; i ++){
        memset(vis, 0, sizeof(vis));
        if (dfs(i))
            con ++;
    }
    return con;
}


//无向
//两个集合

int dfs(int u){
    for (int i = head[u]; i != -1; i = e[i].next){
        int v = e[i].to;
        if (!vis[v]){
            vis[v] = 1;
            if (linky[v] == -1 && dfs(linky[v])){
                linky[v] = u;
                linkx[u] = v;
                return 1;
            }
        }
    }
    return 0;
}

int hungury(){
    int con = 0;
    memset(linky, -1, sizeof(linky));
    memset(linkx, -1, sizeof(linkx));
    for (int i = 1; i <= n; i ++){
        if (linkx[i] == -1){
            memset(vis, 0, sizeof(vis));
            con += dfs(i);
        }
    }
    return con;
}


//一个集合
int dfs(int u){
    for (int i = head[u]; i != -1; i = e[i].next){
        int v = e[i].to;
        if (!vis[v]){
            vis[v] = 1;
            if (linky[v] == -1 && dfs(linky[v])){
                linky[v] = u;
                linky[u] = v;
                return 1;
            }
        }
    }
    return 0;
}

int hungury(){
    int con = 0;
    memset(linky, -1, sizeof(linky));
    for (int i = 1; i <= n; i++){
        if (linky[i] == -1){
            memset(vis, 0, sizeof(vis));
            con += dfs(i);
        }
    }
    return con;
}
