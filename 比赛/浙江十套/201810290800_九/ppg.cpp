#include<iostream>
#define ll long long
#define MAXN 64
#define max(x,y) ((x)<(y)?(y):(x))
#define abs(x) ((x)<0?-(x):(x))
#define dis(u,v) (abs(x[u]-x[v])+abs(y[u]-y[v]))
using namespace std;
ll x[MAXN],y[MAXN],n=0,ans=0;
int main()
{
  int i=0,j=0;
  freopen("ppg.in","r",stdin);freopen("ppg.out","w",stdout);
  cin>>n;
  for(i=1;i<=n;++i)
  {
  	cin>>x[i]>>y[i];
  }
  for(i=1;i<=n;++i)
  {
  	for(j=i+1;j<=n;++j)
  	{
  	  ans=max(ans,dis(i,j));
	}
  }
  cout<<(ans+1>>1)<<endl;
  return 0;
}
