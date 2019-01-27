#include<cstdio>
#define MAXP 1010
using namespace std;
int l,r,f[MAXP],p=0,q=0,ans=0;
int main()
{
  int i=0,j=0,a=0,b=0;
  cin>>p>>q;
  l=1;r=p;
  for(i=1;i<=q;i++)
  {
  	cin>>j;
  	f[j]=1;
  }
  for(i=1;i<=q;i++)
  {
  	for(a=l;!f[a];a++);
  	a-=l;
  	for(b=r;!f[b];b--);
  	b=r-b;
  	if(a>b)
  	{
  	  ans+=
	}
	else
	{
	  
	}
  }
  return 0;
}
