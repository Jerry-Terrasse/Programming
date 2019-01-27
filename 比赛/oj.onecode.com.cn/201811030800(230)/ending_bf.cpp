#include<cstdio>
#include "memory.h"
#define ll long long
#define MAXN 100010
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
struct edge
{
  int to,w,next;
}e[MAXN<<1];
int head[MAXN],size[MAXN],n=0,cnt=0;
ll ans=0;
inline bool ok(int);
inline void read(int&);
void write(const ll&);
inline void addedge(const int&,const int&,const bool&);
int dfs(const int&,const int&);
int main()
{
  register int i=0,u=0,v=0,w=0;
  read(n);
  for(i=1;i<n;++i)
  {
  	read(u);read(v);read(w);
  	addedge(u,v,ok(w));
  }
  for(i=1;i<=n;++i)
  {
  	memset(size,0,sizeof(size));
	cnt=dfs(i,0);
  	ans+=cnt*(cnt-1);
  }
  write(ans);
  return 0;
}
int dfs(const int &x,const int &fa)
{
  register int ans=0,i=0,f=0;
  size[x]=1;
  for(i=head[x];i;i=e[i].next)
  {
  	if(e[i].to!=fa)
  	{
  	  f=dfs(e[i].to,x);
  	  ans+=e[i].w?size[e[i].to]:f;
	  size[x]+=size[e[i].to];
	}
  }
  return ans;
}
inline void addedge(const int &u,const int &v,const bool &w)
{
  e[++cnt].to=v;
  e[cnt].w=w;
  e[cnt].next=head[u];
  head[u]=cnt;
  e[++cnt].to=u;
  e[cnt].w=w;
  e[cnt].next=head[v];
  head[v]=cnt;
  return;
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
