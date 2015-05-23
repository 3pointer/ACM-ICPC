#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

using namespace std;

#define N 50010

#define lson s << 1
#define rson s << 1 | 1

#define Pair pair<double, Node>
#define sqrt2(x) (x) * (x)

int n, k, idx;

struct Node{
    int feature[5];
    bool operator < (const Node & u) const{
        return feature[idx] < u.feature[idx];
    }
}_data[N];

priority_queue<Pair> Q;

class KDTree{

    public:
        void Build(int, int, int, int);
        void Query(Node, int, int, int);

    private:
        Node data[4 * N];
        int flag[4 * N];

}kd;

void KDTree::Build(int l, int r, int s, int dept){
    if (l > r)
        return ;
    flag[s] = 1;
    flag[lson] = flag[rson] = -1;
    idx = dept % k;
    int mid = (l + r) >> 1;
    nth_element(_data + l, _data + mid, _data + r + 1);
    data[s] = _data[mid];
    Build(l, mid - 1, lson, dept + 1);
    Build(mid + 1,r,  rson, dept + 1);
}

void KDTree::Query(Node p, int m, int s, int dept){
    if (flag[s] == -1){
        return;
    }
    Pair cur(0, data[s]);
    for (int i = 0; i < k; i ++){
        cur.first += sqrt2(cur.second.feature[i] - p.feature[i]);
    }
    int dim = dept % k;
    bool fg = 0;
    int x = lson;
    int y = rson;
    if (p.feature[dim] >= data[s].feature[dim])
        swap(x, y);
    if (~flag[x])
        Query(p, m, x, dept + 1);
    if (Q.size() < m){
        Q.push(cur);
        fg = 1;
    } else {
        if (cur.first < Q.top().first){
            Q.pop();
            Q.push(cur);
        }
        if (sqrt2(p.feature[dim] - data[s].feature[dim]) < Q.top().first){
            fg = 1;
        }
    }
    if (~flag[y] && fg){
        Query(p, m, y, dept + 1);
    }
}


int main(){

    while(scanf("%d%d", &n, &k) != EOF){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < k; j ++){
                scanf("%d", &_data[i].feature[j]);
            }
        }
        kd.Build(0, n - 1, 1, 0);
        int t, m;
        scanf("%d", &t);
        while(t --){
            Node p;
            for (int i = 0; i < k; i ++){
                scanf("%d", &p.feature[i]);
            }
            scanf("%d", &m);
            while(!Q.empty()){
                Q.pop();
            }
            kd.Query(p, m, 1, 0);
            printf("the closest %d points are:\n", m);
            Node tmp[25];
            for (int i = 0; !Q.empty(); i ++){
                tmp[i] = Q.top().second;
                Q.pop();
            }
            for (int i = m - 1; i >= 0; i --){
                for (int j = 0; j < k; j ++){
                    printf("%d%c", tmp[i].feature[j], j == k - 1 ? '\n' : ' ');
                }
            }
        }
    }
    return 0;
}

