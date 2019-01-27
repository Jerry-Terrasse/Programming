#include<iostream>
#define MAXN 64
using namespace std;
int a[MAXN],n=0,m=0,l=0,r=1000000000,ans=0;
inline bool ok();
int main()
{
  int i=1;
  for(cin>>n>>m;i<=n;++i)
  {
  	cin>>a[i];
  }
  for(;l+1<r;)
  {
  	ans=(l+r)>>1;
  	if(ok())
  	{
  	  l=ans;
	}
	else
	{
	  r=ans;
	}
  }
  cout<<l<<endl;
  return 0;
}
inline bool ok()
{
  int lim=min(m,ans),i=1;
  for(;i<=n;++i)
  {
  	lim-=max(0,ans-a[i]);
  	if(lim<0)
  	{
  	  return false;
	}
  }
  return true;
}
