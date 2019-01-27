#include<iostream>
#include<iomanip>
#include<cmath>
#define ld long double
#define MAXN 16
#define sqr(x) ((x)*(x))
using namespace std;
ld pos[MAXN][2],dis[MAXN][MAXN],vis[MAXN],n=0,ans=0x7fffffff;
void dfs(const int&,const int&,const ld&);
int main()
{
  int i=0,j=0;
  cin>>n;
  for(i=1;i<=n;++i)
  {
  	cin>>pos[i][0]>>pos[i][1];
  }
  for(i=0;i<=n;++i)
  {
  	for(j=1;j<=n;++j)
  	{
  	  if(i<=j)
  	  {
  	    dis[i][j]=sqrt(sqr(pos[i][0]-pos[j][0])+sqr(pos[i][1]-pos[j][1]));
	  }
	  else
	  {
	  	dis[i][j]=dis[j][i];
	  }
	}
  }
  dfs(0,0,0);
  cout<<fixed<<setprecision(2)<<ans<<endl;
  return 0;
}
void dfs(const int &x,const int &f,const ld &s)
{
  int i=0;
  if(ans<=s)
  {
  	return;
  }
  if(x==n)
  {
  	ans=s;
  }
  for(i=1;i<=n;++i)
  {
  	if(vis[i])
  	{
  	  continue;
	}
	vis[i]=1;
	dfs(x+1,i,s+dis[f][i]);
	vis[i]=0;
  }
  return;
}
