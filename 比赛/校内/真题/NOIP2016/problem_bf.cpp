#include<iostream>
#define ll long long
using namespace std;
int t=0,k=0,n=0,m=0,ans=0;
inline ll calc(const int&,const int&);
int main()
{
  register int i=0,j=0;
  cin>>t>>k;
  for(;t--;)
  {
  	cin>>n>>m;
  	for(i=0,ans=0;i<=n;++i)
  	{
  	  for(j=min(i,m);j>=0;--j)
  	  {
  	    if(calc(i,j)%k==0)
  	    {
  	      ++ans;
		}
	  }
	}
	cout<<ans<<endl;
  }
  return 0;
}
inline ll calc(const int &n,const int &m)
{
  register int i=0;
  register ll ans=1;
  for(i=1;i<=n;++i)
  {
  	ans*=i;
  }
  for(i=1;i<=m;++i)
  {
  	ans/=i;
  }
  for(i=n-m;i;--i)
  {
  	ans/=i;
  }
  return ans;
}
