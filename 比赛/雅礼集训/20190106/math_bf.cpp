#include<iostream>
#include<cmath>
#define ld double
#define MAXM 33
#define MAXN 10010
using namespace std;
int f[MAXM],n=0,m=0,t=0;
ld msn[MAXN],x=0,ans=0;
void dfs(const int&,const int&);
inline void work();
inline void init();
int main()
{
  register int i=0;
  freopen("math.in","r",stdin);freopen("math.out","w",stdout);
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>t;
  for(;t--;)
  {
    cin>>m>>n>>x;
    init();
    dfs(1,n);
    if(ans<0)
    {
      cout<<'-';
      ans=-ans;
    }
    else
    {
      cout<<'+';
    }
    //cout<<ans<<"->";
    for(;ans<1;ans*=10);
    for(;ans>=10;ans/=10);
    cout<<(int)ans<<endl;
  }
  return 0;
}
inline void init()
{
  register int i=0;
  ans=0;
  for(i=1;i<=n;++i)
  {
    msn[i]=sin(x*i);
  }
  return;
}
inline void work()
{
  register ld ret=1;
  register int i=0;
  for(i=1;i<=m;++i)
  {
    //cout<<f[i]<<' ';
    //ret*=sin(x*f[i]);
    ret*=msn[f[i]];
  }
  //cout<<endl;
  ans+=ret;
  return;
}
void dfs(const int &x,const int &rem)
{
  if(x==m)
  {
    f[m]=rem;
    work();
    return;
  }
  for(f[x]=rem+x-m+1;--f[x];)
  {
    dfs(x+1,rem-f[x]);
  }
  return;
}
//0.00067143379688921383