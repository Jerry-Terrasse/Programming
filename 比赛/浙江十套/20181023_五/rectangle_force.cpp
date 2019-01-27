#include<iostream>
#define MAXN 220
using namespace std;
char a[MAXN][MAXN];
int n=0,m=0,ans=0;
int main()
{
  int i=0,j=0,k=0,l=0,r=0,s=0;
  bool bo=false;
  cin>>n>>m;
  for(i=0;i<n;++i)
  {
  	cin>>a[i];
  }
  for(i=0;i<n;++i)
  {
  	for(j=0;j<m;++j)
  	{
	  for(k=i;k<n;++k)
      {
      	for(l=j;l<m;++l)
      	{
          for(bo=true,r=i;bo&&r<=k;++r)
          {
          	for(s=j;bo&&s<=l;++s)
          	{
   		      if(a[r][s]=='*')
   		      {
  		      	bo=false;
  		      	break;
		      }
	        }
		  }
		  ans+=bo;
	    }
	  }
    }
  }
  cout<<ans<<endl;
  return 0;
}
