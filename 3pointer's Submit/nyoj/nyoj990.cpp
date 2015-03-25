#include <stdio.h>
#include <algorithm>
#define N 102

using namespace std;

int num[N];
int vis[N*2];

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i ++)
        {
            scanf("%d", &num[i]);
            if (num[i] < 0)
            {
                num[i] = -num[i];
                vis[num[i]] = 2;
            }
            else
                vis[num[i]] = 1;
        }
        int flag = num[0];
        sort(num, num + n);
        int con = 1;

        /*for (int i = 0; i < n; i++)
        {
            if (num[i] < flag)
            {
                if (vis[num[i]] == 1)
                    con ++;
            }
            else if (num[i] == flag)
            {
                continue;
            }
            else
            {
                if (vis[num[i]] == 2)
                    con ++;
            }
        }
	    */
        int tmp;
        int con1 = 0;
        int con2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (flag == num[i])
            {
                tmp = i;
                break;
            }
            if (vis[num[i]] == 1)
                con1++;
        }
        for (int i = tmp + 1; i < n; i++)
        {
            if (vis[num[i]] == 2)
                con2++;
        }
        if (con1 == 0 && vis[flag] == 2 || con2 == 0 && vis[flag] == 1)
            con = 1;
        else
            con = con1 + con2 + 1;
        printf("%d\n", con);
    }
    return 0;
}
