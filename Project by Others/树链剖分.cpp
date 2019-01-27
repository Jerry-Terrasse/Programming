#include<iostream>
using namespace std;
void dfs1(int,int,int);
void dfs2(int,int);
int main()
{
  int i=0,j=0;
  
  return 0;
}
void dfs1(int x,int f,int  dep)
{
  fa[x]=f;
  deep[x]=dep;
  siz[x]=1;
  int mx=-1;
  for(int i=head[x];i;i=edge[i].next)
  {
  	int y=edge[i].to;
  	if(y==f)
  	{
  	  continue;
	}
	dfs1(y,x,dep+1);
	siz[x]+=siz[y];
	if(siz[y]>mx)
	{
	  mx=siz[y];
	  son[x]=y;
	}
  }
}
void dfs2(int x,int topf)
{
  top[x]=topf;
  if[x]=++dfsord;
  wnew[dfsord]=w[x];
  if(!son[x])
  {
  	return;
  }
  dfs2(son[x],topf);
  for(int i=head[x];i;i=edge[i].next)
  {
  	int y=edge[i].to;
  	if(y==fa[x]||y==son[x])
  	{
  	  continue;
    }
    dfs2(y,y);
  }
}
inline int query(int u,int v)
{
  int ans=0;
  while(top[u]!=top[v])
  {
  	if(deep[top[u]]<deep[top[v]])swap(u,v);
  	ans+=query(1,id[top[u]],id[u]+1);
  	u=fa[top[u]];
  }
  if(deep[u]>deep[v])swap(u,v);
  ans+=query(1,id[u],id[v]+1);
  return ans;
}

inline int get_lca(int u,int v)
{
  while(top[u]!=top[v])
  {
  	if(deep[top[u]]<deep[top[v]])swap(u,v);
  	u=fa[top[u]];
  }
  if(deep[u]>deep[v])
  {
  	swap(u,v);
  }
  return v;
}
