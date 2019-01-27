#include<iostream>
#include "memory.h"
#define ll long long
#define MAXN 550
#define min(x,y) ((x)<=(y)?(x):(y))
#define abs(x) ((x)<0?(-(x)):(x))
using namespace std;
ll f[MAXN][MAXN],a[MAXN],n=0;
int main()
{
  int i=1,j=0,k=0;
  memset(f,0x3f,sizeof(f));
  for(cin>>n;i<=n;++i)
  {
  	cin>>a[i];
  }
  for(i=1;i<=n;++i)
  {
  	f[i][i]=0;
  }
  for(i=1;i<n;++i)
  {
  	for(j=1;i+j<=n;++j)
  	{
  	  for(k=j;k<i+j;++k)
  	  {
  	    f[j][j+i]=min(f[j][j+i],f[j][k]+f[k+1][j+i]+abs(a[k]-a[j+i]));
	  }
	}
  }
  cout<<f[1][n]<<endl;
  return 0;
}
