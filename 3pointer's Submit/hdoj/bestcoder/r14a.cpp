#include <stdio.h>
int main()
{
    int a, b;
    while(scanf("%d%d", &b, &a) != EOF)
        printf("%d\n", 2 * b - a);
    return 0;
}

