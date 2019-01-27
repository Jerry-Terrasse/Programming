#include<iostream>
#include<iomanip>
#define ld long double
#include<vector>
#include<bitset>
#define MAXN 100010
using namespace std;
ld ans=0;
int d[MAXN],n=0,m=0;
vector<pair<int,int> >e[MAXN];
bitset<MAXN>ext[MAXN];
void dfs(int,int);
inline bool ok();
inline void value();
int main()
{
  int i=0,u=1,v=0,w=0;
  freopen("graph.in","r",stdin);freopen("graph.out","w",stdout);
  ios::sync_with_stdio(0);
  for(cin>>n>>i;u<=n;u++)
  {
	cin>>d[u];
  	ext[0][u]=1;
  }
  for(;i;i--)
  {
  	cin>>u>>v>>w;
  	ext[u][v]=ext[v][u]=1;
  	e[u].push_back(make_pair(v,w));
  	e[v].push_back(make_pair(u,w));
  }
  if(n<2)
  {
  	cout<<0<<endl;
  	return 0;
  }
  if(n==2)
  {
  	if(ok())
  	{
  	  value();
	  cout<<ans<<endl;
	}
	else
	{
	  cout<<0<<endl;
	}
	return 0;
  }
  dfs(0,1);
  cout<<fixed<<setprecision(2)<<ans<<endl;
  fclose(stdin);fclose(stdout);
  return 0;
}
inline void value()
{
  ld dot=0,edge=0;
  int i=0,j=0;
  for(i=1;i<=n;i++)
  {
  	if(!ext[0][i])
  	{
  	  continue;
	}
	dot+=d[i];
	for(j=0;j<e[i].size();j++)
  	{
  	  if(e[i][j].first>i && ext[i][e[i][j].first])
  	  {
  	  	edge+=e[i][j].second;
	  }
	}
  }
  dot/=edge;
  if(dot>ans)
  {
  	ans=dot;
  }
  return;
}
inline bool ok()
{
  int i=0,j=0;
  for(i=1;i<=n;i++)
  {
  	for(j=i+1;j<=n;j++)
  	{
  	  if(ext[0][i] && ext[0][j] && !ext[i][j])
  	  {
  	  	return false;
	  }
	}
  }
  return true;
}
void dfs(int x,int o)
{
  if(ok())
  {
  	value();
  }
  if(x==n-2)
  {
  	return;
  }
  int i=o,j=0;
  for(;i<=n;i++)
  {
  	ext[0][i]=0;
  	for(j=0;j<e[i].size();j++)
  	{
  	  ext[i][e[i][j].first]=ext[e[i][j].first][i]=0;
	}
	dfs(x+1,i+1);
	ext[0][i]=1;
  	for(j=0;j<e[i].size();j++)
  	{
  	  ext[i][e[i][j].first]=ext[e[i][j].first][i]=1;
	}
  }
  return;
}
