#include<iostream>
#define MAXN 2000020
using namespace std;
int a[MAXN],f[MAXN],n=0,m=0,ans=0x80000000;
int main()
{
  int i=1;
  for(cin>>n;i<=n;i++)
  {
  	cin>>a[i];
  	if(f[i-1]>0)
  	{
  	  f[i]=f[i-1]+a[i];
	}
	else
	{
	  f[i]=a[i];
	}
	ans=max(ans,f[i]);
  }
  cout<<ans<<endl;
  return 0;
}
