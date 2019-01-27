#include<iostream>
#define MAXN 32
using namespace std;
int a[MAXN],n=0,ans=0,now=0;
inline void judge();
int main()
{
  int i=0;
  cin>>n;
  for(i=0;i<n;++i)
  {
  	cin>>a[i];
  }
  for(now=1;now<(1<<n);++now)
  {
  	judge();
  }
  cout<<ans<<endl;
  return 0;
}
inline void judge()
{
  int i=0,pre=0,d=0;
  for(i=0;;++i)
  {
  	if(1<<i&now)
  	{
  	  pre=a[i];
  	  break;
	}
  }
  for(++i;i<n;++i)
  {
  	if(1<<i&now)
  	{
  	  d=a[i]-pre;
  	  pre=a[i];
  	  break;
	}
  }
  if(i==n)
  {
  	++ans;
  	return;
  }
  for(++i;i<n;++i)
  {
  	if(1<<i&now)
  	{
  	  if(a[i]-pre==d)
  	  {
  	    pre=a[i];
	  }
	  else
	  {
	  	return;
	  }
	}
  }
  ++ans;
  return;
}
