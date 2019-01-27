#include<iostream>
#define MAXN 500050
#define MAXD 20
using namespace std;
struct edge
{
  int to,next;
}e[MAXN];
int fa[MAXN][MAXD],head[MAXN],cnt=0,n=0,m=0,s=0;
void dfs(int,int);
void dfs(int);
inline void add(int,int);
int main()
{
  int i=0,u=0,v=0;
  for(cin>>n>>m>>s;m;m--)
  {
  	cin>>u>>v;
  	add(u,v);
  	add(v,u);
  }
  dfs(s,0);
  dfs(s);
  return 0;
}
void dfs(int x)
{
  int i=1;
  for(;fa[x][i-1]!=0;i++)
  {
  	fa[x][i]=fa[fa[x][i-1]][i-1];
  }
  return;
}
void dfs(int x,int father)
{
  int i=0;
  fa[x][0]=father;
  for(i=head[x];i;i=e[i].next)
  {
  	if(e[i].to!=father)
  	{
  	  dfs(e[i].to,x);
	}
  }
  return;
}
inline void add(int u,int v)
{
  e[++cnt].to=v;
  e[cnt].next=head[u];
  head[u]=cnt;
  return;
}
