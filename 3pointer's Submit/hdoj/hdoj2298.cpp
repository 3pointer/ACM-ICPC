#include <stdio.h>
#include <math.h>
#define G 9.8
#define PI 4 * atan(1)
#define eps 1e-12

double x, y, v;
inline double fun(double s)
{
    return x * tan(s) - ((x * x * 0.5 * G / (v * v)) * (tan(s) * tan(s) + 1));
}

double delta(double x, double y, double v)
{
    return (x * x) - 4 * (G * 0.5 * x * x / (v * v)) * ((G * 0.5 * x * x / (v * v)) + y);
}
double ans(double x, double y, double v)
{
    return (-1 * x) / (-1 * G * x * x / (v * v)) - sqrt(delta(x, y, v));
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf%lf%lf", &x, &y, &v);
        double l = 0;
        double r = PI * 0.5;
        while(l + eps < r)
        {
            double mid = (l + r) * 0.5;
            double mmid = (mid + r) * 0.5;
            if (fun(mid) > fun(mmid))
                r = mmid;
            else
                l = mid;
        }
        if (y > fun(l))
        {
            printf("-1\n");
            continue;
        }
        double left = 0;
        while (left + eps < l)
        {
            double mid = (left + l) * 0.5;
            if (fun(mid) - y > 0)
                l = mid;
            else 
                left = mid;
        }
        printf("%lf\n", l);
        /*
        if (delta(x, y, v) < 0)
        {
            printf("-1\n");
            continue;
        }
        printf("%lf\n", atan(ans(x, y, v)));
        */
    }
}
