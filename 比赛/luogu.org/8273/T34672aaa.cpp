#include<iostream>
#include "memory.h"
#define MAXN 1000010
#define MAXX 1000010
using namespace std;
int ak[MAXX],a[MAXN],t=0,n=0,ans=0;
int sg(int);
int main()
{
  int i=0;
  ios::sync_with_stdio(0);
  memset(ak,-1,sizeof(ak));
  ak[0]=0;
  for(cin>>t;t;t--)
  {
  	ans=0;
  	cin>>n;
  	for(i=0;i<n;i++)
  	{
  	  cin>>a[i];
  	  ans^=sg(a[i]);
	}
	if(ans)
	{
	  cout<<"First player wins."<<endl;
	}
	else
	{
	  cout<<"Second player wins."<<endl;
	}
  }
  return 0;
}
int sg(int x)
{
  if(ak[x]!=-1)
  {
  	return ak[x];
  }
  int i=0,j=0,k=0;
  bool mex[MAXX];
  memset(mex,0,sizeof(mex));
  for(i=0;i<=x-1;i++)
  {
  	int kkk=0;
	kkk=sg(i);
	mex[kkk]=1;
  }
  for(i=1;i<=x-2;i++)
  {
  	for(j=1;j<=x-i-1;j++)
  	{
  	  k=x-i-j;
  	  mex[sg(i)^sg(j)^sg(k)]=1;
	}
  }
  for(i=0;i<MAXX;i++)
  {
  	if(!mex[i])
  	{
  	  return ak[x]=i;
	}
  }
}
