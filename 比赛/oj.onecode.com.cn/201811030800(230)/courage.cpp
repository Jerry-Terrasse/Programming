#include<cstdio>
#include<cmath>
#define ld long double
using namespace std;
int n=0;
inline void read(int&);
int main()
{
  register int i=0,j=0;
  read(n);
  j=n%3;
  for(i=ceil((ld)n/7);i%3!=j;++i);
  j=(n-(i<<2))/3;
  for(;i>j;--i,putchar('4'));
  for(;j--;putchar('7'));
  //main();
  return 0;
}
inline void read(int &x)
{
  register char c=getchar();
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
