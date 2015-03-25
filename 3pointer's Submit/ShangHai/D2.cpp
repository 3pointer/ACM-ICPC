#include <stdio.h>
#include <string.h>
double map[12][1002];
double v[12][1002];
int main()
{
    int t;
    int nn, mm;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas ++)
    {
        memset(v, 0, sizeof(v));
        scanf("%d%d", &mm, &nn);
        for (int i = 1; i <= nn; i++) 
            for (int j = 1; j <= mm; j++) 
                scanf("%lf", &map[i][j]);

        for (int i = 1; i <= nn; i++)
            for (int j = 1; j <= mm; j++)
                for (int k = 0; k <= i; k++)
                    if (v[i][j] < v[k][j] + map[i-k][j])
                        v[i][j] = v[k][j] + map[i-k][j];
        printf("%.5lf\n", v[nn][mm]);
    }
}
