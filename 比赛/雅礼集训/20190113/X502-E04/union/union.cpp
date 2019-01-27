#include<iostream>
#include "memory.h"
#define ll long long
//#define int long long
#define MAXN 22
#define H 1000000007
using namespace std;
int a[MAXN][MAXN],x[MAXN*MAXN],y[MAXN*MAXN],us[MAXN],n=0,cnt=0;
ll now=0,ans=0;
inline void work();
inline void init();
int find(const int&);
signed main()
{
  register int i=0,j=0;
  freopen("union.in","r",stdin);freopen("union.out","w",stdout);
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n;
  for(i=1;i<n;++i)
  {
    for(j=i+1;j<=n;++j)
    {
      cin>>a[i][j];
      if(a[i][j])
      {
        x[cnt]=i;
        y[cnt++]=j;
      }
    }
  }
  for(now=0;now<(1<<cnt);++now)
  {
    work();
  }
  cout<<ans<<endl;
  return 0;
}
inline void init()
{
  register int i=0;
  for(i=1;i<=n;++i)
  {
    us[i]=i;
  }
  return;
}
int find(const int &x)
{
  return us[x]==x?x:us[x]=find(us[x]);
}
inline void work()
{
  register int i=0;
  register ll ret=0;
  init();
  for(i=0;i<cnt;++i)
  {
    if((now>>i&1))
    {
      us[find(x[i])]=find(y[i]);
    }
  }
  for(i=2;i<=n;++i)
  {
    if(find(i)!=find(1))
    {
      return;
    }
  }
  for(i=0,ret=1;i<cnt;++i)
  {
    if(now>>i&1)
    {
      (ret*=a[x[i]][y[i]])%=H;
    }
  }
  (ans+=ret)%=H;
  return;
}
/*
4
3 0 8
5 0
2
*/
