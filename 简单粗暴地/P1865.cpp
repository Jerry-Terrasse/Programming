#include<iostream>
#include "memory.h"
#define MAXM 1000010
#define lbt(x) (-(x)&(x))
using namespace std;
int zs[MAXM],ba[MAXM],n=0,m=0,cnt=0;
inline void prime();
inline void add(int);
inline int sum(int);
int main()
{
  int i=0,u=0,v=0;
  cin>>n>>m;
  prime();
  for(i=1;i<=cnt;++i)
  {
  	add(zs[i]);
  }
  for(;n--;)
  {
  	cin>>u>>v;
  	if(u<1||v>m)
  	{
  	  cout<<"Crossing the line"<<endl;
	}
	else
	{
	  cout<<sum(v)-sum(u-1)<<endl;
	}
  }
  return 0;
}
inline int sum(int x)
{
  int ans=0;
  for(;x;x-=lbt(x))
  {
  	ans+=ba[x];
  }
  return ans;
}
inline void add(int x)
{
  for(;x<=m;x+=lbt(x))
  {
  	++ba[x];
  }
  return;
}
inline void prime()
{
  int i=0,j=0;
  memset(zs,-1,sizeof(zs));
  for(i=2;i<=m;++i)
  {
  	if(zs[i])
  	{
  	  zs[++cnt]=i;
	}
	for(j=1;j<=cnt&&zs[j]*i<=m;++j)
	{
	  zs[zs[j]*i]=0;
	  if(!(i%zs[j]))
	  {
	  	break;
	  }
	}
  }
  return;
}
