#include <stdio.h>
#include <string.h>
#define N 500010

char str[N];
int vis[30];

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        memset(vis, 0, sizeof(vis));
        int cou = 0;
        scanf("%s", str);
        int l = strlen(str);
        for (int i = 0; i < l; i += 2){
            vis[str[i] % 32] ++;
            if (vis[str[i + 1] % 32] == 0) {
                cou ++;
            }else{
                vis[str[i + 1] % 32] --;
            }
        }
        printf("%d\n", cou);
    }

    return 0;
}
