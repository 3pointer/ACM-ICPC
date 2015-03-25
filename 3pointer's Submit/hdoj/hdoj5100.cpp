#include <stdio.h>

int main()
{
    int t;
    int n, k;
    scanf("%d", &t);
    while(t--)
    {
        int ans;
        scanf("%d%d", &n, &k);
        int s = n % k;
        if (n < k)
            ans = n * n;
        else if (s <= k / 2)
            ans = s * s;
        else 
            ans = (k - s) * (k - s);
        printf("%d\n", n * n - ans);
    }

    return 0;
}
