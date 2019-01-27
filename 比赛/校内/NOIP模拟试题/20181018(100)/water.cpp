#include<iostream>
#define ll long long
#define lbt(x) ((x)&-(x))
using namespace std;
ll n=0,k=0,ans=0;
inline int btc(ll);
int main()
{
  int i=0;
  freopen("water.in","r",stdin);freopen("water.out","w",stdout);
  cin>>n>>k;
  for(;btc(n)>k;)
  {
  	ans+=lbt(n);
  	n+=lbt(n);
  }
  cout<<ans<<endl;
  return 0;
}
inline int btc(ll x)
{
  int ans=0;
  for(;x;++ans)
  {
  	x&=x-1;
  }
  return ans;
}
