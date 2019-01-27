#include<iostream>
#include<algorithm>
#define MAXN 200020
using namespace std;
int a[MAXN],d[MAXN],e[MAXN],f[MAXN],g[MAXN],p[MAXN],n=0,ans=0;
int main()
{
  int i=1,p=0,l=1,m=1;
  for(cin>>n;i<=n;i++)
  {
  	cin>>a[i];
  }
  if(n==0)
  {
  	cout<<0<<endl;
  	return 0;
  }
  f[1]=g[n]=1;
  a[0]=a[n+1]=0x7fffffff;
  d[1]=a[1];
  e[1]=a[n];
  for(i=2;i<=n;i++)
  {
  	if(a[i]>=d[l])
  	{
  	  d[++l]=a[i];
	  f[i]=l;
	}
	else
	{
	  p=upper_bound(d+1,d+l+1,a[i])-d;
	  d[p]=a[i];
	  f[i]=p;
	}
  }
  for(i=n-1;i>=1;i--)
  {
  	if(a[i]>=e[m])
  	{
  	  e[++m]=a[i];
 	  g[i]=m;
	}
	else
	{
	  p=upper_bound(e+1,e+m+1,a[i])-e;
	  e[p]=a[i];
	  g[i]=p;
	}
  }
  for(i=1;i<=n;i++)
  {
  	//cout<<f[i]<<' '<<g[i]<<endl;
	if(ans<f[i]+g[i])
  	{
  	  ans=f[i]+g[i];
	}
  }
  cout<<ans-1<<endl;
  return 0;
}
