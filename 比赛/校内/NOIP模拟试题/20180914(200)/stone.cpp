#include<iostream>
#include "memory.h"
#define MAXN 1024
using namespace std;
int f[MAXN],r[MAXN],h[MAXN],del[MAXN],n=0,cnt=0,ans=0;
inline int dp();
int main()
{
  int i=1,m=0;
  //freopen("stone.in","r",stdin);freopen("stone.out","w",stdout);
  for(cin>>n;i<=n;i++)
  {
  	cin>>h[i];
  }
  m=dp();
  ans+=f[m];
  for(i=m;i;i=r[i])
  {
  	del[i]=1;
  }
  for(i=1;i<=n;i++)
  {
  	if(!del[i])
  	{
  	  h[++cnt]=h[i];
    }
  }
  n=cnt;
  m=dp();
  ans+=f[m];
  cout<<ans<<endl;
  //fclose(stdin);fclose(stdout);
  return 0;
}
inline int dp()
{
  int i=0,j=0,m=0;
  memset(f,0,sizeof(f));
  memset(r,0,sizeof(r));
  for(i=1;i<=n;i++)
  {
  	f[i]=1;
  	for(j=1;j<i;j++)
  	{
  	  if(h[j]<=h[i]&&f[j]+1>f[i])
  	  {
  	    f[i]=f[j]+1;
  	    r[i]=j;
	  }
	}
	if(f[i]>f[m])
	{
	  m=i;
	}
  }
  return m;
}
