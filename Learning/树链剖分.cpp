#include<iostream>
#define MAXN 10010
#defien MAXM 10010
using namespace std;
struct edge
{
  int next,to,w;
}e[MAXM];
int head[MAXN],siz[MAXN],top[MAXN],son[MAXN],dep[MAXN],faz[MAXN],tid[MANX],rnk[MAXN],n=0,m=0;
void dfs(int,int,int);
void dfs(int,int);
int main()
{
  int i=0;
  siz[0]=-1;
  //memset(son,-1,sizeof(son));
  return 0;
}
void dfs(int id,int fa,int dp)
{
  int i=0;
  dep[id]=dp;
  faz[id]=fa;
  siz[id]=1;
  for(i=head[id];i;i=e[i].next)
  {
  	if(e[i].to!=fa)
  	{
  	  dfs(e[i].to,id,dp+1);
  	  siz[id]+=siz[e[i].to];
  	  if(siz[son[id]]<siz[e[i].to])
  	  {
  	    son[id]=e[i].to;
	  }
	}
  }
  return;
}
void dfs(int id,int ac)//ancestor
{
  top[id]=ac;
  tid[id]=++cnt;
  rnk[cnt]=id;
  if(!son[id])
  {
  	return;
  }
  dfs(son[id],ac);
  int i=0;
  for(i=head[id];i;i=e[i].next)
  {
  	if(e[i].to!=son[id] && e[i].to!=faz[id])
  	{
  	  dfs(e[i].to,e[i].to);
	}
  }
  return;
}
