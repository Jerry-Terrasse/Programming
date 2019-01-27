#include<iostream>
#include<algorithm>
#include<cstdlib>
#define int long long
#define MAXN 77
using namespace std;
int f[MAXN],fc=0,n=1,now=0,ans=0,ansnow=0;
inline void judge();
signed main()
{
  register int i=0;
  if(n>30)
  {
    exit(0);
  }
  for(now=0;now<(1LL<<n);++now)
  {
    judge();
  }
  cout<<ans<<':';
  for(i=0;i<n;++i)
  {
    if(ansnow>>i&1)
    {
      cout<<i+1<<' ';
    }
  }
  cout<<endl;
  ++n;
  main();
  return 0;
}
inline void judge()
{
  register int i=0,j=0;
  for(i=fc=0;i<n;++i)
  {
    if(now>>i&1)
    {
      f[++fc]=i+1;
    }
  }
  for(i=1;i<=fc;++i)
  {
    for(j=i+1;j<=fc;++j)
    {
      if(__gcd(f[i],f[j])>1)
      {
        return;
      }
    }
  }
  for(i=1,j=0;i<=fc;++i)
  {
    j+=f[i];
  }
  if(j>ans)
  {
    ans=j;
    ansnow=now;
  }
  return;
}