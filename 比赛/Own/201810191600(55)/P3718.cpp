#include<cstdio>
#define MAXN 100010
using namespace std;
int n=0,k=0,ans=0;
char a[MAXN];
int main()
{
  int i=0,pre=0,o=0,l=0,r=0,m=0;
  scanf("%d%d%s",&n,&k,a);
  for(i=0;a[i];++i)
  {
  	a[i]=a[i]=='N'?1:0;
  }
  for(l=1,r=n;l+1<r;)
  {
  	ans=l+r+1>>1;m=k;o=a[0];pre=1;
  	for(i=1;i<n&&m>=0;++i)
  	{
  	  if(a[i]==o)
  	  {
  	    if(pre<ans)
  	    {
  	      ++pre;
		}
		else
		{
		  --m;
		  pre=1;
		  o^=1;
		}
	  }
	  else
	  {
	  	pre=1;
	  	o^=1;
	  }
	}
	if(m<0)
	{
	  l=ans;
	}
	else
	{
	  r=ans;
	}
  }
  printf("%d\n",r);
  return 0;
}
