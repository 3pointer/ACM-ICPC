#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

const int N = 1000;

int a[N];
int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n - i - 1; j ++){
            if (a[j] > a[j + 1]){
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i ++){
        cout << a[i] << endl;
    }
    return 0;
}
