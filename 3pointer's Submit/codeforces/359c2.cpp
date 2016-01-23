#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>

using namespace std;
typedef long long LL;
const LL N = 100005;
const LL MOD = 1000000007;

LL n,x;
LL a[N];
map<LL,LL> w;

LL quick_mod(LL a,LL b,LL m)
{
    LL ans = 1;
    a %= m;
    while(b)
    {
        if(b&1)
        {
            ans = ans * a % m;
            b--;
        }
        b >>= 1;
        a = a * a % m;
    }
    return ans;
}

int main()
{
    LL s = 0;
    w.clear();
    scanf("%I64d%I64d",&n,&x);
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
        s += a[i];
        w[a[i]]++;
    }
    int i = a[n-1];
    while(w[i] % x == 0)
    {
        w[i-1] += w[i] / x;
        --i;
    }
    if(i < 0) i = 0;
    printf("%I64d\n",quick_mod(x,s-i,MOD));
    return 0;
}

