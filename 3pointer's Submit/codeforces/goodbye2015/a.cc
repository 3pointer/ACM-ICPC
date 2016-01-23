#include<bits/stdc++.h>

using namespace std;

const int N = 1001;

char str[N];

int main(){
    int n;
    cin >> n;
    gets(str);
    int len = strlen(str);
    if (str[len - 1] == 'k'){
        if (n == 6 || n == 5)
            cout << 53 << endl;
        else
            cout << 52 << endl;
    } else {
        if (n == 30){
            cout << 11 << endl;
        } else if (n == 31){
            cout << 7 << endl;
        } else {
            cout << 12 << endl;
        }
    }

    return 0;
}
