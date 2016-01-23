#include<bits/stdc++.h>
#include<iostream>

using namespace std;

const int N = 11;
int m[N];
int w[N];
int p[N];

double max(double a, double b){
    return a < b ? b : a;
}

int main(){

    p[0] = 500;
    for (int i = 1; i < 5; i ++){
        p[i] = p[i - 1] + 500;
    }
    int h1, h2;
    for (int i = 0; i < 5; i ++){
        cin >> m[i];
    }
    for (int i = 0; i < 5; i ++){
        cin >> w[i];
    }

    cin >> h1 >> h2;
    double ans = 0;
    for (int i = 0; i < 5; i ++){
        ans += max(0.3 * p[i], (double)(1 - m[i] / 250.0) * p[i] - 50 * w[i]);
    }

    cout << ans + 100 * h1 - 50 * h2 << endl;




    return 0;
}
