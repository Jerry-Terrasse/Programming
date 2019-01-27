#include<iostream>
#define MAXN 1010
using namespace std;
int a[MAXN][MAXN],f[MAXN][MAXN],n=0,ans=-1;
int main()
{
  int i=1,j=0;
  for(cin>>n;i<=n;i++)
  {
  	for(j=1;j<=i;j++)
  	{
  	  cin>>a[i][j];
	}
  }
  f[1][1]=a[1][1];
  for(i=2;i<=n;i++)
  {
	for(j=1;j<=i;j++)
  	{
  	  f[i][j]=max(f[i-1][j-1],f[i-1][j]);
  	  f[i][j]+=a[i][j];
	}
  }
  for(i=1;i<=n;i++)
  {
  	ans=max(ans,f[n][i]);
  }
  cout<<ans<<endl;
  return 0;
}
