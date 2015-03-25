#include <stdio.h>
#include <math.h>
#define eps 1e-5
#define eps2 1e-10
#define PI acos(-1)

int main()
{
	double R, r;
	while(scanf("%lf %lf", &R, &r) != EOF)
	{
		double ll = 0.0;
		double rr = 2 * R;
		double area = PI * R * R;
		double x, mid, sinsta, arear, areaR, areatr;
        double rate;
		while (ll + eps < rr)	
		{
			mid = (ll + rr) * 0.5;
			sinsta = ((mid * 0.5) / R);
			x = asin(sinsta);
            areatr = x / 2 / PI * area;
            arear = areatr - (R * cos(x) * (mid / 4));
            areaR = area / 2 - arear;
            rate = arear / areaR;
            if (rate - r < eps2)
                ll = mid;
            else
                rr = mid;
		}
        printf("%.2f\n", ll);
	}	
	return 0;
}
