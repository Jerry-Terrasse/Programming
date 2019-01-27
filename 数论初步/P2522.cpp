//P2522 [HAOI2011]Problem b
#include<cstdio>
#include "memory.h"
#define int long long
#define MAXN 500050
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
int zs[MAXN],mu[MAXN],n=0,zc=0,a=0,b=0,c=0,d=0,k=0;
inline void init();
inline int work(int,int);
inline void read(int&);
void write(const int&);
signed main()
{
  register int i=0;
  init();
  read(n);
  for(;n--;)
  {
    read(a);read(b);read(c);read(d);read(k);
    write(work(b,d)-work(a-1,d)-work(c-1,b)+work(a-1,c-1));
    putchar('\n');
  }
  return 0;
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
inline int work(int n,int m)
{
  register int i=0,j=0,ret=0;
  n/=k;m/=k;
  if(n>m)
  {
    n^=m^=n^=m;
  }
  for(i=1;i<=n;i=j+1)
  {
    j=min(n/(n/i),m/(m/i));
    ret+=(mu[j]-mu[i-1])*(n/i)*(m/i);
  }
  return ret;
}
inline void init()
{
  register int i=0,j=0;
  memset(zs,-1,sizeof(zs));
  for(i=2,mu[1]=1;i<MAXN;++i)
  {
    if(zs[i])
    {
      zs[++zc]=i;
      mu[i]=-1;
    }
    for(j=1;j<=zc&&i*zs[j]<MAXN;++j)
    {
      zs[i*zs[j]]=0;
      if(i%zs[j])
      {
        mu[i*zs[j]]=-mu[i];
      }
      else
      {
        break;
      }
    }
  }
  for(i=2;i<MAXN;++i)
  {
    mu[i]+=mu[i-1];
  }
  return;
}