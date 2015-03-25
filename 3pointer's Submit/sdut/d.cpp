#include <stdio.h>
#include<math.h>
#define eps 1e-8
#define PI acos(-1)

void sor(double &a, double &b, double &c)
{
    double t;
    if (a > b) 
        t = a, a = b, b = t;
    if (b > c)
        t = b, b = c, c = t;
    if (a > b)
        t = a, a = b, b = t;

    t = c;
    c = b;
    b = t;
}
double angle(double a, double b, double c)
{
    double xa = ((double)acos((b * b + c * c - a * a )/ (2 * b * c)));
    //double xb = (acos(b * b - a * a - c * c / (2 * a * c)));
    //double xc = (acos(c * c - b * b - a * a / (2 * b * a)));

    return xa;
}
double langle(double a, double b)
{
    if (a > b)
    {
        double x = a - b;
        double y = a + b;
        double z = 2 * sqrt(a * b);
        return angle(z, x, y);
    }
    else
    {
        double x = b - a;
        double y = a + b;
        double z = 2 * sqrt(a * b);
        return angle(x, z, y) + PI / 2.0;
    }
}
double f(double a, double b, double c, double d)
{
    double temp = 2 * PI - a - b - c;
    temp /= 2.0;
    return (double)tan(temp) * d;
}
int main()
{
    int n;
    double r1, r2, r3;
    double ra, rb, rc;
    scanf("%d", &n);
    while(n --)
    {
        scanf("%lf%lf%lf", &r1, &r2, &r3);
        sor(r1, r2, r3);
        ra = r1 + r2;
        rb = r2 + r3;
        rc = r1 + r3;

        double rA = angle(ra, rb, rc);
        double rB = angle(rb, ra, rc);
        double rC = angle(rc, rb, ra);

        double rAl = langle(r3, r2);
        double rAr = langle(r3, r1);
        double rBl = langle(r1, r2);
        double rBr = langle(r1, r3);
        double rCl = langle(r2, r1);
        double rCr = langle(r2, r3);

        double d3 = f(rA, rAl, rAr, r3);
        double d1 = f(rB, rBl, rBr, r1);
        double d2 = f(rC, rCl, rCr, r2);
        if (d3 < eps || d2 < eps || d1 < eps)
        {
            printf("No Solution!\n");
            continue;
        }
        double a = d3 + d2 + 2 * sqrt(r3 * r2);
        double b = d3 + d1 + 2 * sqrt(r3 * r1);
        double c = d1 + d2 + 2 * sqrt(r1 * r2);

        double s = (a + b + c) * 0.5;
        printf("%.3lf\n", sqrt(s * (s - a) * (s - b) * (s - c)));
    }
    return 0;
}
