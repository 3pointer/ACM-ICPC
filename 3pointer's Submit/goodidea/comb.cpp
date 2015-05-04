#include <stdio.h>
int a[10];
int b[10];
int top = 0;
int n, m;

void f(int c)
{
    if (c > n)
        return;
    if (top == m)
    {
        for (int i = 0; i < m; i++)
            printf("%d ", b[i]);
        printf("\n");
        return;
    }
    b[top++] = a[c];
    f(c + 1);
    top--;
    f(c + 1);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        a[i] = n - i;
    f(0);
}
