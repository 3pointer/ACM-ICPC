#include<bits/stdc++.h>
using namespace std;

const int N = 100100;

int BinSearch(int key, int* d, int low, int high)
{
    while(low<=high)
    {
            int mid = (low+high)>>1;
            if(key>d[mid] && key<=d[mid+1])
                return mid;
            else if(key>d[mid])
                low = mid+1;
            else
                high = mid-1;
        }
    return 0;
}

int LIS(int* a, int n, int* d)
{
    int i,j;
    d[1] = a[1];
    int len = 1;
    for(i = 2; i <= n; i++)
    {
            if(d[len]<a[i])
                j = ++len;
            else
                j = BinSearch(a[i],d,1,len) + 1;
            d[j] = a[i];
        }
    return len;
}
int LIS2(int* a, int n, int* d)
{
    int i,j;
    d[1] = a[1];
    int len = 1;
    for(i = 2; i <= n; i++)
    {
            if(d[len]>a[i])
                j = ++len;
            else
                j = BinSearch(a[i],d,1,len) + 1;
            d[j] = a[i];
        }
    return len;
}

int main(){

    int a[N];
    int b[N];
    int d[N];
    int d2[N];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
        b[n - i + 1] = a[i];
    }
    int ans1 = LIS(a, n, d);
    int ans2 = LIS2(b, n, d2);
    cout << min(n - ans1, n - ans2) << endl;
    return 0;
}
