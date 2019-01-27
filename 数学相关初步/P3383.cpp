#include<iostream>
#include "memory.h"
#define MAXN 10000010
using namespace std;
int ok[MAXN],zs[MAXN],cnt=0,n=0,m=0;
int main()
{
  int i=2,j=0;
  memset(ok,0xff,sizeof(ok));
  ok[0]=ok[1]=false;
  for(cin>>n>>m;i<n;i++)
  {
  	if(ok[i])
  	{
  	  zs[cnt++]=i;
	}
	for(j=0;j<cnt && i*zs[j]<=n;j++)
	{
	  ok[i*zs[j]]=false;
	}
  }
  for(i=0;i<m;i++)
  {
  	cin>>j;
  	if(ok[j])
  	{
  	  cout<<"Yes"<<endl;
	}
	else
	{
	  cout<<"No"<<endl;
	}
  }
  return 0;
}
