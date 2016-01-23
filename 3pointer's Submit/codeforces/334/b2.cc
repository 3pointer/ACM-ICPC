#include<stdio.h>
#include<iostream>
using namespace std;

const int N = 100100;
int a[N];

int main(){

    int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i ++){
    scanf("%d", &a[i]);
  }

  int ans = a[n - 1];
  if (n > k){
    int len = n - k;
    len *= 2;
    int j = len;

    for (int i = 0; i < len; i ++){
      ans = max(ans, a[i] + a[len - i - 1]);
    }
  }
  cout << ans << endl;
  return 0;
}
