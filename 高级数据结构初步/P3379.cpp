#include<cstdio>
#define MAXN 500050
#define MAXA 20
using namespace std;
struct edge
{
  int next,to;
}e[MAXN<<2];
int f[MAXN][MAXA],head[MAXN],dep[MAXN],cnt=0,r=0,n=0,m=0,maxd=0;
inline void addedge(int,int);
void dfs(int,int);
inline void read(int&);
int main()
{
  int i=1,j=0,u=0,v=0,maxp=0;
  for(read(n),read(m),read(r);i<n;i++)
  {
  	read(u);read(v);
    addedge(u,v);
  }
  dfs(r,0);
  /*for(i=1;(1<<i)<n;i++)
  {
  	for(j=1;j<=n;j++)
  	{
  	  f[j][i]=f[f[j][i-1]][i-1];
	}
  }*/
  for(;(1<<maxp)<maxd;maxp++);
  for(i=1;i<=m;i++)
  {
  	read(u),read(v);
  	if(dep[u]>dep[v])
  	{
  	  u^=v;
  	  v^=u;
  	  u^=v;
	}
	for(j=maxp;j>=0;j--)
	{
	  if(dep[f[v][j]]>=dep[u])
	  {
	  	v=f[v][j];
	  }
	}
	if(u==v)
	{
	  printf("%i\n",u);
	  continue;
	}
	for(j=maxp;j>=0;j--)
	{
	  if(f[u][j]!=f[v][j])
	  {
	  	u=f[u][j];
	  	v=f[v][j];
	  }
	}
	printf("%i\n",f[u][0]);
  }
  return 0;
}
inline void read(int &x)
{
  char c=getchar();
  for(x=0;c<'0'||c>'9';c=getchar());
  for(;c>='0'&&c<='9';c=getchar())
  {
  	x=(x<<3)+(x<<1)+c-'0';
  }
  return;
}
void dfs(int r,int fa)
{
  int i=0;
  f[r][0]=fa;
  dep[r]=dep[fa]+1;
  if(dep[r]>maxd)
  {
  	maxd=dep[r];
  }
  for(i=1;(1<<i)<dep[r];i++)
  {
  	f[r][i]=f[f[r][i-1]][i-1];
  }
  for(i=head[r];i;i=e[i].next)
  {
  	if(dep[e[i].to])
  	{
  	  continue;
	}
	dfs(e[i].to,r);
  }
  return;
}
inline void addedge(int u,int v)
{
  e[++cnt].to=v;
  e[cnt].next=head[u];
  head[u]=cnt;
  e[++cnt].to=u;
  e[cnt].next=head[v];
  head[v]=cnt;
  return;
}
