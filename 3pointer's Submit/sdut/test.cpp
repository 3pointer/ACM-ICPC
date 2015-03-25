#include <stdio.h>
#include <math.h>

int main()
{
    double a = 1;
    double b = 38.98;
    double c = 39;
    printf("%lf\n", acos((a * a - b * b - c * c)/(2 * b *c)));
    return 0;
}
