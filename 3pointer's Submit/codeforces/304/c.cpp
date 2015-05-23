#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stack>
#include<queue>
using namespace std;

int n;

queue<int>s1;
queue<int>s2;
int a1[12];
int a2[12];
bool vis[21000000];
int main(){
    int k1, k2;
    while(scanf("%d", &n) != EOF){
        memset(vis, 0, sizeof(vis));
        while(!s1.empty()){
            s1.pop();
        }
        while(!s2.empty()){
            s2.pop();
        }
        int s1num = 0;
        int s2num = 0;
        //int f1 = 0, f2 = 0;
        scanf("%d", &k1);
        for (int i = 0; i < k1; i ++){
            scanf("%d", &a1[i]);
            a1[i] --;
            s1num ++;
            s1.push(a1[i]);
        }
        scanf("%d", &k2);
        for (int i = 0; i < k2; i ++){
            scanf("%d", &a2[i]);
            a2[i] --;
            s2num ++;
            s2.push(a2[i]);
        }
        //printf("s1:%d\n", s1.top());
        //std::cout<<f1<<std::endl;
        //std::cout<<f2<<std::endl;
        int coun = 0;
        int flag = 0;
        while(1){
            if (s1num == n){
                printf("%d %d\n", coun, 1);
                break;
            }
            if (s2num == n){
                printf("%d %d\n", coun, 2);
                break;
            }
            if (flag == 1){
                printf("-1\n");
                break;
            }
            int t1 = s1.front();
            s1.pop();
            int t2 = s2.front();
            s2.pop();
            coun ++;

            s1num --;
            s2num --;
            if (t1 > t2){
                s1.push(t2);
                s1.push(t1);
                s1num += 2;
            }
            if (t2 > t1){
                s2.push(t1);
                s2.push(t2);
                s2num += 2;
            }

        }
    }
    return 0;
}
