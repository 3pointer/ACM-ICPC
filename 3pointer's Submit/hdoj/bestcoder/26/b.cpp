#include <stdio.h>
int main()
{
int t;
scanf("%d", &t);
int x, b, cou = 1;
while(t--)
{
double ans = 1.0;
scanf("%d%d", &x, &b);
double t = ((double)(x-1))/x;
while(b--)
ans*=t;
ans = (1-ans) * x * (x + 1) / 2;
printf("Case #%d: %.3lf\n", cou++, ans);
}

return 0;
}
