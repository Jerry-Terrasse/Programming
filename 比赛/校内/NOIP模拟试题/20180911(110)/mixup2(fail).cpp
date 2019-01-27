#include<iostream>
#define MAXS 25050
#define MAXN 32
#define ok(x) (x>k)||(x<-k)
using namespace std;
struct edge
{
  int to,next;
}e[MAXN*MAXN]
int ext[MAXS],head[MAXN],no[MAXN],cnt=0,n=0,k=0,ans=0;
inline void addedge(int,int);
int main()
{
  int i=1,j=0;
  for(cin>>n>>k;i<=n;i++)
  {
    cin>>no[i];
    ext[no[i]]=1;
    for(j=1;j<i;j++)
    {
      if(ok(no[i]-no[j]))
      {
      	addedge(i,j);
	  }
	}
  }
  for(i=1;i<=n;i++)
  {
  	dfs(i);
  }
  return 0;
}
inline void addedge(int u,int v)
{
  e[++cnt].to=v;
  e[cnt].next=head[u];
  head[u]=cnt;
  e[++cnt].to=v;
  e[cnt].next=head[v];
  head[v]=cnt;
  return;
}
