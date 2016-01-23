/*************************************************************************
	> File Name: c.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月04日 星期日 09时08分03秒
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;
#define N 550

map<int, int>M;
int n;
int a[N];
int ans[N];
int cnt;

int main(){
    cin >> n;
    for (int i = 0; i < n * n; i ++){
        cin >> a[i];
        M[a[i]] ++;
    }
    map<int, int>::iterator mi;
    for (mi = M.begin(); mi != M.end(); mi ++){
        //cout << mi -> first << endl;
        if (mi->second % 2 == 1)
            ans[cnt++] = mi->first;
    }
    for (int i = 0; i < cnt; i ++)
        cout << ans[i] << " ";
    
    return 0;
}
