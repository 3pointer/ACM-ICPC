#include <stdio.h>

int gcd(int a, int b)
{
    return b == 0? a : gcd(b, a%b);
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if ((c + 2) % gcd(a + 2, b + 2) || c < a + b + 2)
            printf("No.\n");
        else
            printf("Yes.\n");
    }
    return 0;
}
