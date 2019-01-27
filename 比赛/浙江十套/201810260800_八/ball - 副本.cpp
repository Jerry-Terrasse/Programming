#include<iostream>
#include "memory.h"
#define MAXL 10010
#define MAXN 110
using namespace std;
struct lll
{
  int a[MAXL],len;
  inline lll();
  inline void init();
  inline void operator=(const lll&);
  inline void operator*=(const int&);
  inline lll operator*(const int&);
  inline void operator+=(const lll&);
  inline lll operator+(const lll&);
  inline void output();
}f[MAXN][MAXN];
int n=0,m=0;
inline void init();
int main()
{
  int i=0,j=0;
  init();
  for(;cin>>n>>m;)
  {
  	f[n][m].output();
  	cout<<endl;
  }
  return 0;
}
inline lll lll::operator*(const int &b)
{
  lll ans=*this;
  ans*=b;
  return ans;
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
  	a[i+1]+=a[i]/10;
  	a[i]=10;
  }
  len=i-1;
  return;
}
inline lll lll::operator+(const lll &b)
{
  lll ans=*this;
  ans+=b;
  return ans;
}
inline void lll::operator+=(const lll &b)
{
  register int i=0;
  for(i=1;i<=b.len;++i)
  {
  	a[i]+=b.a[i];
  }
  if(len<b.len)
  {
  	len=b.len;
  }
  for(i=1;i<=len;++i)
  {
  	a[i+1]+=a[i]/10;
  	a[i]%=10;
  }
  for(;a[i];++i)
  {
  	a[i+1]+=a[i]/10;
  	a[i]%=10;
  }
  len=i-1;
  return;
}
inline void lll::operator=(const lll &b)
{
  len=b.len;
  memcpy(a,b.a,sizeof(a));
  return;
}
inline void lll::init()
{
  len=0;
  memset(a,0,sizeof(a));
  return;
}
inline lll::lll()
{
  init();
  return;
}
inline void init()
{
  register int i=0,j=0;
  memset(f,0,sizeof(0));
  f[0][0].len=f[0][0].a[1]=1;
  for(i=1;i<MAXN;++i)
  {
  	for(j=1;j<MAXN;++j)
  	{
  	  f[i][j]=f[i-1][j]*j+f[i-1][j-1];
	}
  }
  return;
}
