#include<bits/stdc++.h>
using namespace std;

#define N 5000

int ans[N];
int v[N], p[N], d[N];
int q[N];
int status[N];
int cou;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++){
        cin >> v[i] >> d[i] >> p[i];
        status[i] = 1;
    }

    for (int i = 0; i < n; i ++){
        if (status[i] ==  2){
            continue;
        }
        ans[cou ++] = i;
        int left = 0, right = 0;
        for (int j = i + 1, cnt = 0; j < n && cnt <= v[i]; j++){
            if (status[j] == 2)
                continue;
            p[j] -= v[i] - cnt;
            cnt ++;
            if (p[j] < 0){
                status[j] = 2;
                q[right ++] = j;
            }
        }

        while(left < right){
            for (int j = q[left] + 1; j < n; j ++){
                if (status[j] == 2)
                    continue;
                p[j] -= d[q[left]];
                if (p[j] < 0){
                    status[j] = 2;
                    q[right ++] = j;
                }
            }
            left ++;
        }
    }
    cout << cou << endl;
    for (int i = 0; i < cou; i ++)
        cout << ans[i] + 1 << " ";

    return 0;
}
