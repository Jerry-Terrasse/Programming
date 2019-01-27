#include<iostream>
#include<cmath>
#define MAXN 100010
#define ll long long
using namespace std;
ll n=0,p=0,q=0,ans=0;
int main()
{
  ll i=0;
  cin>>n>>p>>q;
  ans=n>>1;
  if(n&1)
  {
  	ans++;
	if(p)
  	{
  	  p--;
	}
	if(q)
	{
	  q--;
	}
  }
  ans+=ceil((double)(p+q)/4);
  cout<<ans<<endl;
  return 0;
}
