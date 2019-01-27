#include<iostream>
#define MAXN 10010
using namespace std;
int a[MAXN],n=0,ans=0;
int gcd(const int&,const int&);
int main()
{
  int i=0,j=0,k=0,l=0;
  for(;cin>>n;)
  {
  	for(i=1,ans=0;i<=n;i++)
  	{
  	  cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
	  for(j=i+1;j<=n;j++)
	  {
	  	for(k=j+1;k<=n;k++)
	  	{
	  	  for(l=k+1;l<=n;l++)
	  	  {
	  	    if(gcd(a[i],gcd(a[j],gcd(a[k],a[l])))==1)
	  	    {
	  	      ans++;
			}
		  }
		}
	  }
	}
	cout<<ans<<endl;
  }
  return 0;
}
int gcd(const int &a,const int &b)
{
  if(a<b)
  {
  	return a?gcd(a,b%a):b;
  }
  return b?gcd(b,a%b):a;
}
