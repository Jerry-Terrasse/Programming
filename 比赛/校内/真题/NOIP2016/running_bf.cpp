#include<cstdio>
#include "memory.h"
#define MAXN 300010
#define MAXE 22
#define MAX 2510
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
struct edge
{
  int to,next;
}e[MAXN<<1];
struct node
{
  int fa,id;
  //short rec[MAX];
}tr[MAXN];
int f[MAXN][MAXE],lca[MAXN],dep[MAXN],vis[MAXN],mxpt[MAXN],size[MAXN],head[MAXN],w[MAXN],s[MAXN],t[MAXN],ans[MAXN],n=0,m=0,cnt=0,root=0;
inline void read(int&);
void write(const int&);
inline void addedge(const int&,const int&);
void predfs(const int&);
void build(const int&);
inline void preca();
inline void findca();
inline void work1();
int main()
{
  int i=0,j=0,u=0,v=0;
  freopen("running.in","r",stdin);freopen("running.out","w",stdout);
  read(n);read(m);
  for(i=1;i<n;++i)
  {
  	read(u);read(v);
  	addedge(u,v);
  }
  for(i=1;i<=n;++i)
  {
  	read(w[i]);
  }
  for(i=1;i<=m;++i)
  {
  	read(s[i]);read(t[i]);
  }
  //if(n==99994)
  {
  	
	//return 0;
  }
  //if(n==99996)
  {
  	//build(1);
  	//for(i=1;i<=m;++i)
  	{
  	  //tr[s[i]].cnt=1;
  	  //tr[s[i]].rec
	}
  }
  mxpt[0]=0x7fffffff;
  predfs(1);
  memset(vis,0,sizeof(vis));
  build(root);
  preca();
  findca();
  work1();
  for(i=1;i<=n;++i)
  {
  	write(ans[i]);
  	putchar(' ');
  }
  return 0;
}
inline void work1()
{
  register int i=0,j=0,tim=0;
  for(i=1;i<=m;++i)
  {
	for(j=s[i],tim=0;j!=lca[i];j=tr[j].fa,++tim)
	{
	  ans[j]+=tim==w[j];
	}
	ans[j]+=tim==w[j];
	for(j=t[i],tim=dep[s[i]]+dep[t[i]]-(dep[lca[i]]<<1);j!=lca[i];j=tr[j].fa,--tim)
	{
	  ans[j]+=tim==w[j];
	}
  }
  return;
}
inline void findca()
{
  register int i=0,j=0,u=0,v=0;
  for(i=1;i<=m;++i)
  {
  	u=s[i];v=t[i];
  	if(dep[u]>dep[v])
  	{
  	  u^=v^=u^=v;
	}
	if(dep[u]<dep[v])
	{
	  for(j=MAXE;j--;)
	  {
	    if(dep[f[v][j]]>=dep[u])
	    {
	  	  v=f[v][j];
	    }
	  }
	}
	if(u!=v)
	{
	  for(j=MAXE;j--;)
	  {
	  	if(f[u][j]!=f[v][j])
	  	{
	  	  u=f[u][j];
	  	  v=f[v][j];
		}
	  }
	  u=f[u][0];
	}
	lca[i]=u;
  }
  return;
}
inline void preca()
{
  register int i=0,j=0;
  for(i=1;i<=n;++i)
  {
  	f[i][0]=tr[i].fa;
  }
  for(j=1;j<MAXE;++j)
  {
  	for(i=1;i<=n;++i)
  	{
  	  f[i][j]=f[f[i][j-1]][j-1];
	}
  }
  return;
}
void build(const int &x)
{
  register int i=0;
  tr[x].id=x;vis[x]=1;dep[x]=dep[tr[x].fa]+1;
  for(i=head[x];i;i=e[i].next)
  {
  	if(vis[e[i].to])
  	{
  	  continue;
	}
	tr[e[i].to].fa=x;
	//tr[x].son[++tr[x].cnt]=e[i].to;
	build(e[i].to);
  }
  return;
}
void predfs(const int &x)
{
  register int i=0;
  vis[x]=size[x]=1;
  for(i=head[x];i;i=e[i].next)
  {
  	if(vis[e[i].to])
  	{
  	  continue;
	}
	predfs(e[i].to);
	size[x]+=size[e[i].to];
	mxpt[x]=max(mxpt[x],size[e[i].to]);
  }
  mxpt[x]=max(mxpt[x],n-size[x]);
  if(mxpt[x]<mxpt[root])
  {
  	root=x;
  }
  return;
}
inline void addedge(const int &u,const int &v)
{
  e[++cnt].to=v;
  e[cnt].next=head[u];
  head[u]=cnt;
  e[++cnt].to=u;
  e[cnt].next=head[v];
  head[v]=cnt;
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
