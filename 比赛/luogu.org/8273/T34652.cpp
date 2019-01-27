#include<iostream>
#include<cmath>
#include "memory.h"
#define MAXN 23333
#define MAXK 2333333
using namespace std;
int f[MAXK],b[MAXN],c[MAXN],n=0,cnt=0,k=0;
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
  	if(c[i]>1)
  	{
	  l=log2(c[i])-1;
  	  for(j=1;j<=l;j++)
  	  {
  	    cnt++;
		b[n+cnt]=b[i]<<j;
		c[n+cnt]=1<<j;
      }
      cnt++;
      c[n+cnt]=1+c[i]-(1<<(l+1));
      b[n+cnt]=b[i]*(c[n+cnt]);
	  c[i]=1;
	}
  }
  n+=cnt;
  cin>>k;
  f[0]=0;
  for(i=1;i<=n;i++)
  {
  	  for(l=k;l>=b[i];l--)
  	  {
  	    f[l]=min(f[l],f[l-b[i]]+c[i]);
	  }
  }
  cout<<f[k]<<endl;
  return 0;
}
