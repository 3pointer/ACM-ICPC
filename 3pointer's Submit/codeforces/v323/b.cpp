/*************************************************************************
	> File Name: b.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月04日 星期日 08时56分13秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define N 1010

int a[N];
int vis[N];
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }
    int cnt = 0;
    int i;
    int ans = -1;
    i = 0;
    while(1){
        if (cnt == n){
            break;
        }
        ans ++;
        for (i = 0; i < n; i ++){
            if(!vis[i] && a[i] <= cnt)
                cnt ++, vis[i] = 1;
        }
        if (cnt == n){
            break;
        }
        ans ++;
        for (i = n - 1; i >= 0; i --)
            if (!vis[i] && a[i] <= cnt)
                cnt ++, vis[i] = 1;
    }
    cout << ans << endl;
    return 0;
}
