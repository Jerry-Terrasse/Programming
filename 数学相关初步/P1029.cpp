#include<iostream>
#include "memory.h"
#define ll long long
#define MAXZ 78498
using namespace std;
ll zs[MAXZ],cnt=0,ccnt=0,x=0,y=0,ans=1;
inline void prime(int);
int main()
{
  ll i=0,k=0;
  cin>>x>>y;
  if(y%x)
  {
  	cout<<0<<endl;
  	return 0;
  }
  prime(y);
  for(i=0,k=y/x;k&&i<cnt;i++)
  {
  	for(ccnt=0;!(k%zs[i]);k/=zs[i],ccnt++);
  	if(ccnt)
  	{
  	  ans<<=1;
	}
  }
  cout<<ans<<endl;
  return 0;
}
inline void prime(int n)
{
  int i=0,j=0;
  bool p[n+1];
  memset(p,-1,sizeof(p));
  for(i=2;i<=n;i++)
  {
  	if(p[i])
  	{
  	  zs[cnt++]=i;
  	  for(j=1;i*j<=n;j++)
  	  {
  	    p[i*j]=0;
	  }
	}
  }
  return;
}
