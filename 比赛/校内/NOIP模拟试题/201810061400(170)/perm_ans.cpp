#include<iostream>
#include "memory.h"
#define MAXN 100010
using namespace std;
int a[MAXN],b[MAXN],use[MAXN],ans[MAXN],sss[MAXN],n=0;
inline void kt(int*);
inline void arckt();
int main()
{
  int i=1;
  for(cin>>n;i<=n;++i)
  {
  	cin>>a[i];
  }
  for(i=1;i<=n;++i)
  {
  	cin>>b[i];
  }
  kt(a);
  kt(b);
  for(i=n-1;i>=1;--i)
  {
  	ans[i-1]+=ans[i]/(n+1-i);
  	ans[i]%=(n+1-i);
  }
  arckt();
  for(i=1;i<=n;++i)
  {
  	cout<<sss[i]<<' ';
  }
  cout<<endl;
  return 0;
}
inline void arckt()
{
  int i=1,j=0,k=0;
  memset(use,0,sizeof(use));
  for(;i<=n;++i)
  {
  	for(j=ans[i],k=0;j||use[k];++k)
  	{
  	  j-=(!use[k]);
	}
	sss[i]=k;
	use[k]=1;
  }
  return;
}
inline void kt(int *a)
{
  int i=1,j=0;
  memset(use,0,sizeof(use));
  for(;i<=n;++i)
  {
  	for(j=0;j<a[i];++j)
  	{
  	  ans[i]+=(!use[j]);
	}
	use[a[i]]=1;
  }
  return;
}
