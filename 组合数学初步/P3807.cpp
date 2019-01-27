#include<iostream>
#define int long long
#define MAXN 100010
#define register
using namespace std;
int arc[MAXN],n=0,m=0,H=0,t=0,ans=0;
inline void init();
inline void lucas(int,int);
inline int C(const int&,const int&);
signed main()
{
  //register int i=0;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>t;
  for(;t--;)
  {
    cin>>n>>m>>H;
    init();
    lucas(n+m,n);
    cout<<ans<<endl;
  }
  return 0;
}
inline int C(const int &n,const int &m)
{
  register int i=0,ans=1;
  if(n<m)
  {
    return 0;
  }
  for(i=n;i;--i)
  {
    (ans*=i)%=H;
  }
  for(i=m;i;--i)
  {
    (ans*=arc[i])%=H;
  }
  for(i=n-m;i;--i)
  {
    (ans*=arc[i])%=H;
  }
  return ans;
}
inline void lucas(int n,int m)
{
  register int i=0;
  for(;n||m;n/=H,m/=H)
  {
    (ans*=C(n%H,m%H))%=H;
  }
  return;
}
inline void init()
{
  register int i=0;
  ans=arc[1]=1;
  for(i=2;i<H;++i)
  {
    (arc[i]=-H/i*arc[H%i]%H+H)%=H;
  }
  return;
}