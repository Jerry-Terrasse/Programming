#include<iostream>
#define ll long long
#define MAXN 100010
using namespace std;
ll a[MAXN],n=0,k=0,sum=0,ans=0;
int main()
{
  register int i=0,j=0;
  cin>>n>>k;
  for(i=1;i<=n;++i)
  {
  	cin>>a[i];
  }
  for(i=k;i<=n;++i)
  {
  	sum=0;
  	for(j=0;j<k;++j)
  	{
  	  sum+=a[i-j]*(k-j);
	}
	ans=max(ans,sum);
  }
  cout<<ans<<endl;
  return 0;
}
