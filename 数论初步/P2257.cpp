//P2257 YY的GCD
#include<iostream>
#include "memory.h"
#define ll long long
#define MAXN 10000000
using namespace std;
int f[MAXN],mu[MAXN],zs[MAXN],zc=0,n=0,m=0,t=0;
ll ans=0;
inline void mb();
inline int min(const int&,const int&);
signed main()
{
  register int i=0,j=0;
  ios::sync_with_stdio(false);cin.tie(0);
  mb();
  cin>>t;
  for(;t--;)
  {
    ans=0;
    cin>>n>>m;
    if(n>m)
    {
      n^=m^=n^=m;
    }
    for(i=1;i<=n;i=j+1)
    {
      j=min(n/(n/i),m/(m/i));
      ans+=(ll)(f[j]-f[i-1])*(n/i)*(m/i);
    }
    cout<<ans<<endl;
  }
  return 0;
}
inline void mb()
{
  register int i=0,j=0;
  memset(zs,-1,sizeof(zs));
  for(i=2,mu[1]=1;i<MAXN;++i)
  {
    if(zs[i])
    {
      zs[++zc]=i;
      mu[i]=-1;
    }
    for(j=1;j<=zc&&i*zs[j]<MAXN;++j)
    {
      zs[i*zs[j]]=0;
      if(i%zs[j])
      {
        mu[i*zs[j]]=-mu[i];
      }
      else
      {
        break;
      }
    }
  }
  for(j=1;j<=zc;++j)
  {
    for(i=1;i*zs[j]<MAXN;++i)
    {
      f[i*zs[j]]+=mu[i];
    }
  }
  for(i=2;i<MAXN;++i)
  {
    f[i]+=f[i-1];
  }
  return;
}
inline int min(const int &x,const int &y)
{
  return x<y?x:y;
}