#include<iostream>
#include <stdio.h>
#include<set>
using namespace std;

int main(){

    int n, m;
    while(~scanf("%d%d", &n, &m)){
        set<pair<int, int> > a;
        int h;
        for (int i = 0; i < n; i ++){
            scanf("%d", &h);
            a.insert(make_pair(h, i));
        }
        for (int i = 0; i < m; i ++){
            int q;
            scanf("%d", &q);
            set<pair<int, int> > :: iterator it = a.lower_bound(make_pair(q, 0));
            if (it == a.end() || it -> first != q){
                puts("-1");
            } else {
                printf("%d\n", it->second + 1);
                a.erase(it);
            }
        }
    }
    return 0;
}
