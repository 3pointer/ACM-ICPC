#include <stdio.h>
#include <string.h>

int main(){

    int k, n, w;
    while(scanf("%d%d%d", &k, &n, &w) != EOF){
        int sum = (1 + w) * w / 2;
        sum *= k;
        if (sum > n){
            printf("%d\n", sum - n);
        }
        else{
            printf("0\n");
        }
    }

    return 0;
}
