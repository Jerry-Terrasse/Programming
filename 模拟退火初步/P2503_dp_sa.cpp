#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include "memory.h"
#define ld long double
#define MAXN 32
#define INF 0x3f3f3f3f
#define rr(x) (rand()%(x))
#define sqr(x) ((x)*(x))
#define MINT 1e-6
#define dt 0.999
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
int f[MAXN][MAXN],a[MAXN],sum[MAXN],n=0,m=0,pw=0,npw=0;
ld av=0,t=0,ans=INF;
inline void sa();
inline int& dp();
inline int min(const int&,const int&);
int main()
{
  int i=1;
  srand(time(NULL));
  for(cin>>n>>m;i<=n;++i)
  {
  	cin>>a[i];
  	sum[n]+=a[i];
  }
  av=(ld)sum[n]/m;
  for(;(ld)clock()/CLOCKS_PER_SEC<0.877;sa());
  //for(i=100;i--;sa());
  ans+=sqr(av)*m;
  ans-=2*av*sum[n];
  ans/=m;
  //ans+=0.001;
  ans=sqrt(max(ans,0));
  cout<<fixed<<setprecision(2)<<ans<<endl;
  return 0;
}
inline void sa()
{
  int i=0,j=0;
  //cout<<1<<endl;
  random_shuffle(a+1,a+n+1);
  pw=dp();
  for(t=7777;t>MINT;t*=dt)
  {
  	i=rr(n)+1;
  	for(j=rr(n)+1;j==i;j=rr(n)+1);
  	a[i]^=a[j]^=a[i]^=a[j];
  	npw=dp();
  	if(npw<pw)
  	{
  	  pw=npw;
	}
	else if(exp(-t)<(ld)rr(7777777)/7777777)
	{
	  pw=npw;
	}
	else
	{
	  a[i]^=a[j]^=a[i]^=a[j];
	}
  }
  if(ans>pw)
  {
  	ans=pw;
  }
  return;
}
inline int& dp()
{
  int i=1,j=0,k=0;
  for(memset(f,0x3f,sizeof(f)),memset(sum,0,sizeof(sum));i<=n;++i)
  {
  	sum[i]=sum[i-1]+a[i];
  }
  for(i=1;i<=n;++i)
  {
  	f[i][1]=sqr(sum[i]);
  }
  for(i=2;i<=m;++i)
  {
  	for(j=i;j<=n;++j)
  	{
  	  for(k=i-1;k<j;++k)
  	  {
  	    f[j][i]=min(f[j][i],f[k][i-1]+sqr(sum[j]-sum[k]));
	  }
	}
  }
  return f[n][m];
}
inline int min(const int &a,const int &b)
{
  return a<b?a:b;
}
