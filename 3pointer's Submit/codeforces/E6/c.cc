#include<bits/stdc++.h>
using namespace std;

const int N = 100001 * 3;
int a[N];
map<int, int>M;
vector<pair<int, int> >v;


int main(){
    int n;
    cin >> n;
    int k;
    int most = 0;
    for (int i = 0; i < n; i ++){
        scanf("%d", &a[i]);
        int tmp = ++ M[a[i]];
        if (tmp > most){
            most = tmp;
            k = a[i];
        }
    }

    if (most <= 1){
        puts("-1");
        return 0;
    }

    int last = 1;
    int now = 0;
    int flag = 0;
    int tmp = 0;
    for (int i = 0; i < n; i ++){
        if (a[i] == k){
            now = i + 1;
            if (flag % 2 == 1){
                v.push_back(make_pair(last, now));
                last = now + 1;
                most -= 2;
            }
            flag ++;
        }
        if (most <= 1){
            tmp = 1;
            break;
        }
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size() - 1; i ++){
        printf("%d %d\n", v[i].first, v[i].second);
    }
    printf("%d %d\n", v[v.size() - 1].first, n);

    return 0;
}
