#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);

    int a = 0;
    int b = 0;

    int x;
    int p = 2;
    for (int i = 0; i < n; i ++){
        scanf("%1d", &x);
        if (x != p){
            a ++;
            p = x;
        } else {
            b ++;
        }
    }
    if (b > 2)
        b = 2;
    printf("%d\n", a + b);

    return 0;
}
