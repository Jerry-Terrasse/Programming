#include<iostream>
#include<cstdio>
#include "memory.h"
#define ll long long
#define MAXL 10000010
using namespace std;
struct lll
{
  ll a[MAXL],len;
  inline void init();
  inline lll();
  inline void output();
  inline void operator*=(const int&);
  inline void operator+=(const lll&);
}ljq,ans;
int n=0;
int main()
{
  register int i=0;
  cin>>n;
  ljq.init();
  ans.init();
  ljq.len=ljq.a[1]=1;
  ans+=ljq;
  for(i=2;i<=n;++i)
  {
  	ljq*=i;
  	ljq.output();
  	putchar('\n');
  	ans+=ljq;
  }
  ans.output();
  putchar('\n');
  main();
  return 0;
}
inline void lll::output()
{
  register int i=0;
  for(i=len;i>=1;--i)
  {
  	putchar(a[i]^48);
  }
  return;
}
inline void lll::operator*=(const int &b)
{
  register int i=0;
  for(i=1;i<=len;++i)
  {
  	a[i]*=b;
  }
  for(i=1;i<=len;++i)
  {
  	a[i+1]+=a[i]/10;
  	a[i]%=10;
  }
  for(;a[i];++i)
  {
  	a[i+1]=a[i]/10;
  	a[i]%=10;
  }
  len=i-1;
  return;
}
inline void lll::operator+=(const lll &b)
{
  register int i=0;
  if(b.len>len)
  {
  	len=b.len;
  }
  for(i=1;i<=b.len;++i)
  {
  	a[i]+=b.a[i];
  }
  for(i=1;i<=len;++i)
  {
  	a[i+1]+=a[i]/10;
  	a[i]%=10;
  }
  for(;a[i];++i)
  {
  	a[i+1]=a[i]/10;
  	a[i]%=10;
  }
  len=i-1;
  return;
}
inline lll::lll()
{
  init();
  return;
}
inline void lll::init()
{
  len=0;
  memset(a,0,sizeof(a));
  return;
}
