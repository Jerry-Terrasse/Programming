#include<iostream>
#include "memory.h"
#define MAXN 3030
using namespace std;
int e[MAXN][MAXN],ans=0,n=0,t=0;
int main()
{
  int i=0,j=0,k=0,u=0,v=0;
  bool bo=false;
  //freopen("a.in","r",stdin);freopen("a.out","w",stdout);
  for(cin>>t;t;t--)
  {
  	memset(e,0,sizeof(e));
  	ans=0;
  	for(cin>>n>>i;i;i--)
  	{
  	  cin>>u>>v;
  	  e[u][v]=1;
	  }
	  for(i=1;i<=n;i++)
	  {
	    for(j=i+1;j<=n;j++)
	    {
	      if(e[i][j])
	      {
	        ans++;
		    }
		    else
		    {
	        bo=false;
		      for(k=i+1;k<j;k++)
	        {
	        	if(e[i][k] && e[k][j])
	        	{
	        	  bo=true;
	        	  e[i][j]=1;
			        break;
			      }
		      }
		      if(bo)
		      {
		        ans++;
		      }
		    }
	    }
	  }
	  ans*=2;
	  ans+=n;
	  cout<<ans<<endl;
  }
  //fclose(stdin);fclose(stdout);
  return 0;
}
