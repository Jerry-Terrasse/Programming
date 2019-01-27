#include<iostream>
#include "memory.h"
#define MAXN 40040
using namespace std;
int zs[MAXN],phi[MAXN],n=0,ans=0,zc=0;
inline void euler();
int main()
{
  register int i=0;
  cin>>n;
  if(n==1)
  {
    cout<<0<<endl;
    return 0;
  }
  euler();
  for(i=2;i<n;++i)
  {
    ans+=phi[i];
  }
  ans<<=1;
  cout<<ans+3<<endl;
  return 0;
}
inline void euler()
{
  register int i=0,j=0;
  memset(zs,-1,sizeof(zs));
  for(i=2;i<MAXN;++i)
  {
    if(zs[i])
    {
      zs[++zc]=i;
      phi[i]=i-1;
    }
    for(j=1;j<=zc&&i*zs[j]<MAXN;++j)
    {
      zs[i*zs[j]]=0;
      if(i%zs[j])
      {
        phi[i*zs[j]]=(zs[j]-1)*phi[i];
      }
      else
      {
        phi[i*zs[j]]=zs[j]*phi[i];
        break;
      }
    }
  }
  return;
}