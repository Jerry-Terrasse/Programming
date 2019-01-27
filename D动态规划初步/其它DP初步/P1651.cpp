#include<iostream>
#include "memory.h"
#define MAXN 55
#define MAXH 500050
using namespace std;
int f[MAXN][MAXH],a[MAXN],n=0,maxa=0;
int main()
{
  int i=0,j=0;
  memset(f,0x80,sizeof(f));
  cin>>n;
  for(i=1;i<=n;++i)
  {
  	cin>>a[i];
  	maxa+=a[i];
  }
  f[0][0]=0;
  for(i=1;i<=n;++i)
  {
	for(j=0;j<maxa;++j)
  	{
  	  f[i][j]=max(f[i][j],f[i-1][j]);
  	  f[i][j]=max(f[i][j],f[i-1][j+a[i]]);
  	  if(j>=a[i])
  	  {
  	    f[i][j]=max(f[i][j],f[i-1][j-a[i]]+a[i]);
	  }
	  else
	  {
	  	f[i][j]=max(f[i][j],f[i-1][a[i]-j]+j);
	  }
	}
  }
  if(f[n][0]>0)
  {
  	cout<<f[n][0]<<endl;
  }
  else
  {
  	cout<<-1<<endl;
  }
  return 0;
}
