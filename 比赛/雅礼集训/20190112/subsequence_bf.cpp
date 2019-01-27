#include<cstdio>
#include "memory.h"
#define MAXN 1010
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
int pre[MAXN][MAXN],f[MAXN][MAXN],a[MAXN],n=0;
inline void read(int&);
void write(const int&);
inline void _write(const int&);
int main()
{
  register int i=0,j=0;
  memset(f,0x80,sizeof(f));
  read(n);
  for(i=1;i<=n;++i)
  {
    read(a[i]);
  }
  for(i=0;i<=n;++i)
  {
    f[i][0]=0;
  }
  for(i=1;i<=n;++i)
  {
    for(j=1;j<=i;++j)
    {
      //f[i][j]=f[i-1][j];
      //f[i][j]=max(f[i][j],f[i-1][j-1]+j*a[i]);
      if(f[i-1][j]<f[i-1][j-1]+j*a[i])
      {
        pre[i][j]=1;
        f[i][j]=f[i-1][j-1]+j*a[i];
      }
      else
      {
        f[i][j]=f[i-1][j];
      }
    }
  }
  for(i=1;i<=n;++i)
  {
    _write(f[n][i]);
  }
  putchar('\n');
  //puts("-----------------");
  for(i=1;i<=n;++i)
  {
    for(j=1;j<=i;++j)
    {
      //_write(f[i][j]);
    }
    //putchar('\n');
  }
  for(i=1;i<=n;++i)
  {
    for(j=1;j<=i;++j)
    {
      _write(pre[i][j]);
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