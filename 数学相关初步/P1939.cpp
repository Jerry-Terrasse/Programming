#include<iostream>
#include "memory.h"
#define ll long long
#define H 1000000007
using namespace std;
ll a[4][4],g[4][4],ans[4],f[4],n=0,m=0,t=0;
inline void mul();
inline void sqr();
int main()
{
  ll i=0,n=0;
  cin>>t;
  for(;t--;)
  {
  	cin>>n;
  	if(n<=3)
  	{
  	  cout<<1<<endl;
  	  continue;
	}
	n-=3;
	ans[1]=ans[2]=ans[3]=1;
	memset(a,0,sizeof(a));
	a[1][2]=a[2][3]=a[3][1]=a[3][3]=1;
	for(;n;n>>=1)
	{
	  if(n&1)
	  {
	  	mul();
	  }
	  sqr();
	}
	cout<<ans[3]<<endl;
  }
  return 0;
}
inline void sqr()
{
  int i=0,j=0,k=0;
  memset(g,0,sizeof(g));
  for(i=1;i<=3;++i)
  {
  	for(j=1;j<=3;++j)
  	{
  	  for(k=1;k<=3;++k)
  	  {
  	    g[i][j]+=a[i][k]*a[k][j];
  	    g[i][j]%=H;
	  }
	}
  }
  memcpy(a,g,sizeof(g));
  return;
}
inline void mul()
{
  ll i=0,j=0;
  memset(f,0,sizeof(f));
  for(i=1;i<=3;++i)
  {
  	for(j=1;j<=3;++j)
  	{
  	  f[i]+=a[i][j]*ans[j];
  	  f[i]%=H;
	}
  }
  memcpy(ans,f,sizeof(f));
  return;
}
