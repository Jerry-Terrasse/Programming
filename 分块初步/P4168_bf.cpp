//P4168[Violet]蒲公英
//bf but Accepted
#include<cstdio>
#include<map>
#include<algorithm>
#include "memory.h"
#define MAXN 40040
#define MAXM 50050
using namespace std;
int f[MAXN],a[MAXN],b[MAXN],n=0,m=0,nc=0,ans=0;
map<int,int>mp;
inline void read(int&);
void write(const int&);
inline void init();
int main()
{
  register int i=0,j=0,u=0,v=0;
  //freopen("P4168#1.in","r",stdin);
  read(n);read(m);
  for(i=1;i<=n;++i)
  {
    read(a[i]);
  }
  init();
  for(;m--;)
  {
    read(u);read(v);
    u=(u+b[ans]-1)%n+1;
    v=(v+b[ans]-1)%n+1;
    if(u>v)
    {
      u^=v^=u^=v;
    }
    memset(f,0,sizeof(f));
    for(i=u;i<=v;++i)
    {
      ++f[a[i]];
    }
    for(i=1,ans=0;i<=nc;++i)
    {
      if(f[i]>f[ans])
      {
        ans=i;
      }
    }
    write(b[ans]);
    putchar('\n');
  }
  return 0;
}
inline void init()
{
  register int i=0;
  memcpy(b,a,sizeof(a));
  sort(b+1,b+n+1);
  nc=unique(b+1,b+n+1)-b-1;
  for(i=1;i<=nc;++i)
  {
    mp.insert(make_pair(b[i],i));
  }
  for(i=1;i<=n;++i)
  {
    a[i]=mp[a[i]];
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
  for(x=0;c<'0'||c>'9';c=getchar());
  for(;c>='0'&&c<='9';c=getchar())
  {
    x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}