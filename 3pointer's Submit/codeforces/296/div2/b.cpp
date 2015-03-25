#include <stdio.h>

char s[200010];
char t[200010];
int a[200100];
int main()
{
    int n;
    int x, y;
    while(scanf("%d", &n) != EOF)
    {
        int tot = 0;
        int flag = 1;
        x = -1;
        y = -1;
        scanf("%s", s);
        scanf("%s", t);
        for (int i = 0; i < n; i ++)
        {
            if (s[i] != t[i])
                a[tot++] = i;
        }
        
        for (int i = 0; i < tot && flag; i ++)
        {
            for (int j = i; j < tot && flag; j ++)
            {
                if (s[a[i]] == t[a[j]] && s[a[j]] == t[a[i]]) 
                {
                    flag = 0;
                    x = a[i];
                    y = a[j];
                    break;
                }
                else if (s[a[i]] == t[a[j]] || s[a[j]] == t[a[i]]) 
                {
                    x = a[i];
                    y = a[j];
                }
            }
        }
        if (flag == 0)
            printf("%d\n%d %d\n", tot - 2, x + 1, y + 1);
        else if (x != -1)
            printf("%d\n%d %d\n", tot - 1, x + 1, y + 1);
        else
            printf("%d\n-1 -1\n", tot);
    }
    return 0;
}
