#include<bits/stdc++.h>

using namespace std;

const int N = 100100;
int u[N];
int v[N];

vector< pair<int, pair<int, int> > > e;

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        e.push_back(make_pair(a, make_pair(-b, i)));
    }

    sort(e.begin(), e.end());
    int k = 0;
    int U = 0;
    int V = 2;
    for (auto E : e){
        if (E.second.first == -1){
            u[E.second.second] = k;
            v[E.second.second] = k + 1;
            k ++;
        } else {
            if (V > k){
                cout << -1 << endl;
                return 0;
            }
            u[E.second.second] = U;
            v[E.second.second] = V;
            if (U == V - 2){
                V ++;
                U = 0;
            } else {
                U ++;
            }
        }
    }
    for (int i = 0; i < m; i ++){
        printf("%d %d\n", u[i] + 1, v[i] + 1);
    }
    return 0;
}
