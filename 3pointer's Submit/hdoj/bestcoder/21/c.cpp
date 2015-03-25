#include <iostream>
#include <cstdio>
const int N = 100000 + 10;
 
using namespace std;
 
int a[N], dp[N];
 
int bs(int k, int len)
{
    int right = len;
    int left = 1;
    int mid = (right + left) >> 1;
    while(left <= right)
    {
        if(k == dp[mid])
            return mid;
        if(k > dp[mid])
            left = mid + 1;
        else
            right = mid - 1;
        mid = (right + left) >> 1;
    }
    return left;
}
 
int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        int len, t;
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        len = 1;
        dp[1] = a[0];
        for(int i = 1; i < n; ++i)
        {
            t = bs(a[i], len);
            dp[t] = a[i];
            if(t > len)
                len = t;
        }
        if (len == n)
        {
            printf("1\n");
            continue;
        }
        for (int i = 0; i < n; i ++)
        {
            for (int j = i; j < n; j++)
            {
                for (int k = j; k < n; k++)
                    
            }
        }
    }
    return 0;
}
