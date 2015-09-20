#include<iostream>
#include <string.h>
#include<stdio.h>
using namespace std;

int n, m;
int vis[10];
struct node
{
    int x;
    char s[3];
}a[10];

int main(){

    int t;
    int x;
    int y;
    scanf("%d", &t);
    while(t --){
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= 5; i ++){
            scanf("%1s%d", a[i].s, &a[i].x);
            y = a[i].s[0] % 32;
            vis[y] ++;
        }
        int mmax = -1;
        int k;
        for (int i = 1; i <= 4; i ++){
            if (vis[i] > mmax)
                mmax = vis[i];
                k = i;
        }

        memset(vis, 0, sizeof(vis));
        int tot = 0;
        for (int i = 1; i <= 5; i ++){
            if (a[i].s[0] == k + 64){
                vis[tot ++] = a[i].x;
            }
        }
        if (tot == 5){

        }


    }
    return 0;
}

