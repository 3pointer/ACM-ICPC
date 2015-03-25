#include <stdio.h>
//#include<unistd.h>
#include <math.h>
#include <string.h>
#define eps 1e-5
#define INF 10000000.0
#define N 1090

double dis[N][N];
double lowcost[N];
double ans;
bool vis[N];
double x[N], y[N], z[N];
int n;

void distan_init()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
        {   
            dis[i][j] = dis[j][i] = sqrt((double)((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])));
        }
}
double prim(double x)
{
    double tmp;    
    int k;
    double sum = 0.0;

    memset(vis, 0, sizeof(vis));

    vis[1] = 1;
    for (int i = 1; i <= n; i++)
        lowcost[i] = fabs(z[1] - z[i]) - x * dis[1][i];

    for (int i = 2; i <= n; i++)
    {
        tmp = -INF;
        for (int j = 2; j <= n; j++)
            if (!vis[j] && tmp < lowcost[j])
                tmp = lowcost[k = j];

        vis[k] = 1;
        sum += tmp;

        for (int j = 1; j <= n; j++)
            if (!vis[j] && lowcost[j] < fabs(z[k] - z[j]) - x * dis[k][j])
                lowcost[j] = fabs(z[k] - z[j]) - x * dis[k][j];    
    }
    //printf("%.10lf\n", sum);
    //sleep(1);
    return sum;
}

int main()
{
    while(scanf("%d", &n) && n)
    {
        for (int i = 1; i <= n; i++)
			scanf("%lf%lf%lf", &x[i], &y[i], &z[i]);
            
        distan_init();
        /*
        double a, b;
        b = 1.0;
        while(1)
        {
            a = prim(b);
            //printf("%f\n", a - b);
            //sleep(1);
            if (fabs(a - b) < eps)
                break;
            b = a;
        }
        */
        double l = 0.0;
        double r = 1000.0;
        double mid;
        while(l + eps < r)
        {
            mid = (l + r) * 0.5;
            if (prim(mid) > eps)
                l = mid;
            else 
                r = mid;
        }
        printf("%.3f\n", mid);
    }
    return 0;
}
