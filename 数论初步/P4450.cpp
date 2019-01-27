//P4450 双亲数
#include<iostream>
#include "memory.h"
#define int long long
#define MAXN 1000010
using namespace std;
int mu[MAXN],zs[MAXN],zc=0,a=0,b=0,k=0,ans=0,t=0;
inline void mb();
inline int min(const int&,const int&);
signed main()
{
  register int i=0,j=0;
  mb();
    ans=0;
    cin>>a>>b>>k;
    a/=k;b/=k;
    if(a>b)
    {
      a^=b^=a^=b;
    }
    for(i=1;i<=a;i=j+1)
    {
      j=min(a/(a/i),b/(b/i));
      //cout<<j<<':';
      ans+=(mu[j]-mu[i-1])*(a/i)*(b/i);
    }
    cout<<ans<<endl;
  return 0;
}
inline int min(const int &x,const int &y)
{
  return x<y?x:y;
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
        mu[i*zs[j]]=0;
        break;
      }
    }
  }
  for(i=2;i<MAXN;++i)
  {
    mu[i]+=mu[i-1];
  }
  return;
}