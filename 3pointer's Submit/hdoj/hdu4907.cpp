#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 100001

int num[N];
int pos[N];
bool vis[N];

int main()
{
    int n, m, t, q;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &num[i]);
            vis[num[i]] = 1;
        }
        sort(num + 1, num + n + 1);
        for (int i = 1; i <= n; i++)
            pos[num[i]] = i;
        while(m --) 
        {
            scanf("%d", &q);
            if (vis[q] == 0)
            {
                printf("%d\n", q);
                continue;
            }
            int l = pos[q];
            int r = n;
            int mid = 0;
            while(l <= r)
            {
                mid = (l + r)/2;
                if (num[mid] - num[l] == mid - l)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            printf("%d\n", l);
        }
    }
}
