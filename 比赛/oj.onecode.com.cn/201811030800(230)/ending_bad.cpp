#include<cstdio>
#include "memory.h"
#define ll long long
#define MAXN 10010
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
int d[MAXN][MAXN],n=0,cnt=0;
ll ans=0;
inline bool ok(int);
inline void read(int&);
void write(const ll&);
int main()
{
  register int i=0,u=0,v=0,w=0;
  memset(d,0x80,sizeof(d));
  read(n);
  for(i=1;i<n;++i)
  {
  	read(u);read(v);read(w);
  	d[u][v]=d[v][u]=ok(w);
  }
  for(u=1;u<=n;++u)
  {
  	for(v=1;v<=n;++v)
  	{
  	  for(i=1;i<=n;++i)
  	  {
  	    if(d[u][i]>=0&&d[i][v]>=0&&d[u][v]<max(d[u][i],d[i][v]))
  	    {
  	      d[u][v]=max(d[u][i],d[i][v]);
		}
	  }
	}
  }
  for(i=1;i<=n;++i)
  {
  	cnt=0;
	for(u=1;u<i;++u)
  	{
  	  cnt+=d[i][u]>0;
	}
	for(u=i+1;u<=n;++u)
	{
	  cnt+=d[i][u]>0;
	}
	ans+=cnt*(cnt-1);
  }
  write(ans);
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
  register char c=getchar();
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
inline bool ok(int x)
{
  for(register int k=0;x;x/=10)
  {
  	k=x%10;
	if(k!=4&&k!=7)
	{
	  return false;
	}
  }
  return true;
}
