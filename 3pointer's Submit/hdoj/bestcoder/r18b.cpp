#include <stdio.h>
#include <math.h>
#define eps 1e-8
#define eps2 1e-10

inline double max2(double a, double b)
{
    return a > b ? a : b;
}
double a, b, c, d, l, r;
double f(double x)
{
    return fabs(a * x * x * x + b * x * x + c * x + d);
}
double daof(double x)
{
    return 3 * a * x * x + 2 * b * x + c;
}
double ce()
{
    return -2.0 * b / (6 * a);
}
double max3(double a, double b, double c)
{
    double t;
    if (a < b)
        t = a, a = b, b = t;
    if (b < c)
        t = b, b = c, c = t;
    if (a < b)
        t = a, a = b, b = t;
    return a;
}
int main()
{
    double mmin, mmax;
    while(scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &l, &r) != EOF)
    {
        double tl = l;
        double tr = r;
        if (daof(tl) < eps && daof(tr) < eps)
        {
            mmin = f(tl);
            mmax = f(tr);
            printf("%.2lf\n", mmax > mmin ? mmax : mmin);
        }
        else if (daof(tl) * daof(tr) < eps)
        {
            while(tl + eps < tr)
            {
                double mid = (tl + tr) / 2.0;
                if (daof(mid) > eps2)
                    tr = mid;
                else
                    tl = mid;
            }
            printf("%.2lf\n", max3(f(l), f(r), f(tl)));   
        }
        else
        {
            if (ce() > tr || ce() < tl)
            {
                mmin = f(tl); 
                mmax = f(tr);
                printf("%.2lf\n", mmax > mmin ? mmax : mmin);
            }
            else
            {
                double temp = ce();
                while(tl + eps < temp)
                {
                    double mid = (tl + temp) / 2.0;
                    if (daof(mid) > eps2)
                        temp = mid;
                    else
                        tl = mid;
                }
                temp = ce();
                while(temp + eps < tr)
                {
                    double mid = (tr + temp) / 2.0;
                    if (daof(mid) > eps2)
                        tr = mid;
                    else
                        temp = mid;
                }
                double ans1 = max2(f(l), f(tl));
                double ans2 = max2(f(tr), f(r));
                printf("%.2lf\n", max2(ans1, ans2));
            }
        }
    }
    return 0;
}
