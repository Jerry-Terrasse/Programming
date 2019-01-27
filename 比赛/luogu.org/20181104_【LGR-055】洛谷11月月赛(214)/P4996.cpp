#include<iostream>
#define ll long long
#define MAXN 32
#define H 998244353
using namespace std;
ll C[MAXN][MAXN],f[MAXN],n=0,m=0;
ll ans=0;
inline void init();
int main()
{
  register int i=0,j=0,a=0,x=0,y=0;
  char c='\0';
  cin>>n>>m;
  init();
  for(i=1;i<=m;++i)
  {
  	for(j=1,x=0,y=0;j<=n;++j)
  	{
  	  cin>>c;
  	  if(c=='0')
  	  {
  	    ++x;
	  }
	  else
	  {
	  	++y;
	  }
	}
	cin>>a;
	ans+=a*f[y]%H*f[x];
	ans%=H;
  }
  cout<<ans<<endl;
  return 0;
}
inline void init()
{
  register int i=0,j=0;
  for(i=0;i<=n;++i)
  {
  	C[i][0]=1;
  }
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=i;++j)
  	{
  	  C[i][j]=(C[i-1][j]+C[i-1][j-1])%H;
	}
  }
  for(i=1,f[0]=1;i<=n;++i)
  {
  	for(j=0;j<i;++j)
  	{
  	  f[i]+=C[i][j]*f[j];
  	  f[i]%=H;
	}
  }
  return;
}
