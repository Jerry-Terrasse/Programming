//P3935 Calculating
#include<iostream>
#define int long long
#define H 998244353
using namespace std;
int n=0,m=0,ans=0;
inline int work(const int&);
signed main()
{
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n>>m;
  ans=work(m);
  ans-=work(n-1);
  if(ans<0)
  {
    ans+=H;
  }
  cout<<ans<<endl;
  return 0;
}
inline int work(const int &x)
{
  register int i=0,j=0,ret=0;
  for(i=1;i<=x;i=j+1)
  {
    j=x/(x/i);
    ret+=(j+1-i)*(x/i);
    ret%=H;
  }
  return ret;
}