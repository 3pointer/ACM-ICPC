#include <stdio.h>

int n, m;
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b); 
}

int main(){

    while(scanf("%d%d", &n, &m) != EOF){
        int x = n * m;
        int y = n + m;
        int a = gcd(x, y);
        printf("%d/%d\n", x / a, y / a);
    }
    return 0;
}
