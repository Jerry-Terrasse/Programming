#include<cstdio>
#include "memory.h"
#define MAXN 17
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
int f[1<<MAXN],g[1<<MAXN],a[MAXN],b[MAXN],c[MAXN],maxa=0,maxb=0,n=0,k=0,ans=0;
inline void read(int&);
void write(const int&);
void predfs(const int&);
void dfs(const int&,const int&,const int&);
inline int btc(int);
int main()
{
  register int i=0,j=0;
  freopen("envelope.in","r",stdin);freopen("envelope.out","w",stdout);
  read(n);read(k);
  for(i=1;i<=n;++i)
  {
  	read(a[i]);read(b[i]);read(c[i]);
  }
  if(k==1)
  {
  	for(i=1;i<=n;++i)
  	{
  	  if(maxa<a[i])
  	  {
  	    maxa=a[i];
	  }
	  if(maxb<b[i])
	  {
	  	maxb=b[i];
	  }
	}
	maxa*=maxb;
	for(i=1;i<=n;++i)
	{
	  ans+=(maxa-a[i]*b[i])*c[i];
	}
	write(ans);
	return 0;
  }
  if(k==n)
  {
  	write(0);
	return 0;
  }
  if(n<=200)
  {
  	memset(f,-1,sizeof(f));
  	memset(g,-1,sizeof(g));
  	f[0]=0;ans=0x7fffffff;
	predfs((1<<n)-1);
	dfs(1,0,(1<<n)-1);
	for(i=1;i<=n;++i)
	{
	  ans-=a[i]*b[i];
	}
  	write(ans);
  	return 0;
  }
  return 0;
}
inline int btc(int x)
{
  register int ans=0;
  for(;x;x&=x-1,++ans);
  return ans;
}
void dfs(const int &x,const int &sum,const int &now)
{
  if(x>k)
  {
  	if(sum<ans)
  	{
  	  ans=sum;
	}
	return;
  }
  register int nxt=0;
  //dfs(x+1,sum,now);
  for(nxt=now;nxt;nxt=(nxt-1)&now)
  {
  	dfs(x+1,sum+f[nxt]*g[nxt]*btc(nxt),now^nxt);
  }
  return;
}
void predfs(const int &now)
{
  register int i=0;
  for(;i<n;++i)
  {
  	if(now>>i&1)
  	{
  	  if(f[1<<i^now]==-1)
  	  {
  	    predfs(1<<i^now);
	  }
	  f[now]=max(f[1<<i^now],a[i+1]);
	  g[now]=max(g[1<<i^now],b[i+1]);
	  break;
	}
  }
  for(;i<n;++i)
  {
  	if((now>>i&1)&&f[1<<i^now]==-1)
  	{
  	  predfs(1<<i^now);
	}
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
