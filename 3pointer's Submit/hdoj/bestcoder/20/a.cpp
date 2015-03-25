#include <stdio.h>
#include <string.h>

int vis[300];
inline int max(int a, int b)
{
    return a > b? a: b;
}

int main()
{
    int t;
    int n;
    int x;
    scanf("%d", &t);
    while(t--)
    {
        int ma = -1;
        memset(vis, 0, sizeof(vis));
        int k;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            vis[x]++;
        }
        for (int i = 0; i < 101; i ++)
            if (vis[i] > ma)
            {
            ma = vis[i];
            k = i;
            }
        printf("%d\n", k);
    }



    return 0;
}
