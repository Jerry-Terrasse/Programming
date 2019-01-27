#include<iostream>
#include<cmath>
#include "memory.h"
#define MAXP 10000010
#define ll long long
using namespace std;
int f[MAXP],g[MAXP],t=0,p=0,q=0,ans=0;
int main()
{
  ll i=0,j=0,x=0,y=0,z=0;
  freopen("prime.in","r",stdin);freopen("prime.out","w",stdout);
  for(cin>>t;t--;)
  {
  	memset(f,0,sizeof(f));
  	memset(g,0,sizeof(g));
  	ans=0;
	cin>>p>>q;
	x=p*q;
	y=ceil(sqrt(x>>1));
	z=ceil(sqrt(x));
  	if(p<q)
  	{
  	  swap(p,q);
	}
	for(i=0;i<=p;i++)
	{
	  f[i]=i*i%p;
	  g[i]=i*i%q;
	}
	for(i=0;i<=y;i++)
	{
	  for(j=i+1;j<=z;j++)
	  {
	  	if(!((f[i%p]+f[j%p])%p) && !((g[i%q]+g[j%q])%q) && i*i+j*j==x)
	  	{
	  	  if(i==0)
	  	  {
	  	    ans+=2;
		  }
		  else
		  {
		  	ans+=4;
		  }
		}
	  }
	}
	cout<<(ans<<1)<<endl;
  }
  fclose(stdin);fclose(stdout);
  return 0;
}
