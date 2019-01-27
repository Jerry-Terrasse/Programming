#include<iostream>
#include<algorithm>
#define ll long long
#define MAXN 100010
using namespace std;
ll a[MAXN],b[MAXN],n=0,k=0,ans=0;
int main()
{
  int i=0;
  cin>>n>>k;
  for(i=1;i<=n;++i)
  {
  	cin>>a[i];
  }
  sort(a+1,a+n+1);
  for(i=1;i<n;++i)
  {
  	b[i]=a[i+1]-a[i];
  }
  sort(b+1,b+n);
  for(i=1;i<=k;++i)
  {
  	ans+=b[i];
  }
  cout<<ans<<endl;
  return 0;
}
