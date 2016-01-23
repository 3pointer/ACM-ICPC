#include<bits/stdc++.h>

const int N = 1011;
const int INF = 0x3f3f3f3f;

using namespace std;

int ma[N][N];
int ma2[N][N];
    int n, m;

void floyd(){
    for (int k = 1; k <= n; k ++){
        for (int i = 1; i <= n; i ++){
            for (int j = 1; j <= n; j ++){
                ma[i][j] = min(ma[i][j], ma[i][k] + ma[k][j]);
            }
        }
    }
}
void floyd2(){
    for (int k = 1; k <= n; k ++){
        for (int i = 1; i <= n; i ++){
            for (int j = 1; j <= n; j ++){
                ma2[i][j] = min(ma2[i][j], ma2[i][k] + ma2[k][j]);
            }
        }
    }
}


int main(){
    cin >> n >> m;

    memset(ma, INF, sizeof(ma));
    memset(ma2, INF, sizeof(ma2));
    int a, b;

    while(m --){
        cin >> a >> b;
        ma[a][b] = ma[b][a] = 1;
    }

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            if (i != j && ma[i][j] == INF){
                ma2[i][j] = ma2[j][i] = 1;
            }
        }
    }
    floyd();
    floyd2();

    if (ma[1][n] != INF && ma2[1][n] != INF)
        cout << max(ma[1][n], ma2[1][n]) << endl;
    else
        cout << -1 << endl;
    return 0;
}
