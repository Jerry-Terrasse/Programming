#include<iostream>
#include "memory.h"
#define MAXN 16
#define MAXX 1010
using namespace std;
int f[MAXX],a[MAXN],n=0,x=0,sum=0;
int main()
{
  int i=0,j=0;
  memset(f,0x3f,sizeof(f));
  cin>>x>>n;
  for(i=1;i<=n;++i)
  {
  	cin>>a[i];
  }
  for(i=1,f[0]=0;i<=x;++i)
  {
  	for(j=1;j<=n;++j)
  	{
  	  if(a[j]<=i)
  	  {
  	    f[i]=min(f[i],f[i-a[j]]+1);
	  }
	}
  }
  cout<<f[x]<<endl;
  return 0;
}
