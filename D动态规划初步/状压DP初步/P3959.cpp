#include<iostream>
#include "memory.h"
#define ll long long
#define MAXM 1010
#define MAXN 16
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
ll f[MAXN][1<<MAXN<<1],e[MAXN][MAXN],ans=INF,n=0,m=0;
int main()
{
  ll i=0,s=0,t=0,j=0,k=0,l=0;
  memset(e,0x3f,sizeof(e));
  for(cin>>n>>m;m--;)
  {
  	cin>>s>>t>>i;
  	e[s][t]=e[t][s]=i;
  }
  memset(f,0x3f,sizeof(f));
  for(i=0;i<n;i++)
  {
  	f[1][1<<i]=0;
  }
  for(i=2;i<=n;i++)
  {
  	for(s=0;s<(1<<n);s++)
  	{
  	  if(f[i-1][s]==INF)
  	  {
  	    continue;
	  }
	  for(t=0;t<(1<<n);t++)
	  {
	  	if(s&t)
	  	{
	  	  continue;
		}
		f[i][t|s]=f[i-1][s];
		for(j=0;j<n;j++)
		{
		  if(!(t&(1<<j)))
		  {
		  	continue;
		  }
		  l=INF;
		  for(k=1;k<=n;k++)
		  {
		  	if((s&(1<<k>>1))&&(e[k][j]!=INF))
		  	{
		  	  l=min(l,e[k][j]*i);
			}
		  }
		  if(l==INF)
		  {
		  	f[i][t|s]=INF;
		  }
		  else
		  {
		  	f[i][t|s]+=l; 
		  }
		}
	  }
	}
  }
  for(i=1;i<=n;i++)
  {
  	ans=min(ans,f[i][(1<<n)-1]);
  }
  cout<<ans<<endl;
  return 0;
}
