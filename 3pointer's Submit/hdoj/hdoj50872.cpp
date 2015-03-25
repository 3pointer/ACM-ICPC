#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i,a,n) for(int i = a; i < n; i++)
#define repe(i,a,n) for(int i = a; i <= n; i++)
#define per(i,n,a) for(int i = n; i >= a; i--)
#define clc(a,b) memset(a,b,sizeof(a))
#define INF 0x3f3f3f3f
typedef long long LL;
#define MAXN 1010
int a[MAXN], dp[MAXN], n, cnt[MAXN];

int sloved()
{
    dp[0] = cnt[0] = 1;
    int ans = 1, s = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = cnt[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if(a[j] >= a[i]) continue;
            if(dp[i] < dp[j]+1)
                dp[i] = dp[j]+1, cnt[i] = cnt[j];
            else if(dp[i] == dp[j]+1)
                cnt[i] += cnt[j];
        }
        if(ans < dp[i])
            ans = dp[i], s = i;
    }
    int sum = 0;
    rep(i,0,n) if(ans == dp[i]) sum += cnt[i];
    if(1 == sum) ans--;
    return ans;
}
int main()
{
#ifdef SHY
    freopen("e:\\1.txt", "r", stdin);
#endif
    int t;
    scanf("%d%*c", &t);
    while(t--)
    {
        scanf("%d%*c", &n);
        rep(i,0,n) scanf("%d%*c", &a[i]);
        printf("%d\n", sloved());
    }
    return 0;
}
