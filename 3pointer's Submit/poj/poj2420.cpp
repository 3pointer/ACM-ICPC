#include <stdio.h>
#include <math.h>
#define N 110
#define eps 1e-10
struct node
{
    double x, y;
}p[N];

double dis(node a, node b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main()
{
    int n;
    node u;
    u.x = 0.0;
    u.y = 0.0;
    double step = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf%lf", &p[i].x, &p[i].y);
        step += fabs(p[i].x) + fabs(p[i].y);
        u.x += p[i].x;
        u.y += p[i].y;
    }
    u.x /= n;
    u.y /= n;

    node v;
    v.x = 0.0;
    v.y = 0.0;
    double minlen;
    double cur, exp;
    int flag = 0;
    while(step > eps)
    {
        step /= 2;
        for (int i = -1; i <=1; i++) 
        for (int j = -1; j <=1; j++) 
        {
            v.x = u.x + step * i;
            v.y = u.y + step * j;
            cur = exp = 0.0;
            for (int k = 0; k < n; k++)
            {
                cur += dis(u, p[k]);
                exp += dis(v, p[k]);
            }
            if (exp < cur)
                u = v;
        }
    }
    double res = 0;
    for (int i = 0; i < n; i ++)
        res += dis(u, p[i]);
    printf("%.0lf\n", res);

    return 0;
}
