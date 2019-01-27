#include<iostream>
#define ll long long
#define MAXN 1000010
#define MAXD 8
#define max(x,y) ((x)<(y)?(y):(x))
#define abs(x) ((x)<0?-(x):(x))
using namespace std;
ll a[MAXN][MAXD],n=0,d=0,ans=0;
int main()
{
  ll i=0,j=0,k=0,dis=0;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>d;
  for(i=1;i<=n;++i)
  {
  	for(j=0;j<d;++j)
  	{
      cin>>a[i][j];
    }
  }
  for(i=1;i<=n;++i)
  {
  	for(j=i+1;j<=n;++j)
  	{
      for(k=0,dis=0;k<d;++k)
      {
      	dis+=abs(a[i][k]-a[j][k]);
	  }
	  ans=max(ans,dis);
    }
  }
  cout<<ans<<endl;
  return 0;
}
