#include <stdio.h>
#include <algorithm>
int n;
int a[3010];
int main(){
    while(scanf("%d", &n) != EOF){
        for (int i = 0; i < n; i ++){
            scanf("%d", &a[i]);
        }
        std::sort(a, a + n);
        int k = 0;
        int sum = 0;
        for (int i = 1; i < n; i ++){
            if (a[i] <= a[i - 1]){
                k = a[i - 1] - a[i] + 1;
                a[i] += k;
                sum += k;
            } else {
               // k = 0;
            }
        }
        printf("%d\n", sum);
    }

    return 0;
}
