#include<iostream>
#include "memory.h"
#define MAXB 100010
using namespace std;
int us[MAXB],zs[MAXB],cnt[MAXB],a=0,b=0,p=0,ans=0;
int fa(int);
int main()
{
  int i=0,j=0,k=0;
  ios::sync_with_stdio(0);
  cin>>a>>b>>p;
  memset(zs,-1,sizeof(zs));//0xFFFFFFFFFFFFFFFFFFFFFF...
  for(i=2;i<=b;i++)
  {
  	if(zs[i])
  	{
  	  for(j=i,k=b/i;j<=k;j++)
  	  {
  	    zs[i*j]=0;
	  }
	}
  }
  for(i=a;i<=b;i++)
  {
  	us[i]=i;
  }
  for(i=p;i<=b;i++)
  {
  	if(zs[i])
  	{
  	  for(j=1;i*j<a;j++);
  	  k=i*j;
  	  for(j++;i*j<=b;j++)
  	  {
  	    if(fa(k)!=fa(i*j))
  	    {
  	      //cout<<"connect:"<<k<<'&'<<i*j<<endl;
		  us[us[k]]=us[i*j];
		}
	  }
	}
  }
  for(i=a;i<=b;i++)
  {
  	if(!cnt[k=fa(i)])
  	{
  	  ans++;
  	  cnt[k]=1;
	}
  }
  cout<<ans<<endl;
  return 0;
}
int fa(int x)
{
  return us[x]==x?x:us[x]=fa(us[x]);
}
