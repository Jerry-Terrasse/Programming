#include<cstdio>
#include<algorithm>
#include "memory.h"
#define ll long long
#define MAXN 1000010
#define MAXD 10
using namespace std;
int a[MAXN][MAXD],n=0,d=0;
ll f[MAXD][MAXN],minf[MAXD],maxf[MAXD],ans=0;
char c='\0',o='\0';
inline void read(int&);
void write(const ll&);
int main()
{
  int i=0,j=0,k=0;
  freopen("jail.in","r",stdin);freopen("jail.out","w",stdout);
  memset(minf,0x3f,sizeof(minf));
  read(n);read(d);
  for(i=0;i<n;++i)
  {
  	for(j=0;j<d;++j)
  	{
      read(a[i][j]);
    }
    for(j=0;j<(1<<d>>1);++j)
    {
   	  for(k=1,f[j][i]=a[i][0];k<d;++k)
   	  {
        f[j][i]+=(j<<1>>k&1)?-a[i][k]:a[i][k];
      }
      if(minf[j]>f[j][i])
      {
      	minf[j]=f[j][i];
	  }
	  if(maxf[j]<f[j][i])
	  {
	  	maxf[j]=f[j][i];
	  }
	}
  }
  for(i=0;i<(1<<d>>1);++i)
  {
  	ans=max(abs(minf[i]-maxf[i]),ans);
  }
  write(ans);
  putchar('\n');
  return 0;
}
void write(const ll &x)
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
  for(x=0,o=0;c<'0'||c>'9';c=getchar())
  {
  	if(c=='-')
  	{
      o=1;
    }
  }
  for(;c>='0'&&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  if(o)
  {
  	x=-x;
  }
  return;
}
