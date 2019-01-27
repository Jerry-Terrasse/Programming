#include<iostream>
#include "memory.h"
#define ll long long
#define MAXN 110
using namespace std;
ll f[MAXN<<1][MAXN<<1],g[MAXN<<1][MAXN<<1],a[MAXN<<1],ans[2]={0x3f3f3f3f3f3f3f3f,(ll)0xc0c0c0c0c0c0c0c0},n=0;
int main()
{
  ll l=1,len=2,r=0,k=0;
  memset(f,0x3f,sizeof(f));
  memset(g,0xc0,sizeof(g));
  for(cin>>n;l<=n;l++)
  {
  	cin>>a[l];
  	g[l][l]=g[n+l][n+l]=f[l][l]=f[n+l][n+l]=0;
	a[n+l]=a[l];
  }
  for(l=2;l<=(n<<1);l++)
  {
  	a[l]+=a[l-1];
  }
  for(;len<=n;len++)
  {
  	for(l=1;;l++)
  	{
  	  r=l+len-1;
  	  if(r>(n<<1))
  	  {
  	    break;
	  }
  	  for(k=l;k<r;k++)
  	  {
  	    f[l][r]=min(f[l][k]+f[k+1][r],f[l][r]);
  	    g[l][r]=max(g[l][k]+g[k+1][r],g[l][r]);
	  }
	  f[l][r]+=a[r]-a[l-1];
	  g[l][r]+=a[r]-a[l-1];
	}
  }
  /*for(l=1;l<=n+1;l++)
  {
  	cout<<l<<","<<l+n-1<<":"<<f[l][l+n-1]<<endl;
  }*/
  for(l=1;l<=n;l++)
  {
  	ans[0]=min(ans[0],f[l][l+n-1]);
  	ans[1]=max(ans[1],g[l][l+n-1]);
  }
  for(l=0;l<=1;l++)
  {
  	cout<<ans[l]<<endl;
  }
  return 0;
}
