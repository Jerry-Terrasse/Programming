#include<cstdio>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include "memory.h"
#define db double
#define MAXN 220
#define MAXT 1e7
#define MINT 1e-7
#define dt 0.99
#define AC 2702
#define min(x,y) ((x)<(y)?(x):(y))
#define rr(x) (rand()*rand()%(x))
using namespace std;
double t=0;
int f[2][MAXN],g[MAXN],use[MAXN],a[MAXN],b[MAXN],cnt[2],n=0,ans=0x7fffffff;
char c='\0';
inline void SA();
inline void make();
inline void calc(int&);
inline void move(const int&,const int&,const int&,const int&);
inline void read(int&);
void write(const int&);
int main()
{
  register int i=0;
  freopen("sort.in","r",stdin);freopen("sort.out","w",stdout);
  read(n);
  for(i=1;i<=n;++i)
  {
  	read(a[i]);read(b[i]);
  }
  if(n<=4)
  {
  	i=1077;
  }
  else
  {
  	i=AC/n+77;
  }
  for(;i--;SA());
  write(ans);
  putchar('\n');
  return 0;
}
inline void SA()
{
  register int i=0,j=0,k=0,l=0,pre=0,now=0;
  make();
  calc(pre);
  if(ans>pre)
  {
  	ans=pre;
  }
  for(t=MAXT;t>MINT;t*=dt)
  {
  	k=rr(2);l=rr(2);
  	if(!cnt[k])
  	{
  	  k^=1;
	}
	i=rr(cnt[k])+1;
	if(l==k)
	{
	  j=rr(cnt[l])+1;
	}
	else
	{
	  j=rr(cnt[l]+1)+1;
	}
	move(k,i,l,j);
	calc(now);
	if(pre>now)
	{
	  pre=now;
	  if(ans>now)
	  {
	  	ans=now;
	  }
	}
	else if(exp(-t)<(db)(rr(7777777)/7777777))
	{
	  pre=now;
	}
	else
	{
	  move(l,j,k,i);
	}
  }
  //write(emm);
  //putchar('\n');
  return;
}
inline void move(const int &k,const int &x,const int &l,const int &y)
{
  register int i=0;
  int a=f[k][x];
  for(i=x;i<cnt[k];++i)
  {
  	f[k][i]=f[k][i+1];
  }
  --cnt[k];
  for(i=cnt[l]+1;i>y;--i)
  {
  	f[l][i]=f[l][i-1];
  }
  f[l][y]=a;
  ++cnt[l];
  return;
}
inline void calc(int &ans)
{
  register int i=0,j=0;
  for(ans=0,i=0;i<2;++i)
  {
  	for(j=1;j<=cnt[i];++j)
  	{
  	  g[f[i][j]]=g[f[i][j-1]]+a[f[i][j-1]];
  	  if(ans<g[f[i][j]]+a[f[i][j]]+b[f[i][j]])
  	  {
  	    ans=g[f[i][j]]+a[f[i][j]]+b[f[i][j]];
	  }
	}
  }
  return;
}
inline void make()
{
  register int i=0,j=0;
  cnt[0]=cnt[1]=0;
  memset(f,0,sizeof(f));
  memset(use,0,sizeof(use));
  for(i=7;i;--i)
  {
  	cnt[0]+=rr(n)+1;
  }
  cnt[0]/=7;
  cnt[1]=n-cnt[0];
  for(i=1;i<=cnt[0];)
  {
  	j=rr(n)+1;
  	if(use[j])
  	{
  	  continue;
	}
	use[j]=1;
	f[0][i++]=j;
  }
  for(i=1;i<=cnt[1];)
  {
  	j=rr(n)+1;
  	if(use[j])
  	{
  	  continue;
	}
	use[j]=1;
	f[1][i++]=j;
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
  for(x=0;c<'0'||c>'9';c=getchar());
  for(;c>='0'&&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
