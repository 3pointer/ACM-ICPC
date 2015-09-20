#include <stdio.h>
#include <string.h>
#include <queue>
#define N 100100
using namespace std;

int indegree[N];
int soc[N];
int inq[N];
int head[N];
int tot;
int cou;
int n, m, k;

struct node{
    int to, next;
}e[N << 2];

void init(){
    memset(head, -1, sizeof(head));
    memset(indegree, 0, sizeof(indegree));
    memset(inq, 0, sizeof(inq));
    tot = 0;
    cou = 0;
}

void addedge(int a, int b){
    e[tot].next = head[a];
    e[tot].to = b;
    head[a] = tot ++;
}

void work(){
    priority_queue<int>q;
    for (int i = 1; i <= n; i++){
        if (indegree[i] <= k){
            q.push(i);
            inq[i] = 1;
        }
    }

    while(!q.empty()){
        int cur = q.top();
        q.pop();

        if (indegree[cur] > k){
            inq[cur] = 0;
            continue;
        }

        k -= indegree[cur];

        for (int i = head[cur]; i != -1; i = e[i].next){
            int t = e[i].to;
            indegree[t] --;
            if (!inq[t] && indegree[t] <= k){
                q.push(t);
                inq[t] = 1;
            }
        }
        soc[cou++] = cur;
    }
}
int main(){
    int a, b;
    while(scanf("%d%d%d", &n, &m, &k) != EOF){
        init();
        while(m --){
            scanf("%d%d", &a, &b);
            addedge(a, b);
            indegree[b]++;            
        }
        work();
        for (int i = 0; i < cou - 1; i ++){
            printf("%d ", soc[i]);
        }
        printf("%d\n", soc[cou - 1]);
    }
    return 0;
}
