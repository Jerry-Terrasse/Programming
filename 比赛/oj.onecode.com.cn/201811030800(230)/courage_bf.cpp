#include<iostream>
#include<cstdio>
#define ll long long
#define MAXN 1000010
//#define INF 0x7ffffffe
#define INF 1e7
using namespace std;
int n=0;
inline int ok(ll);
int main()
{
  register ll i=0,j=0;
  //for(n=1;n<=256;++n)
  cin>>n;
  for(i=0;i<INF;++i)
  {
  	if(ok(i)==n)
  	{
  	  //cout<<n<<':'<<i<<endl;
  	  cout<<i<<endl;
	  break;
	}
  }
  return 0;
}
inline int ok(ll x)
{
  register int ans=0,k=0;
  for(;x;x/=10)
  {
  	k=x%10;
  	if(k==4||k==7)
  	{
  	  ans+=k;
	}
	else
	{
	  return 0;
	}
  }
  return ans;
}
