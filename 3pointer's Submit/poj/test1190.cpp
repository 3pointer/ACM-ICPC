#include <iostream>
#include <cmath>
using namespace std ;
#define INF 0xffffff
int n , m , ans ;
inline int Sum_n3( int x )
{
 return (x+1)*(x+1)*x*x/4 ;
}
inline int Min( int x , int y )
{
 return x > y ? y : x ;
}
void dfs( int floor , int r , int h , int leftv , int s )
{
 if ( ( s + 2*leftv/r ) >= ans )
  return ;
 if ( leftv < Sum_n3( floor ) )
  return ;
 if ( floor == 0 )
 {
  if ( leftv == 0 )
   ans = s ;
  return ;
 }
 int k = 0 , i , j , maxh ;
 for ( i = r-1 ; i >= floor ; i-- )
 {
  k = i*i ;
  if ( floor == m )
   s = k ;
  maxh = Min( h-1 , (leftv-Sum_n3(floor-1))/k ) ;
               // 直接用j = h-1 也可以过但是用 j = naxh 后效率要高点
  for ( j = maxh ; j >= floor ; j-- )
  {
   dfs( floor-1 , i , j , leftv-k*j , s+2*i*j ) ;
  }
 }
}
int main()
{
// freopen( "e:\\in.txt" , "r" , stdin ) ;
 while ( cin >> n >> m )
 {
  ans = INF ;
  dfs( m , 100 , 10000 , n , 0 ) ;
               //100 最大半径  1000最大高   分别在高为1   半径为1是取得
  if ( ans == INF )
   cout << 0 << endl ;
  else
   cout << ans << endl ;
 }
 return 0 ;
}
