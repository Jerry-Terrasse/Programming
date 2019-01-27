#include<iostream>
#define MAXN 100010
#define MAX 65
using namespace std;
int f[MAXN][MAX],a[MAXN],n=0,ans=0;
int main()
{
  register int i=0,j=0,k=0;
  cin>>n;
  for(i=1;i<=n;++i)
  {
  	cin>>a[i];
  }
  for(i=1;i<=n;++i)
  {
  	for(j=0;j<MAX;++j)
  	{
  	  if(a[i]>>j&1)
  	  {
  	  	for(k=0;k<MAX;++k)
  	  	{
  	  	  if(a[i]>>k&1)
  	  	  {
  	  	  	f[i][j]=max(f[i][j],f[i-1][k]);
  	  	  }
  	  	}
  	  	++f[i][j];
  	  }
  	  else
  	  {
  	  	f[i][j]=f[i-1][j];
  	  }
  	}
  }
  for(i=0;i<MAX;++i)
  {
  	ans=max(ans,f[n][i]);
  }
  cout<<ans<<endl;
  return 0;
}
