#include<iostream>
#define MAXN 100010
using namespace std;
int n=0,m=0,o[MAXN],t[MAXN];
int main()
{
  int i=0,j=0,a=0,ans=0;
  string s="";
  ios::sync_with_stdio(0);
  cin>>n>>m;
  for(;i<n;i++)
  {
  	cin>>s>>t[i];
  	if(s[0]=='A')
  	{
  	  o[i]=0;
  	  continue;
	}
	if(s[0]=='O')
  	{
  	  o[i]=1;
  	  continue;
	}
	if(s[0]=='X')
  	{
  	  o[i]=2;
  	  continue;
	}
  }
  for(i=0;i<=m;i++)
  {
	a=i;
	for(j=0;j<n;j++)
  	{
  	  if(o[j]==0)
  	  {
  	    a&=t[j];
  	    continue;
	  }
	  if(o[j]==1)
  	  {
  	    a|=t[j];
  	    continue;
	  }
	  if(o[j]==2)
  	  {
  	    a^=t[j];
  	    continue;
	  }
	}
	ans=max(ans,a);
  }
  cout<<ans<<endl;
  return 0;
}
