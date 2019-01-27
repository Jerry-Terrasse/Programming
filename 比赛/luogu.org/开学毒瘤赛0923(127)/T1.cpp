#include<iostream>
#define MAXN 100010
#define ll long long
using namespace std;
ll a[MAXN],n=0,m=0,ans=0,maxa=0,l=0,r=0;
int main()
{
  int i=1,j=0,s=0,k=0;
  for(cin>>n>>m;i<=n;i++)
  {
  	cin>>a[i];
  	if(a[i]>l)
  	{
  	  l=a[i];
	}
	r+=a[i];
  }
  r++;
  for(;;)
  {
  	ans=(l+r)>>1;
	for(i=1,k=m;i<=n&&k;)
  	{
  	  s=a[i];
  	  for(i++;i<=n;i++)
  	  {
  	    if(s+a[i]<=ans)
  	    {
  	      s+=a[i];
		}
		else
		{
		  break;
		}
	  }
	  k--;
	}
	if(k==0&&i>n)
	{
	  cout<<ans<<endl;
	  return 0;
	}
	if(i<=n)
	{
	  l=ans;
	}
	if(k>0)
	{
	  r=ans+1;
	}
  }
  return 0;
}
