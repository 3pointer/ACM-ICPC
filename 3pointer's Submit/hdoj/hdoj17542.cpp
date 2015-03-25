#include <stdio.h>
#define N 200001
struct node
{
    int l,r;
    int maxx;    
};
inline int max(int a, int b)
{
    return a > b? a : b;
}
node line[N*3];
int val[N];
void build(int l,int r,int s)
{
    line[s].l = l;
    line[s].r = r;
    if (l == r)
    {
        line[s].maxx = val[l];
        return;
    }
    int mid = (l+r)>>1;
    build(l,mid,s*2);
    build(mid+1,r,s*2+1);
    line[s].maxx = max(line[s*2].maxx,line[s*2+1].maxx);
}
void modify(int stu, int score, int step)
{
    line[step].maxx = max(line[step].maxx,score);
    if (line[step].l == line[step].r)
    {
        //line[step].maxx = max(line[step].maxx,score);
        return;
    }
    if (stu > line[step*2].r)
        modify(stu, score, step*2+1);
    //if (stu < line[step*2+1].l)
    else
        modify(stu, score, step*2);
    
}

int query(int l, int r, int s)
{
    if (l == line[s].l && line[s].r == r)
        return line[s].maxx;
    if (l >= line[s*2+1].l)
        return query(l, r, s*2+1);
    if (r <= line[s*2].r)
        return query(l, r, s*2);
    int mid = (line[s].l+line[s].r)>>1;
    int ta = query(l, mid, s*2);
    int tb = query(mid+1, r, s*2+1);
    return max(ta, tb);
}
int main()
{
    int n,m;
    char str;
    int a,b;
    while(scanf("%d%d", &n, &m)!=EOF)
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", &val[i]);
        getchar();
        build(1,n,1);
        while(m--)
        {
            scanf("%c%d%d", &str, &a, &b);
            getchar();
            if (str == 'U')
                modify(a,b,1);
            if (str == 'Q')
                printf("%d\n", query(a,b,1));
        }
    }
}
