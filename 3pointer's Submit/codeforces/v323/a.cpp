/*************************************************************************
	> File Name: a.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月04日 星期日 08时40分09秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define N 55

int h[N];
int v[N];
int ans[N * N];

int main(){
    int n;
    int a, b;
    int cnt = 0;
    cin >> n;

    for (int i = 0; i < n * n; i ++){
        cin >> a >> b;
        if (h[a] || v[b])
            continue;
        h[a] = 1;
        v[b] = 1;
        ans[cnt ++ ] = i + 1; 
    }
    for (int i = 0; i < cnt; i ++)
        cout << ans[i] << " ";
    return 0;
}
