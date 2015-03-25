#include <stdio.h>
#include <string.h>
#define N 499

struct node
{
    int v, w, next;
}e[N];

int head[N];
int tot;

void init()
{
    memset(head, -1, sizeof(head));
    tot = 0;
}

void addedge(int a, int b, int c)
{
    e[tot].v = b;
    e[tot].w = c;
    e[tot].next = head[a];
    head[a] = tot++;
}
int main()
{


}

