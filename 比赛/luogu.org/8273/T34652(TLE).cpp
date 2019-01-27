#include<iostream>
#include "memory.h"
#define MAXN 233
#define MAXK 23333
using namespace std;
int f[MAXK],b[MAXN],c[MAXN],n=0,k=0;
int main()
{
  int i=1,j=0,l=0;
  memset(f,0x3f,sizeof(f));
  for(cin>>n;i<=n;i++)
  {
    cin>>b[i];
  }
  for(i=1;i<=n;i++)
  {
  	cin>>c[i];
  }
  cin>>k;
  f[0]=0;
  for(i=1;i<=n;i++)
  {
  	for(j=1;j<=c[i];j++)
  	{
  	  for(l=k;l>=b[i];l--)
  	  {
  	    f[l]=min(f[l],f[l-b[i]]+1);
	  }
	}
  }
  cout<<f[k]<<endl;
  return 0;
}
