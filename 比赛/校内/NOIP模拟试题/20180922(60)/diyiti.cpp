#include<iostream>
#include "memory.h"
#define ll long long
#define MAXN 10010
using namespace std;
int a[MAXN],n=0;
ll f[5][MAXN];
int gcd(const int&,const int&);
inline void read(int&);
int main()
{
  int i=0,j=0,k=0,maxa=0;
  freopen("diyiti.in","r",stdin);freopen("diyiti.out","w",stdout);
  for(;cin>>n;)
  {
  	memset(f,0,sizeof(f));
	for(i=1,maxa=0;i<=n;i++)
  	{
  	  read(a[i]);
  	  if(a[i]>maxa)
  	  {
  	    maxa=a[i];
	  }
	}
	for(i=1;i<=n;i++)
	{
	  for(j=4;j>=2;j--)
	  {
	  	for(k=1;k<=maxa;k++)
	  	{
	  	  if(f[j-1][k])
	  	  {
	  	    if(a[i]<k)
	  	    {
	  	      f[j][gcd(k,a[i])]+=f[j-1][k];
			}
			else
			{
			  f[j][gcd(a[i],k)]+=f[j-1][k];
			}
		  }
		}
	  }
	  f[1][a[i]]++;
	}
	cout<<f[4][1]<<endl;
  }
  return 0;
}
inline void read(int &x)
{
  char c=getchar();
  for(x=0;c<'0'||c>'9';c=getchar());
  for(;c>='0'&&c<='9';c=getchar())
  {
  	x=(x<<3)+(x<<1)+c-'0';
  }
  return;
}
int gcd(const int &a,const int &b)
{
  return b?gcd(b,a%b):a;
}
