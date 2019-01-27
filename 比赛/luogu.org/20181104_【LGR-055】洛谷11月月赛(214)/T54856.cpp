#include<iostream>
#include<algorithm>
#define ll long long
#define MAXN 330
#define sqr(x) ((x)*(x))
using namespace std;
int a[MAXN],n=0;
ll ans=0;
int main()
{
  register int i=0,j=0;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n;
  for(i=1;i<=n;++i)
  {
  	cin>>a[i];
  }
  sort(a+1,a+n+1);
  for(i=1,j=n;i<=j;++i,--j)
  {
  	ans+=sqr(a[i-1]-a[j])+sqr(a[i]-a[j]);
  }
  cout<<ans<<endl;
  return 0;
}
