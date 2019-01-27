#include<iostream>
#include "memory.h"
#define ll long long
#define MAXN 8
#define H 1000000007
using namespace std;
struct mat
{
  ll a[MAXN][MAXN],n,m;
  inline mat();
  inline void init();
  inline void operator*=(const mat&);
  inline mat operator*(const mat&);
}ans,a,e;
ll n=0;
inline void init();
inline mat pow(mat,ll);
int main()
{
  init();
  cin>>n;
  if(n<=2)
  {
  	cout<<1<<endl;
  	return 0;
  }
  ans=pow(a,n-2)*ans;
  cout<<ans.a[1][1]<<endl;
  return 0;
}
inline mat pow(mat a,ll b)
{
  mat ans=e;
  for(;b;b>>=1)
  {
  	if(b&1)
  	{
  	  ans=a*ans;
	}
	a=a*a;
  }
  return ans;
}
inline mat mat::operator*(const mat &x)
{
  mat ans;
  register int i=0,j=0,k=0;
  ans.n=n;
  ans.m=x.m;
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=m;++j)
  	{
  	  for(k=1;k<=m;++k)
  	  {
  	    ans.a[i][j]+=a[i][k]*x.a[k][j];
	    ans.a[i][j]%=H;
	  }
	}
  }
  return ans;
}
inline void init()
{
  a.n=a.m=2;
  a.a[1][1]=a.a[1][2]=a.a[2][1]=1;
  ans.n=2;ans.m=1;
  ans.a[1][1]=ans.a[2][1]=1;
  e.n=e.m=2;
  e.a[1][1]=e.a[2][2]=1;
  return;
}
inline void mat::init()
{
  n=m=0;
  memset(a,0,sizeof(a));
  return;
}
inline mat::mat()
{
  init();
  return;
}
