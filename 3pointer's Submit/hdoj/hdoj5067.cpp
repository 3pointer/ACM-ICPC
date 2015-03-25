#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

int n, m;
vector<pair<int, int> >a;
int dp[1 << 12][12];

inline int min(int a, int b)
{
    return a > b?b : a;
}

int dis(int i, int j)
{
    return (abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second));
}

int main()
{
    int x;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        a.clear();
        for (int i = 0; i < n; i ++)
        {
            for (int j = 0; j < m; j ++)
            {
                scanf("%d", &x);
                if (x || (i == 0 && j == 0))
                a.push_back(make_pair(i, j));
            }
        }
        int s = 1 << a.size();
        int l = a.size();

        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;
        for (int i = 0; i < l; i ++)
            dp[1<<i][i] = dis(0, i);

        for (int i = 0; i < s; i ++)
        {
            for (int j = 0; j < l; j ++)
            {
                for (int k = 0; k < l; k ++)
                {
                    //if (i & 1 << k != 0) continue; 判断只走一遍
                    //dp[i|(1 << k)][k] = min(dp[i|(1 << k)][k], dp[i][j] + dis(j, k));
                    dp[i][j] = min(dp[i][j], dp[i^(1 << j)][k] + dis(j, k));
                }
            }
        }
        printf("%d\n", dp[s - 1][0]);
    }
    return 0;
}
