#include<iostream>
#include<algorithm>
#define MAXN 110
using namespace std;
struct edge
{
  int from,to,w;
}e[MAXN*MAXN];
int us[MAXN],n=0,m=0,ans=0;
inline bool cmp(const edge&,const edge&);
int find(const int&);
int main()
{
  int i=1;
  for(cin>>n>>m;i<=m;i++)
  {
  	cin>>e[i].from>>e[i].to>>e[i].w;
  }
  for(i=1;i<=n;i++)
  {
  	us[i]=i;
  }
  sort(e+1,e+m+1,cmp);
  for(i=1;i<=m;i++)
  {
  	if(find(e[i].from)!=find(e[i].to))
  	{
  	  us[us[e[i].from]]=us[e[i].to];
	}
	else
	{
	  ans+=e[i].w;
	}
  }
  cout<<ans<<endl;
  return 0;
}
int find(const int &x)
{
  return us[x]==x?x:us[x]=find(us[x]);
}
inline bool cmp(const edge &a,const edge &b)
{
  return a.w<b.w;
}
