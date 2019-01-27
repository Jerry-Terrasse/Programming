#include<iostream>
#include "memory.h" 
#include<vector>
#define MAXN 20020
#define pr pair<int,int>
using namespace std;
vector<pr >e[MAXN];
int color[MAXN],n=0,m=0,ans=0;
bool bo=false;
void dfs(int,int);
int main()
{
  int i=0,u=0,v=0,w=0,l=0,r=0xffffffff;
  for(cin>>n>>m;m;m--)
  {
    cin>>u>>v>>w;
    e[u].push_back(make_pair(v,w));
    e[v].push_back(make_pair(u,w));
    if(r<w)
    {
      r=w;
	}
  }
  for(ans=(l+r)>>1;l!=r;)
  {
	//cout<<l<<"<="<<ans<<"<="<<r<<endl;
	memset(color,0,sizeof(color));
  	bo=true;
	for(i=1;i<=n && bo;i++)
  	{
  	  if(!color[i])
  	  {
  	    dfs(i,1);
	  }
	}
	if(bo)
	{
	  r=ans;
	}
	else
	{
	  l=ans+1;
	}
	ans=(l+r)>>1;
  }
  cout<<ans<<endl;
  return 0;
}
void dfs(int x,int co)
{
  int i=0;
  color[x]=co;
  for(;i<e[x].size();i++)
  {
  	if(e[x][i].second>ans)
  	{
  	  //cout<<e[x][i].first<<endl;
	  if(color[e[x][i].first])
	  {
	    if(color[e[x][i].first]==co)
	    {
	      bo=false;
	      return;
		}
	  }
	  else
	  {
	  	dfs(e[x][i].first,3-co);
	  	if(!bo)
	  	{
	  	  return;
		}
	  }
	}
  }
  return;
}
