#include<iostream>
#define MAXN 1010
using namespace std;
int a[10],b[10],c[10],d[10],n=0,ans=0;
char ch='\0';
int main()
{
  int i=0,j=0,k=0;
  cin>>n;
  for(i=1;i<=n;++i)
  {
  	cin>>ch;
  	++a[ch^48];
  	++c[ch^48];
  }
  for(i=1;i<=n;++i)
  {
  	cin>>ch;
  	++b[ch^48];
  	++d[ch^48];
  }
  for(i=0,j=0;i<=9;++i)
  {
  	for(;a[i]&&j<=9;)
  	{
  	  if(j>i)
  	  {
  	    k=min(a[i],b[j]);
  	    a[i]-=k;
  	    b[j]-=k;
  	    ans+=k;
  	    if(!b[j])
  	    {
  	      ++j;
		}
	  }
	  else
	  {
	  	++j;
	  }
	}
  }
  cout<<ans<<endl;
  ans=0;
  for(i=0,j=0;i<=9;++i)
  {
  	for(;c[i]&&j<=9;)
  	{
  	  if(j>=i)
  	  {
  	    k=min(c[i],d[j]);
  	    c[i]-=k;
  	    d[j]-=k;
  	    ans+=k;
  	    if(!d[j])
  	    {
  	      ++j;
		}
	  }
	  else
	  {
	  	++j;
	  }
	}
  }
  cout<<n-ans<<endl;
  return 0;
}
