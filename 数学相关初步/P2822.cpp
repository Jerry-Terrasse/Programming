#include<iostream>
#define MAXN 2020
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
int a[MAXN][MAXN],t=0,k=0,n=0,m=0,ans=0;
inline void init();
int main()
{
  int i=0,j=0;
  cin>>t>>k;
  init();
  for(;t--;)
  {
  	cin>>n>>m;
  	ans=0;
  	for(i=0;i<=n;++i)
  	{
  	  ans+=a[i][min(i,m)];
	}
	cout<<ans<<endl;
  }
  return 0;
}
inline void init()
{
  int i=0,j=0;
  for(i=00;i<MAXN;++i)
  {
  	for(j=1,a[i][0]=1%k;j<=i;++j)
  	{
  	  a[i][j]=(a[i-1][j-1]+a[i-1][j])%k;
	}
  }
  for(i=0;i<MAXN;++i)
  {
  	for(j=1,a[i][0]=!a[i][0];j<=i;++j)
  	{
  	  a[i][j]=!a[i][j];
  	  a[i][j]+=a[i][j-1];
	}
  }
  return;
}
