//U54223 Tweetuzki 爱取球
#include<iostream>
#define int long long
#define H 20040313
#define MAXN 10000010
using namespace std;
int f[MAXN],n=0,ans=0;
signed main()
{
  register int i=0;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n;
  ans=f[1]=1;
  for(i=2;i<=n;++i)
  {
    f[i]=-H/i*f[H%i];
    f[i]%=H;
    f[i]+=H;
    f[i]%=H;
    ans+=f[i];
  }
  ans%=H;
  ans*=n;
  ans%=H;
  cout<<ans;
  return 0;
}