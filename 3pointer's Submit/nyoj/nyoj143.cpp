#include <stdio.h>
#include <string.h>

int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800};
int s[20];
int vis[20];

void init()
{
    memset(vis, 0, sizeof(vis));
    memset(s, 0, sizeof(s));
}
int invKT(int n, int k)
{
    int t;
    int j;
    k --;
    for (int i = 0; i < n; i++)
    {
        t = k / fac[n - i - 1];
        for (j = 1; j <= n; j++)
        {
            if (!vis[j])
            {
                if (t == 0)
                    break;
                t --;
            }
        }
        s[i] = j;
        vis[j] = 1;
        k %= fac[n - i - 1];
    }
    return 0;
}
void show()
{
    for (int i = 0; i < 12; i++)
        printf("%c", s[i] + 96);
    printf("\n");
}

int main()
{
    int t;
    int k;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d", &k);
        init();
        invKT(12, k);
        show();
    }
    return 0;
}

