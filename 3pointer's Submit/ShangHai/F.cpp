#include <stdio.h>

int main(){
    int i;
    int t;
    double n;
    double s;
    scanf("%d",&t);
    for (i = 1; i <= t; i++)
    {
        scanf("%lf",&n);
        s = 8 * n * n - 7 * n + 1;
        printf("Case #%d: %.0lf\n", i, s);           
    }
    return 0;    
}
