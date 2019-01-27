#include<iostream>
#include "memory.h"
#define MAXN 100010
#define big_MAX 1000010
#define MAX 78499
using namespace std;
int v[big_MAX],zs[MAX],p[MAX],cnt=0,mx=0,a=0,t=0,n=0,m=0;
inline void make();
int main()
{
  int i=0,j=0,k=0;
  ios::sync_with_stdio(0);
  make();
  for(cin>>t;t;t--)
  {
  	for(cin>>n>>m;n;n--)
  	{
  	  cin>>a;
  	  for(i=0;a!=1 && i<mx;i++)
  	  {
  	  	for(;a%zs[i]==0;p[i]++,a/=zs[i]); 
	  }
	  if(a!=1)
	  {
	  	/*extra[cnt++]=a;*/
	  	cnt++;
	  }
	}
	for(;m;m--)
	{
	  cin>>a;
  	  for(i=0;a!=1 && i<mx;i++)
  	  {
  	  	for(;a%zs[i]==0;p[i]--,a/=zs[i]); 
	  }
	  if(a!=1)
	  {
	  	/*for(i=0;i<cnt;i++)
	  	{
	  	  if(extra[i]==a)
	  	  {
	  	  	extra[i]=0;
		  }
		}*/
		cnt--;
	  }
	}
	for(i=0;i<mx;i++)
	{
	  cnt+=p[i];
	}
	if(cnt==1)
	{
	  cout<<"YES"<<endl;
	}
	else
	{
	  cout<<"NO"<<endl;
	}
  }
  return 0;
}
inline void make()
{
  int cnt=0,i=2,j=0;
  for(;cnt<MAX && i<big_MAX;i++)
  {
  	if(!v[i])
  	{
  	  v[i]=i;
  	  zs[cnt++]=i;
  	  //cout<<i<<endl;
	}
	for(j=0;j<cnt;j++)
	{
	  if(zs[j]>v[i]||zs[j]>n/i)
	  {
	  	break;
	  }
	  else
	  {
	  	v[i*zs[j]]=zs[j];
	  }
	}
  }
  mx=cnt;
  return;
}
