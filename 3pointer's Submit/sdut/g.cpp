#include <stdio.h>
int main()
{
    int n;
    while(scanf("%d", &n)&&n)
    {
        //if (~n << (32 - (int)log2(n))== 0)
        if (((n + 1) & n) == 0)
            printf("Bob\n");
        else
            printf("Alice\n");
    }
    return 0;
}
