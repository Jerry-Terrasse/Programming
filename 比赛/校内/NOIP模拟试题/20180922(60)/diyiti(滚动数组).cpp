#include<iostream>
#include "memory.h"
#define ll long long
#define MAXN 10010
using namespace std;
int a[MAXN],n=0;
ll f[2][5][MAXN];
int gcd(const int&,const int&);
int main()
{
  int i=0,j=0,k=0,maxa=0;
  for(;cin>>n;)
  {
  	memset(f,0,sizeof(f));
	for(i=1,maxa=0;i<=n;i++)
  	{
  	  cin>>a[i];
  	  if(a[i]>maxa)
  	  {
  	    maxa=a[i];
	  }
	}
	for(i=1;i<=n;i++)
	{
	  f[i&1][1][a[i]]++;
	  for(j=4;j>=2;j--)
	  {
	  	for(k=1;k<=maxa;k++)
	  	{
	  	  if(f[i&1^1][j-1][k])
	  	  {
	  	    if(a[i]<k)
	  	    {
	  	      f[i&1][j][gcd(k,a[i])]+=f[i&1^1][j-1][k];
			}
			else
			{
			  f[i&1][j][gcd(a[i],k)]+=f[i&1^1][j-1][k];
			}
		  }
		}
	  }
	}
	cout<<f[n&1][4][1]<<endl;
  }
  return 0;
}
int gcd(const int &a,const int &b)
{
  return b?gcd(b,a%b):a;
}
