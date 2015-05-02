#include <queue>
#include<iostream>
#include<stdio.h>
#include <string.h>
#include <vector>
#include<algorithm>
using namespace std;

struct node{
    int value;
    int loc;
};

struct no{
    int value;
    int ret;
};

vector<no>H;
vector<node> v;
int n, m;
int a[1021][1021];
int q[100210];
int d[4][2] = {0, -1, 0, 1, 1, 0, -1, 0};

int father[2000210];

bool ok(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m);
}
int find(int x){
    if (x == -1){
        return -1;
    }
    return father[x] == x ? x : father[x] = find(father[x]);
}

int cmp(node a, node b){
    return a.value > b.value;
}

int ans;

void un(int k){
    int row = v[k].loc / m;
    int col = v[k].loc % m;
    //printf("%d %d\n", row, col);

    int root = v[k].loc;
    int high = v[k].value;

    if (find(root) == -1){
        ans ++;
        father[root] = root;
    }

    for (int i = 0; i < 4; i ++){
        int tx = row + d[i][0];
        int ty = col + d[i][1];

        if (ok(tx, ty)){
            if (a[tx][ty] >= high){
                int tmp = find(tx * m + ty);
                if (tmp != father[root] && tmp != -1){
                    ans --;
                    father[tmp] = root;
                }
            }
        }
    }
}

int main(){
    int t;
    scanf("%d%d", &n, &m);

    memset(father, -1, sizeof(father));
    ans = 0;

    node tmp;
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            scanf("%d", &a[i][j]);
            tmp.value = a[i][j];
            tmp.loc = i * m + j;
            v.push_back(tmp);
        }
    }

    scanf("%d", &t);
    for (int i = t - 1; i >= 0; i --)
        scanf("%d", &q[i]);

    sort(v.begin(), v.end(), cmp);

    no ttmp;
    ttmp.value = 2000000000;
    ttmp.ret = 0;
    H.push_back(ttmp);

    int re = 0;
    un(0);
    for (int i = 1; i <= n * m; i ++){
        if (v[i].value != v[i - 1].value){
            ttmp.value = v[i - 1].value;
            ttmp.ret = ans;
            H.push_back(ttmp);
        }
	if (i == n * m)
		break;
        un(i);
    }

    /*
    for (int i = 0; i < t;){
        ttmp = H.front();
        H.pop();

        while (q[i] >= H.front().value){
            i ++;
            aaa[ccc ++] = ttmp.ret;
            if (H.empty())
                break;
        }
    }
    */

    int flag = 1;
    int tot = H.size() - 1;
    for (int i = t - 1; i >= 0; i --){
        while(q[i] >= H[tot].value)
            tot --;
        if (flag == 1){
            printf("%d", H[tot].ret);
            flag = 0;
        }
        else
            printf(" %d", H[tot].ret);
    }
printf("\n");
    return 0;
}
