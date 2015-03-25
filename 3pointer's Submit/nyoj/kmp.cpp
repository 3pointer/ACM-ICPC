#include<stdio.h>
#include<string.h>
#define N 1000005
#include <stdio.h>
#define M 200
int fa[1000];
int nextval[N];  
int len;  

void getnext(const int *s)  
{  
    int i = 0, j = -1;  
    nextval[0] = -1;  
    while(i != M)  
    {  
        if(j == -1 || s[i] == s[j])  
        nextval[++i] = ++j;  
        else  
        j = nextval[j];  
    }  
}  

int main()
{
    int a, b;
    int length;
    fa[1] = 1;
    fa[2] = 1;
    scanf("%d%d", &a, &b);
    for (int i = 3; i <= M; i++)
    fa[i] = (a * fa[i-1] % 7 + b * fa[i-2] % 7)%7;
    for (int i = 1; i <= M; i++)
    printf("%d\t", fa[i]%7);
    printf("\n\n!!!!!!!!");
    getnext(fa);  
    for(int i = 1; i <= M; ++i)  
    {  
        length = i - nextval[i]; //循环节的长度  
        if(i != length && i % length == 0) //如果有多个循环  
        printf("%d %d\n", i, i / length);  
    }  
    return 0;
}
