#include <stdio.h>
#include <math.h>
int tot;
int k;
int map[100][100];
void chess_board(int tr, int tc, int dr, int dc, int size)
{
    if (size == 1)
        return;
    int t = ++tot;
    int s = size / 2;
    if (dr < tr + s && dc < tc + s)
        chess_board(tr, tc, dr, dc, s);
    else
    {
        map[tr + s - 1][tc + s - 1] = t;
        chess_board(tr, tc, tr + s - 1, tc + s - 1, s);
    }
    if (dr < tr + s && dc >= tc + s)
        chess_board(tr, tc + s, dr, dc, s);
    else
    {
        map[tr + s - 1][tc + s] = t;
        chess_board(tr, tc + s, tr + s - 1, tc + s, s);
    }
    if (dr >= tr + s && dc < tc + s)
        chess_board(tr + s, tc , dr, dc, s);
    else
    {
        map[tr + s][tc + s - 1] = t;
        chess_board(tr + s, tc, tr + s, tc + s - 1, s);
    } 
    if (dr >= tr + s && dc >= tc + s)
        chess_board(tr + s, tc + s , dr, dc, s);
    else
    {
        map[tr + s][tc + s] = t;
        chess_board(tr + s, tc + s, tr + s, tc + s, s);
    } 
}
int f(int k)
{
    return (int)pow(2, k);
}
void show()
{
    int K = f(k);
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < K; j++)
            printf("%d\t", map[i][j]);
        printf("\n");
    }
}
int main()
{
    int x, y;
    printf("输入k\n");
    scanf("%d", &k);
    printf("输入特殊方格的坐标\n");
    scanf("%d%d", &x, &y);
    chess_board(0, 0, x, y, f(k));
    show();
}
