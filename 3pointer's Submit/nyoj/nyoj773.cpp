#include <stdio.h>
#include <math.h>
#define eps 1e-9

int main()
{
    double n, p;
    while(scanf("%lf%lf", &n, &p) && n + p)
    {
        double l = 0;
        double r = 1000000000;
        while(l + eps < r)
        {
            double mid = (l + r)/2.0;        
            if (pow(mid, n) > p)
                r = mid;
            else
                l = mid;
        }
        printf("%.0lf\n", l);
    }
}
