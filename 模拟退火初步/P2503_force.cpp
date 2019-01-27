#include<iostream>
#include<cmath>
#include<iomanip>
#define ld long double
#define MAXN 32
#define sqr(x) ((x)*(x))
using namespace std;
int a[MAXN],p[MAXN],sum[MAXN],n=0,m=0;
ld av=0,s=0,ans=999999;
void dfs(int);
int main()
{
  int i=0;
  for(cin>>n>>m;i<n;i++)
  {
  	cin>>a[i];
  	av+=a[i];
  }
  av/=m;
  dfs(0);
  ans/=m;
  ans=sqrt(ans);
  cout<<fixed<<setprecision(2)<<ans<<endl;
  return 0;
}
void dfs(int x)
{
  if(x==n)
  {
  	s=0;
  	for(int i=0;i<m;i++)
  	{
  	  s+=sqr(sum[i]-av);
	}
	if(s<ans)
	{
	  ans=s;
	}
	return;
  }
  for(p[x]=0;p[x]<m;p[x]++)
  {
  	sum[p[x]]+=a[x];
  	dfs(x+1);
  	sum[p[x]]-=a[x];
  }
  return;
}
