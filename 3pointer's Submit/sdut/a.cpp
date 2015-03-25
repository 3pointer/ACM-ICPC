#include <stdio.h>
#include <algorithm>
using namespace std;

struct node
{
    char str[30];
    int age;
}name[100];

int cmp(const node & a, const node & b)
{
    return a.age < b.age;
}
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%d %s", &name[i].age, name[i].str);
        sort(name, name + n, cmp);
        printf("%s %s\n", name[0].str, name[n - 1].str);
    }
    return 0;
}
