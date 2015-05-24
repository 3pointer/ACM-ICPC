#include <stdio.h>
#include <string.h>

char str[1000];

int main(){
    while(scanf("%s", str) != EOF){
        int vis[100] = {0};
        int flag = 0;
        int len = strlen(str);
        if (len % 3 == 0){
            int k = len / 3;
            char s = '0';
            for (int i = 0; i < len; i += k){
                s = str[i];
                if (vis[s % 32] != 0)
                    flag = 1;
                vis[s % 32] = 1;
                for (int j = i; j < i + k; j ++){
                    if (str[j] != s) 
                        flag = 1;
                }
            }
            if (flag == 0)
                puts("YES");
            else 
                puts("NO");
        }
        else
            puts("NO");
    }
        
    return 0;
}

