#include<iostream>
#include "memory.h"
#include<cmath>
#define ll long long
#define MAXN 16
#define ld long double
using namespace std;
ll f[MAXN],n=0,k=0,ans=0;
ll dfs(int);
int main()
{
  ll i=0,dx=0,dy=0;
  //cin>>n>>k;
  for(dx=1;dx<=10;dx++)
  {
  	cout<<'{';
	for(dy=1;dy<=10;dy++)
  	{
  	  memset(f,0,sizeof(f));
  	  n=dx;k=dy;ans=0;
	  for(i=1;i<=n;i++)
      {
  	    f[i]=round((ld)i*k*0.9);
      }
      ans=dfs(n);
      cout<<ans<<',';
	}
	cout<<"},";
  }
  return 0;
}
ll dfs(int x)
{
  if(x<=0)
  {
  	return 0;
  }
  ll i=0,ans=0x7fffffffffffffff;
  for(i=1;i<=x;i++)
  {
  	ans=min(ans,f[i]+dfs(x-i));
  }
  return ans;
}
