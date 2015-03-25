#include <stdio.h>
#include <math.h>
#define eps 1e-5

double a, b, c, d, l, r;
double f(double x)
{
    return fabs(a * x * x * x + b * x * x + c * x + d);
}

double max2(double x, double y)
{
    return x > y ? x : y;
}

int main()
{
    double ans;
    while(scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &l, &r) != EOF)
    {
        ans = -1.0;
        ans = max2(f(l), f(r));
        if (fabs(a) > eps)
        {
            double delta = 4 * b * b - 12 * a * c;
            if (delta > eps)
            {
                double x1 = ( -2.0 * b - sqrt(delta) ) / (6.0 * a);
                double x2 = ( -2.0 * b + sqrt(delta) ) / (6.0 * a);
                if (l + eps < x1 && x1 + eps < r)
                ans = max2(ans, f(x1));
                if (l + eps < x2 && x2 + eps < r)
                ans = max2(ans, f(x2));
            }
        }
        else if (fabs(b) > eps)
        {
            double x = -1.0 * c/2/b;
            if (l + eps < x && x + eps < r)
                ans = max2(ans, f(x));
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}
