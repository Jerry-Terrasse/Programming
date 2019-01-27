#include<cstdio>
#include "memory.h"
#define int long long
#define MAXN 1000010
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
int f[MAXN],n=0,q=0,ans=0;
inline void read(int&);
void write(const int&);
inline void init();
inline void work(const int &u,const int &v);
signed main()
{
  register int u=0,v=0;
  read(n);read(q);
  init();
  for(;q--;)
  {
  	read(u);read(v);
  	u^=ans;v^=ans;
  	work(u,v);
  	write(ans);
  	putchar('\n');
  }
  return 0;
}
inline void work(const int &l,const int &r)
{
  register int i=0;
  ans=0;
  for(i=l;i<=r;++i)
  {
  	ans+=max(r-f[i],0);
  }
  for(i=l;i<=r;++i)
  {
  	f[i]=max(f[i],r);
  }
  return;
}
inline void init()
{
  register int i=0;
  for(i=1;i<=n;++i)
  {
  	f[i]=i;
  }
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
  register char c=getchar();
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
