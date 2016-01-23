#include<bits/stdc++.h>

using namespace std;

const int N = 1001;

int main(){
    int a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;
    int x = c - a;
    int y = d - b;
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    cout << max(x, y);
    return 0;
}
