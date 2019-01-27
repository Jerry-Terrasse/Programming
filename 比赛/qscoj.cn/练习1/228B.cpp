#include<iostream>
#include<algorithm>
#define MAXN 100010//MAXM=MAXN
using namespace std;
struct edge
{
  int u,v,c;
}e[MAXN];
int us[MAXN],n=0,m=0,ans=0;
inline bool cmp(edge,edge);
int fa(int);
int main()
{
  int i=0;
  ios::sync_with_stdio(0);
  cin>>n>>m;
  for(;i<m;i++)
  {
  	cin>>e[i].u>>e[i].v>>e[i].c;
  	ans+=e[i].c;
  }
  sort(e,e+m,cmp);
  for(i=1;i<=n;i++)
  {
  	us[i]=i;
  }
  for(i=0;i<m;i++)
  {
  	if(fa(e[i].u)!=fa(e[i].v))
  	{
  	  ans-=e[i].c;
  	  us[us[e[i].u]]=us[e[i].v];
	}
  }
  cout<<ans<<endl;
  return 0;
}
int fa(int x)
{
  return us[x]==x?x:(us[x]=fa(us[x]));
}
inline bool cmp(edge a,edge b)
{
  return a.c>b.c;
}
