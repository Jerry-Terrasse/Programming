#include<cstdio>
#include "memory.h"
#define MAXN 10010
#define max(x,y) ((x)<(y)?(y):(x))
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
int f[MAXN][MAXN<<2],a[MAXN],b[MAXN],n=0,ma=0,mb=0,ans=0;
char c='\0';
inline void read(int&);
void write(const int&);
int main()
{
  register int i=0,j=0,k=0;
  freopen("huaji.in","r",stdin);freopen("huaji.out","w",stdout);
  memset(f,0x80,sizeof(f));
  read(n);read(ma);read(mb);
  for(i=1;i<=n;++i)
  {
  	read(a[i]);
  }
  for(i=1;i<=n;++i)
  {
  	read(b[i]);
  }
  for(i=1,f[0][0]=0;i<=n;++i)
  {
  	for(j=min(i,ma);j>=1;--j)
  	{
	  for(k=min(i,mb);k>=1;--k)
  	  {
		f[j][k]=max(f[j][k],max(f[j-1][k]+a[i],f[j][k-1]+b[i]));
	  }
  	  f[j][0]=max(f[j][0],f[j-1][0]+a[i]);
	}
	for(k=mb;k>=1;--k)
	{
	  f[0][k]=max(f[0][k],f[0][k-1]+b[i]);
	}
  }
  for(j=0;j<=ma;++j)
  {
  	for(k=0;k<=mb;++k)
  	{
  	  ans=max(ans,f[j][k]);
	}
  }
  write(ans);
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
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
