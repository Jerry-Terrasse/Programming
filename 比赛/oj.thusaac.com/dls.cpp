#include<iostream>
#include<cmath>
#define int long long
#define H 998244353
#define MAXN 70000070
using namespace std;
signed zs[MAXN],prm[MAXN];
int pc=0,t=0,a=0,b=0,f=0,g=0;
inline void prime();
inline int ksm(int,int);
signed main()
{
  register int i=0;
  prime();
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>t;
  /*for(i=1;;++i)
  {
  	cout<<zs[i]<<' ';
	}*/
  for(;t--;)
  {
    cin>>a>>b;
    f=zs[b]+1-a;
    g=floor(sqrt(b))-ceil(sqrt(a))+1;
    f=max(f,g);
    cout<<ksm(2,f)<<endl;
  }
  return 0;
}
inline int ksm(int a,int b)
{
  register int ret=1;
  for(;b;b>>=1)
  {
    if(b&1)
    {
      (ret*=a)%=H;
    }
    (a*=a)%=H;
  }
  return ret;
}
inline void prime()
{
  register int i=0,j=0;
  for(i=2,zs[1]=1;i<MAXN;++i)
  {
    if(!zs[i])prm[++pc]=i;
    for(j=1;j<=pc&&i*prm[j]<MAXN;++j)
    {
      zs[i*prm[j]]=1;
      if(!(i%prm[j]))
      {
        break;
      }
    }
  }
  for(i=2;i<MAXN;++i)
  {
    zs[i]+=zs[i-1];
  }
  return;
}
