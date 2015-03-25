#include <stdio.h>
#include <algorithm>
#include <iostream>
#define lson l, m, s << 1
#define rson m + 1, r, s << 1 | 1
#define N 100100
using namespace std;

int sum[N << 2];
long long total[200010];
int b[200010];
int aa[N];
struct node
{
    int v, order;
}a[N << 2];

void pushup(int s) {
    sum[s] = sum[s << 1] + sum[s << 1 | 1];
}

void build(int l, int r, int s){
    if (l == r) {
        sum[s] = 0;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(s);
}

void update(int p, int l, int r, int s){
    if (l == r){
        sum[s] += 1;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m)
        update(p, lson);
    else
        update(p, rson);
    pushup(s);
}

int query(int ll, int rr, int l, int r, int s){
    if (ll <= l && r <= rr){
        return sum[s];
    }
    int m = (l + r) >> 1;
    int res = 0;
    if (ll <= m)
        res += query(ll, rr, lson);
    if (rr > m)
        res += query(ll, rr, rson);
    return res;
}

int cmp(node a, node b) {
    return a.v < b.v;
}

int main(){
    int n;
    total[0] = 0;
    for (int i = 1; i <= 100010; i ++)
        total[i] = total[i - 1] + i;

    scanf("%d", &n);
    for (int i = 1; i <= n; i ++){
        scanf("%d", &a[i].v), a[i].order = i; 
    }

    stable_sort(a + 1, a + 1 + n, cmp);

    for (int i = 1; i <= n; i ++){
        aa[a[i].order] = i; 
    }

    build(1, n, 1);
    for (int i = 1; i <= n; i ++){
        b[i] = query(aa[i], n, 1, n, 1);
        update(aa[i], 1, n, 1);
    }

    build(1, n, 1);
    for (int i = n; i >= 1; i --){
        b[i] += query(1, aa[i], 1, n, 1); 
        update(aa[i], 1, n, 1);
    }

    long long sum = 0;
    for (int i = 1; i <= n; i ++){
        sum += total[b[i]];
    }

    cout << sum << endl;
    return 0;
}
