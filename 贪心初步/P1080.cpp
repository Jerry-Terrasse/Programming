#include<cstdio>
#include<algorithm>
#include "memory.h"
#define MAXN 100010
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
struct lll
{
  int a[MAXN],l;
  inline lll();
  inline void init();
  inline void init(int);
  inline void operator*=(const int&);
  inline void operator/=(const int&);
  inline lll operator/(const int&);
  inline bool operator<(const lll&);
  inline void output();
  inline void operator=(const lll&);
}pro,ans;
struct gen
{
  int l,r;
}a[MAXN];
int n=0;
char c='\0';
inline bool cmp(const gen&,const gen&);
inline void read(int&);
void write(const int&);
int main()
{
  int i=0;
  pro.init(1);
  for(read(n);i<=n;i++)
  {
  	read(a[i].l);read(a[i].r);
  }
  sort(a+1,a+n+1,cmp);
  for(i=1;i<=n;i++)
  {
  	pro*=a[i-1].l;
  	ans=max(ans,pro/a[i].r);
  }
  ans.output();
  return 0;
}
inline void lll::operator=(const lll &x)
{
  l=x.l;
  memcpy(a,x.a,sizeof(a));
  return;
}
void write(const int &x)
{
  if(x>9)
  {
  	write(x/10);
  }
  putchar(x%10^48);
  return;
}
inline void read(int &x)
{
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
inline void lll::output()
{
  register int i=0;
  for(i=l;i;--i)
  {
  	putchar(a[i]^48);
  }
  return;
}
inline lll lll::operator/(const int &x)
{
  lll ans=*this;
  ans/=x;
  return ans;
}
inline bool lll::operator<(const lll &x)
{
  if(l<x.l)
  {
  	return true;
  }
  register int i=0;
  for(i=l;i;--i)
  {
  	if(a[i]!=x.a[i])
  	{
  	  return a[i]<x.a[i];
	}
  }
  return false;
}
inline void lll::operator/=(const int &x)
{
  register int i=0;
  for(i=l;i;--i)
  {
  	a[i-1]+=a[i]%x*10;
  	a[i]/=x;
  }
  a[0]=0;
  for(;!a[l];--l);
  return;
}
inline void lll::operator*=(const int &x)
{
  if(!x)
  {
  	init();
  	return;
  }
  register int i=0;
  for(i=1;i<=l;++i)
  {
  	a[i]*=x;
  }
  for(i=1;i<=l||a[i];++i)
  {
  	a[i+1]+=a[i]/10;
  	a[i]%=10;
  }
  l=i-1;
  return;
}
inline void lll::init(int x)
{
  init();
  for(;x;x/=10)
  {
  	a[l++]=x%10;
  }
  --l;
  if(!l)
  {
  	++l;
  }
  return;
}
inline void lll::init()
{
  memset(a,0,sizeof(a));
  l=1;
  return;
}
inline lll::lll()
{
  init();
  return;
}
inline bool cmp(const gen &a,const gen &b)
{
  return a.l*a.r<b.l*b.r;
}
