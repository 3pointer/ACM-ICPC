#include <stdio.h>
#include <string.h>

int next[100000];
char str[100000];
int len;

void getnext()
{
    int j = -1;
    int i = 0;
    next[0] = -1;
    while(i < len)
    {
        if (j == -1 || str[j] == str[i])
            next[++i] = ++j;
        else
            j = next[j];
    }
}
int main()
{
    while(scanf("%s", str) && str[0] != '.')
    {
        len = strlen(str);
        getnext();
        if (len % (len - next[len]) == 0)
            printf("%d\n", len / (len - next[len]));
        else
            printf("1\n");
    }
    return 0;
}
