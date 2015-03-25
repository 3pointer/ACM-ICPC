#include <stdio.h>
#include <string.h>
#define N 3

struct Mat
{
    long long mat[N][N];
};

/*
void init(Mat Mata)
{
    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    Mata.mat[i][j]=0;
    Mata.mat[0][0]=1,Mata.mat[0][1]=3;
    Mata.mat[0][2]=2,Mata.mat[0][3]=7;

    Mata.mat[1][1]=3,Mata.mat[1][2]=2;
    Mata.mat[1][3]=7;

    Mata.mat[2][1]=Mata.mat[3][2]=1;
}
*/
long long M;
Mat mul(Mat p, Mat q)
{
    Mat t;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            t.mat[i][j] = 0;
            for (int k = 0; k < N; k++)
            {
                t.mat[i][j] += p.mat[i][k] * q.mat[k][j];
                if (t.mat[i][j] > M)
                {
                    t.mat[i][j] %= M;
                }
            }
        }
    }
    return t;
}

Mat pw(Mat a, long long b)
{
    Mat ans;
    ans.mat[0][0] = 1;
    ans.mat[0][1] = 0;
    ans.mat[0][2] = 0;

    ans.mat[1][0] = 0;
    ans.mat[1][1] = 1;
    ans.mat[1][2] = 0;

    ans.mat[2][0] = 0;
    ans.mat[2][1] = 0;
    ans.mat[2][2] = 1;
    while(b)
    {
        if (b & 1)
            ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

int main()
{
    Mat a;
    long long n;
    while(scanf("%lld %lld", &n, &M) != EOF)
    {
        a.mat[0][0] = 1;
        a.mat[0][1] = 0;
        a.mat[0][2] = 1;

        a.mat[1][0] = 1;
        a.mat[1][1] = 0;
        a.mat[1][2] = 0;

        a.mat[2][0] = 0;
        a.mat[2][1] = 0;
        a.mat[2][2] = 2;
        long long x;
        if (n >= 3)
        {
            a = pw(a, n - 2);
            x = 2 * a.mat[0][0] + 4 * a.mat[0][2];
        }
        else
        {
            if (n == 1)
                x = 1;
            if (n == 2)
                x = 2;
        }
        printf("%lld\n", x % M);
    }    
    return 0;
}
