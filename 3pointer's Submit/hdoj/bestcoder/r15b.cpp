#include <stdio.h>
#include <string>
#include <iostream>
#include <string.h>
#include <map>

using namespace std;

int flag;
int flag2;
int flag3;
map<string, int>m;

void print(int x)
{
    if (x == 1)
    {
        printf("000001");
        return;
    }
    if (x == 2)
    {
        printf("000010");
        return;
    }
    if (x == 3)
    {
        printf("000011");
        return;
    }
    if (x == 4)
    {
        printf("000100");
        return;
    }
    if (x == 5)
    {
        printf("000101");
        return;
    }
    if (x == 6)
    {
        printf("000110");
        return;
    }
}
void print2(int x)
{
    int a[10] = {0};
    int i = 0;
    while(x) 
    {
        a[5 - i] = x % 2;
        x /= 2;
        i ++;
    }
    for (i = 1; i <= 5; i ++)
    printf("%d", a[i]);
}
void tprintc(int * a, int len)
{
    int x = 1;
    int sum = 0;
    for (int i = len - 1; i >= 0; i --)
    {
        if (a[i] == 1)
        sum += x;
        x <<= 1; 
    }
    if (sum >= 7 || sum == 0)
    {
        flag = 0;
        return;
    }
    else if (sum == 6)
    {
        flag2 = 1;
        return;
    }
    else
    {
        map<string,int> :: iterator iter;
        for (iter = m.begin(); iter != m.end(); iter ++)
        {
            if (iter->second == sum)
            {
                cout<<iter->first;
                return;
            }
        }
    }
}

void tprint(int * a, int len)
{
    int x = 1;
    int sum = 0;
    for (int i = len - 1; i >= 0; i --)
    {
        if (a[i] == 1)
        sum += x;
        x <<= 1; 
    }
    printf("R%d", sum);
}

int main()
{
    int n;
    int a, b;
    char ch;
    int su;
    int x1[10];
    int x2[10];
    int x3[10];
    string str; 
    m["ADD"] = 1;
    m["SUB"] = 2;
    m["DIV"] = 3;
    m["MUL"] = 4;
    m["MOVE"] = 5;
    m["SET"] = 6;
    while(scanf("%d", &n) != EOF)
    {
        su = 0;
        if (n == 1)
        {
            cin>>str; 
            getchar();
            int len = str.size();
            if (str[len - 1] != 'T')
            scanf("%c%d,%c%d", &ch, &a, &ch, &b);
            else
            scanf("%c%d", &ch, &a);
            if (str[len - 1] != 'T')
            {
                int x1 = m[str];
                if (x1 == 0)
                {
                    puts("Error!");
                    continue;
                }
                else
                {
                    print(x1);
                    if (a >= 32)
                    {
                        puts("Error!");
                        continue;
                    }
                    else
                    {
                        print2(a); 
                        if (b >= 32)
                        {
                            puts("Error!");
                            continue;
                        }
                        print2(b);
                        printf("\n");
                    }
                }
            }
            else
            {
                printf("000110");
                print2(a);
                printf("00000\n");
            }
        }
        else
        {
            cin>>str;
            if (str.size() != 16)
            {
                puts("Error!");
                continue;
            }
            else
            {
                int i, j, k;
                for (i = 0; i <= 5; i ++) 
                x1[i] = str[i] - '0';
                for (j = 0; j <= 4; j ++)
                x2[j] = str[j + i] - '0';
                for (k = 0; k <= 4; k ++)
                x3[k] = str[k + j + i] - '0';
                flag = 1;
                flag2 = 0;
                flag3 = 0;
                for (int z = 0; z <= 4; z ++)
                {
                    if (x2[z] == 1)
                    {
                        puts("Error!");
                        flag3 = 1;
                        break;
                    }
                }
                if (flag3 == 1)
                    continue;
                for (int z = 0; z <= 4; z ++)
                    su += x3[z];
                if (x1[3] == 1 && x1[4] == 1 && x1[5] == 1 && su == 0)
                {
                    puts("Error!");
                    continue;
                }
                tprintc(x1, 6);
                if (flag == 0)
                {
                    puts("Error!");
                    continue;
                }
                if (flag2 == 1)
                {
                    for (int z = 0; z <= 4; z ++)
                    {
                        if (x3[z] == 1)
                        {
                            puts("Error!");
                            flag3 = 1;
                            break;
                        }
                    }
                    if (flag3 == 1)
                    continue;
                    printf("SET");
                }
                printf(" ");
                tprint(x2, 5);
                if (flag2 == 1)
                {
                    printf("\n");
                    continue;
                }
                printf(",");
                tprint(x3, 5);
                printf("\n");
            }
        }
    }
return 0;
}
