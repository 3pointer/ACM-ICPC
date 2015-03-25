#include <stdio.h>

int a[10010];
int dp[10010];

int bs(int x, int len)
{
    int l = 1;
    int r = len;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if (dp[mid] == x)
            return mid;
        else if (dp[mid] > x)
            r = mid - 1;        
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i ++)
            scanf("%d", &a[i]);

        int len = 1;
        dp[1] = a[0];

        for (int i = 0; i < n; i++)
        {
            int t = bs(a[i], len);
            dp[t] = a[i];
            if (len < t)
                len = t;
        }
        printf("%d\n", len);
    }
    return 0;
}
