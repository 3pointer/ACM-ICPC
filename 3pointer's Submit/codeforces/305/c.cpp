#include <stdio.h>
#include <map>
using namespace std;
map<int, int> m;
map<int, int> m2;


int exgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int r=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
    return r;
}


int main(){
    int M, x1, a1, h1, y1;
    int x2, a2, h2, y2;
    scanf("%d", &M);
    scanf("%d%d%d%d", &h1, &a1, &x1, &y1);
    scanf("%d%d%d%d", &h2, &a2, &x2, &y2);
    int cou = 1;
    int s1, s2;
    while (m[h1] == 0){
        m[h1] = cou;
        cou ++;
        h1 = h1 * x1 + y1;
        h1 %= M;
    }
    s1 = cou - 1;
    cou = 1;
    while (m2[h2] == 0){
        m2[h2] = cou;
        cou ++;
        h2 = h2 * x2 + y2;
        h2 %= M;
    }
    s2 = cou - 1;
    int k1 = m[a1];
    int k2 = m2[a2];
    int x, y;
    if (k1 == 0 || k2 == 0) 
        printf("%d\n", -1);
    else{
        int d = exgcd(s1, s2, x, y);
        int c = k1 - k2;
        c = c + M;
        c %= M;
        if (c % d != 0){
            printf("-1\n");
        }
        else {
            int tmp = c / d;
            x *= tmp;
            y *= tmp;
            printf("%d\n", x + k1 - 1);
        }

         
    }

    return 0;
}
