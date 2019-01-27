#include<cstdio>
#include "memory.h"
#define MAXN 220
using namespace std;
int f[MAXN][MAXN][MAXN],a[MAXN],b[MAXN],n=0,m=0,t=0;
inline void read(int&);
void write(const int&);
inline void max(int&,const int&);
int main()
{
  register int i=0,j=0,k=0;
  read(n);read(m);read(t);
  for(i=1;i<=n;++i)
  {
    read(a[i]);read(b[i]);
  }
  for(i=1;i<=n;++i)
  {
    memcpy(f[i],f[i-1],sizeof(int)*MAXN*MAXN);
    for(j=a[i];j<=m;++j)
    {
      for(k=b[i];k<=t;++k)
      {
        max(f[i][j][k],f[i-1][j-1][k]);
        max(f[i][j][k],f[i-1][j][k-1]);
        max(f[i][j][k],f[i-1][j-a[i]][k-b[i]]+1);
      }
    }
  }
  write(f[n][m][t]);
  return 0;
}
inline void max(int &x,const int &y)
{
  if(x<y)
  {
    x=y;
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