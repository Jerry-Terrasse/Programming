#include<iostream>
#include "memory.h"
#define MAXN  20010
using namespace std;
int n=0,m=0,k=0,ans=0;
bool d[MAXN],a[MAXN],b[MAXN<<1],c[MAXN<<1];
void dfs(int);
int main()
{
  int i=0,x=0,y=0;
  cin>>n>>m>>k;
  for(;i<k;i++)
  {
  	cin>>x>>y;
  	a[y]=b[y+x]=c[y+MAXN-x]=d[x]=1;
  }
  for(y=1;y<=m;y++)
  {
  	if(!a[y])
  	{
  	  for(x=1;x<=n;x++)
  	  {
  	    ans+=!(b[y+x]|c[y+MAXN-x]|d[x]);
	  }
	}
  }
  cout<<ans<<endl;
  return 0;
}
