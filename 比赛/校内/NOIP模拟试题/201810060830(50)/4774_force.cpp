#include<iostream>
#include "memory.h"
#define MAXN 1000010
using namespace std;
int f[MAXN],s[MAXN],n=0,m=0,ans=0;
int main()
{
  int i=0,j=0;
  char cmd[16]="",c='\0';
  //freopen("4774.in","r",stdin);
  cin>>n>>m;
  for(i=1;i<=n;++i)
  {
  	for(c=getchar();c!='4'&&c!='7';c=getchar());
  	s[i]=(c=='7');
  }
  for(;m--;)
  {
  	cin>>cmd;
  	if(cmd[0]=='c')
  	{
  	  memset(f,0,sizeof(f));
	  ans=0;
	  for(i=1;i<=n;++i)
  	  {
		for(j=1;j<i;++j)
  	    {
  	      if(s[j]<=s[i]&&f[j]>f[i])
  	      {
  	        f[i]=f[j];
		  }
		}
		++f[i];
		ans=max(ans,f[i]);
	  }
	  cout<<ans<<endl;
	}
	else
	{
	  cin>>i>>j;
	  for(;i<=j;++i)
	  {
	  	s[i]^=1;
	  }
	}
  }
  return 0;
}
