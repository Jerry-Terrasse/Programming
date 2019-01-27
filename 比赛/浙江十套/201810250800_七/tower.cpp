#include<iostream>
#include<vector>
#define MAXN 55
#define MAX 24
#define MAXH 500000
#define ll long long
#define lbt(x) ((x)&-(x))
using namespace std;
int g[1<<MAX],cnt[MAXH],a[MAXN],n=0,ans=0;
vector<int>f[MAXH];
void dfs1(ll);
int main()
{
  int i=0,j=0;
  freopen("tower.in","r",stdin);freopen("tower.out","w",stdout);
  cin>>n;
  for(i=0;i<n;++i)
  {
  	cin>>a[i];
  }
  dfs1((1<<n)-1);
  if(ans)
  {
  	cout<<ans<<endl;
  }
  else
  {
  	cout<<-1<<endl;
  }
  return 0;
}
void dfs1(ll x)
{
  if((!x)||g[x])
  {
  	return;
  }
  int i=0,j=0,h=0;
  for(;i<n;++i)
  {
  	if(x>>i&1)
  	{
  	  dfs1(x^(1<<i));
	}
  }
  for(i=0;i<n;++i)
  {
  	if(x>>i&1)
  	{
  	  break;
	}
  }
  g[x]=h=g[x^(1<<i)]+a[i];
  for(j=0;j<cnt[h];++j)
  {
    if((!(f[h][j]&x))&&ans<h)
    {
      ans=h;
	}
  }
  ++cnt[h];
  f[h].push_back(x);
  return;
}
