#include<cstdio>
#include "memory.h"
#define int long long
#define MAXN 1010
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
int pre[MAXN],f[MAXN],a[MAXN],n=0;
inline void read(int&);
void write(const int&);
inline void _write(const int&);
signed main()
{
  register int i=0,j=0,l=0,r=0,mid=0;
  memset(f,0x80,sizeof(f));
  memset(pre,0xff,sizeof(pre));
  f[0]=0;
  read(n);
  for(i=1;i<=n;++i)
  {
    read(a[i]);
  }
  for(i=1;i<=n;++i)
  {
    for(l=0,r=i;l+1<r;)
    {
      mid=l+r+1>>1;
      if(f[mid]-f[mid-1]<a[i]*mid)
      {
        r=mid;
      }
      else
      {
        l=mid;
      }
    }
    for(j=i;j>=r;--j)
    {
      f[j]=f[j-1]+a[i]*j;
    }
    for(j=1;j<=i;++j)
    {
      _write(f[j]);
    }
    putchar('\n');
  }
  return 0;
}
inline void _write(const int &x)
{
  if(x<0)
  {
    putchar('-');
    write(-x);
  }
  else
  {
    write(x);
  }
  putchar(' ');
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
  register bool bo=false;
  for(x=0;c<'0'||c>'9';c=getchar())
  {
    if(c=='-')
    {
      bo=true;
    }
  }
  for(;c>='0'&&c<='9';c=getchar())
  {
    x=(x<<1)+(x<<3)+(c^48);
  }
  if(bo)
  {
    x=~x+1;
  }
  return;
}