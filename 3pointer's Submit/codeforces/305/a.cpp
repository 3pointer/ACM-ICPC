#include<stdio.h>
#include<string.h>

bool ok(char *s, int len){
    for (int i = 0; i < len / 2; i ++)
        if (s[i] != s[len - i - 1])
            return 0;
    return 1;
}
int main(){
    int k;
    char s[1010];
    scanf("%s", s);
    scanf("%d", &k);
    int l = strlen(s);

    int flag = 1;
    if (l % k)
        flag = 0;

    int x = l / k;

    if (k > l)
        flag = 0;
    for (int i = 0; i * x < l && flag; i ++)
        if (ok(s + i * x, x) == 0)
            flag = 0;
    if (flag == 0)
        puts("NO");
    else
        puts("YES");
    return 0;
}
