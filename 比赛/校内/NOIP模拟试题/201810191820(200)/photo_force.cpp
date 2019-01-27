#include<iostream>
#define ll long long
#define MAXN 1010
using namespace std;
ll h[MAXN][2],n=0,s=0,ans=0x7fffffff;
inline void judge();
inline int btc(ll);
int main()
{
  int i=0;
  cin>>n;
  for(i=0;i<n;++i)
  {
  	cin>>h[i][false]>>h[i][true];
  }
  for(s=0;s<(1<<n);++s)
  {
  	judge();
  }
  cout<<ans<<endl;
  return 0;
}
inline void judge()
{
  if(btc(s)>(n>>1))
  {
  	return;
  }
  ll i=0,f=0,g=0;
  for(i=0;i<n;++i)
  {
  	f=max(f,h[i][s>>i&1^1]);
  	g+=h[i][s>>i&1];
  }
  if(f*g<ans)
  {
  	ans=f*g;
  }
  return;
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
