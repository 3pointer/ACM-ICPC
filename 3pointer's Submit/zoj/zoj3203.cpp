#include <stdio.h>
#define eps 1e-6

double D, H, h;

double fun(double x)
{
    return D + H - x - D * (H - h)/x;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf %lf %lf", &H, &h, &D);
        double left = (H - h) * D / H;
        double right = D;
        while (left + eps < right)
        {
            double mid = (left + right)/2.0;
            double midmid = (mid + right)/2.0;
            if (fun(mid) > fun(midmid))
                right = midmid;
            else
                left = mid;
        }
        printf("%.3lf\n", fun(left));
    }
}
