#include <stdio.h>
#include <string.h>
int n, m;
int rcd[20];
int used[20];
int num[20];

void f(int i)
{
    if (i == n)
    {
        for (int j = 0; j < n; j++)
            printf("%d  ", rcd[j]);
        printf("\n");
        return;
    }
    for (int j = 0; j < m; j++)
    {
        if (used[j] > 0)
        {
            used[j]--;
            rcd[i] = num[j];
            f(i + 1);
            used[j]++;
        }
    }
}

int main()
{
    int val;
    int j;
    while(scanf("%d", &n) != EOF)
    {
        m = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &val);
            for (j = 0; j < m; j++)
            {
                if (num[j] == val)
                {
                    used[j]++;
                    break;
                }
            }
            if (j == m)
            {
                num[m] = val;
                used[m++] = 1;
            }
        }
        f(0);
    }
}
