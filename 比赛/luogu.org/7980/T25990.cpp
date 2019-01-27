#include<iostream>
#include<vector>
#define MAXN 1000010
using namespace std;
vector<int>e[MAXN];
int k[MAXN],l[MAXN],f[MAXN],dfn[MAXN],low[MAXN],st[MAXN],ext[MAXN],cnt=0,top=0,num=0,n=0,m=0,ans=-1,rec=0;
void tj(int);
int dfs(int);
int main()
{
  int i=0,u=0,v=0;
  cin>>n>>m;
  for(i=1;i<=n;i++)
  {
    cin>>k[i];
    l[i]=k[i];
  }
  for(;m;m--)
  {
  	cin>>u>>v;
  	e[u].push_back(v);
  }
  for(i=1;i<=n;i++)
  {
  	if(dfs(i)>=ans && k[i]>k[rec])
  	{
  	  ans=dfs(i);
  	  rec=i;
	}
  }
  return 0;
}
int dfs(int x)
{
  int i=0,ans=0;
  if(f[x])
  {
  	return f[x];
  }
  ans=k[x];
  
  return ans;
}
void tj(int x)
{
  int i=0;
  dfn[x]=low[x]=++num;
  st[++top]=x;
  ext[x]=1;
  for(;i<e[x].size();i++)
  {
  	if(!dfn[e[x][i]])
  	{
  	  tj(e[x][i]);
  	  low[x]=min(low[x],low[e[x][i]]);
	}
	else if(ext[e[x][i]])
	{
	  low[x]=min(low[x],low[e[x][i]]);
	}
	if(dfn[x]==low[x])
	{
	  int add=0,mx=0,p=0;
	  for(;;)
	  {
	    p=st[top--];
	    ext[p]=0;
	    add+=k[p];
	    mx=max(mx,k[p]);
		if(x==p)
		{
		  break;
		}
	  }
	}
  }
  return;
}
