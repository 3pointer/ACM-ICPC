#include <stdio.h>
#include <math.h>
#include <algorithm>
#define N 100005
#define INF 0x3f3f3f3f
using namespace std;
struct SBT
{
    int left, right, size, key;
    void init()
    {
        left = right = key = 0;
        size = 1;
    }
}T[N];

int root, tot;

void Left_rot(int &x)
{
    int k = T[x].right;
    T[x].right = T[k].left;
    T[k].left = x;
    T[k].size = T[x].size;
    T[x].size = T[T[x].left].size + T[T[x].right].size + 1;
    x = k;
}

void Right_rot(int &x)
{
    int k = T[x].left;
    T[x].left = T[k].right;
    T[k].right = x;
    T[k].size = T[x].size;
    T[x].size = T[T[x].left].size + T[T[x].right].size + 1;
    x = k;
}
void Maintain(int &r, bool flag)
{
    if (flag)
    {
        if (T[T[T[r].right].right].size > T[T[r].left].size)
            Left_rot(r);
        else if (T[T[T[r].right].left].size > T[T[r].left].size)
        {
            Right_rot(T[r].right);
            Left_rot(r);
        }
        else
            return;
    }
    else
    {
        if (T[T[T[r].left].left].size > T[T[r].right].size)
            Right_rot(r);
        else if (T[T[T[r].left].right].size > T[T[r].right].size)
        {
            Left_rot(T[r].left);
            Right_rot(r);
        }
        else
            return;
    }
    Maintain(T[r].left, false);
    Maintain(T[r].right, true);
    Maintain(r, false);
    Maintain(r, true);
}

void Insert(int &r, int k)
{
    if (r == 0)
    {
        r = ++tot;
        T[r].init();
        T[r].key = k;
    }
    else
    {
        T[r].size ++;
        if (k < T[r].key)
            Insert(T[r].left, k);
        else
            Insert(T[r].right, k);
        Maintain(r, k >= T[r].key);
    }
}

int Remove(int &r, int k)
{
    int d_key;
    if (!r)
        return 0;
    T[r].size --;
    if (T[r].key == k || (T[r].left == 0 && k < T[r].key) || (T[r].right == 0 && k > T[r].key))
    {
        d_key = T[r].key;
        if (T[r].left && T[r].right)
            T[r].key = Remove(T[r].left, k + 1);
        else
            r = T[r].left + T[r].right;
        return d_key;
    }
    else
        return Remove(k < T[r].key? T[r].left : T[r].right, k);
}
void Delete(int &r, int delay, int min_val)
{
    if (!r)
        return;
    if (T[r].key + delay < min_val)
    {
        r = T[r].right;
        Delete(r, delay, min_val);
    }
    else
    {
        Delete(T[r].left, delay, min_val);
        T[r].size = T[T[r].right].size + T[T[r].left].size + 1;
    }
}

int Get_Max(int &r)
{
    while(T[r].right)
        r = T[r].right;
    return r;
}

int Get_Min(int &r)
{
    while(T[r].left)
        r = T[r].left;
    return r;
}

int Get_Pre(int &r, int y, int k)
{
    if (r == 0)
    {
        if (y == 0)
            return INF;
        return T[y].key;
    }
    if (k >= T[r].key)
        return Get_Pre(T[r].right, r, k);
    else
        return Get_Pre(T[r].left, y, k);
}

int Get_Next(int &r, int y, int k)
{
    if (r == 0)
    {
        if (y == 0)
            return INF;
        return T[y].key;
    }
    if (k < T[r].key)
        return Get_Next(T[r].left, r, k);
    else
        return Get_Next(T[r].right, y, k);
}

int Get_Min_kth(int &r, int k)
{
    int t = T[T[r].left].size + 1;
    if (t == k)
        return T[r].key;
    if (t < k)
        return Get_Min_kth(T[r].right, k - t);
    else
        return Get_Min_kth(T[r].left, k);
}


int Get_Max_kth(int &r, int k)
{
    int t = T[T[r].left].size + 1;
    if (t == k)
        return T[r].key;
    if (t < k)
        return Get_Max_kth(T[r].right, k - t);
    else
        return Get_Max_kth(T[r].left, k);
}

int Get_Rank(int &r, int k)
{
    if (k < T[r].key)
        return Get_Rank(T[r].left, k);
    else if (k > T[r].key)
        return Get_Rank(T[r].right, k) + T[T[r].left].size + 1;
    else
        return T[T[r].left].size + 1;
}

int Find(int &r, int k)
{
    if (!r)
        return 0;
    if (k == T[r].key)
        return 1;
    if (k < T[r].key)
        return Find(T[r].left, k);
    else
        return Find(T[r].right, k);
}

void Inorder(int &r)
{
    if (r == 0)
        return ;
    Inorder(T[r].left);
    printf("%d--%d", T[r].key, T[r].size);
    Inorder(T[r].right);
}

int main()
{
    int n;
    int a, b;
    int x, y;
    int t;
    int m;
    int TreeKind;
    scanf("%d", &t);
    {
        tot = root = 0;
        int ans = 0;
        for (int cas = 1; cas <= t; cas ++)
        {
            scanf("%d%d", &n, &m);
            for (int i = 1; i <= n; i++)
            {
                scanf("%d%d", &a, &b);
            }
        }
    }
    return 0;
}
