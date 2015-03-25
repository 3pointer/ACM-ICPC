#include<stdio.h>
#include<string.h>
#include<ctype.h>

char a[211][321];
const int max(int a, int b)
{
    return a > b ? a : b;
}
void rev(char * s)
{
    int l = strlen(s);
    for (int i = 0; i < l / 2; i++)
    {
        char t = s[i];
        s[i] = s[l - i - 1];
        s[l - i - 1] = t;
    }
}
int main()
{
    int n, B;
    while(scanf("%d%d", &n, &B) != EOF)
    {
        int flag = 0;
        int maxl = -1;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++)
        {
            scanf("%s", a[i]);
            int l = strlen(a[i]);
            maxl = max(l, maxl);
            rev(a[i]);
        }
        for (int i = 0; i < n; i++)
        for (int j = 0; j < maxl; j++)
        {
                if (a[i][j] >= 58)
                    a[i][j] -= 39;
                else
                    if (a[i][j] >= 48)
                    a[i][j] -= 48;
        }
        for (int j = 0; j < maxl; j++)
        {
            for (int i = 1; i <= n; i++)
            { 
                a[i][j] += a[i-1][j];
                a[i][j] %= B;
            }
        }
        int mxl;
        for (mxl = maxl; a[n][mxl] == 0; mxl --);
        for (int i = mxl; i >= 0; i--)
        {
            a[n][i] += 48;
            if (a[n][i] >= 58)
                a[n][i] += 39;
            printf("%c", a[n][i]);
            flag = 1;
        }
        if (flag == 0)
        {
            printf("0");
        }
        printf("\n");
    }
    return 0;
}
