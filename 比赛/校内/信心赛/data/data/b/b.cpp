#include <bits/stdc++.h>

using namespace std ;

int n, m ;

int a[1000000], b[1000000], c[1000000], d[1000000] ;
inline void read(int &a)
{
  a = 0;
  char c =  getchar() ;
  while (isspace(c)) c = getchar() ;
  do a = a * 10 + c - '0', c = getchar() ;
  while (isdigit(c)) ;
}
inline void write(int a)
{
  if (a > 9) write(a / 10) ;
  putchar(a % 10 + '0') ;
}
int main()
{
  read(n), read(m) ;
  for (int i = 1; i <= n; i ++) read(a[i]), read(b[i]) ;
  int a1 = -100000000 , a2 = -100000000, a3 = -100000000, a4 = -100000000 ;
  for (int i = 1; i <= m;i ++) read(c[i]), read(d[i]), a1 = max(a1, c[i] + d[i]), a2 = max(a2,
                                            c[i] - d[i]), a3 = max(a3, -c[i] + d[i]), a4 = max(a4, -c[i] - d[i]) ;
  for (int i = 1; i <= n; i ++)
    {
      int ans = 0 ;
      ans = max(ans, a1 - (a[i] + b[i])) ;
      ans = max(ans, a2 - (a[i] - b[i])) ;
      ans = max(ans, a3 - (-a[i] + b[i])) ;
      ans = max(ans, a4 - (-a[i] - b[i])) ;
      write(ans) ;
      putchar(10);
    }
}
