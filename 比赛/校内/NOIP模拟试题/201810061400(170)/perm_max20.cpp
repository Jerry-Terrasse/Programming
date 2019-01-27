#include<iostream>
#include "memory.h"
#define ll long long
#define MAXN 5050
using namespace std;
int use[MAXN],a[MAXN],b[MAXN],n=0;
ll js[MAXN],oa=0,ob=0;
inline ll kt(int*);
inline void arckt(ll,int*);
inline void init();
int main()
{
  int i=1;
  cin>>n;
  init();
  for(;i<=n;++i)
  {
  	cin>>a[i];
  }
  for(i=1;i<=n;++i)
  {
  	cin>>b[i];
  }
  //if(n<=20)
  {
  	oa=kt(a);
    ob=kt(b);
    arckt((oa+ob)%js[n],a);
  }
  //else
  {
  	
  }
  for(i=1;i<=n;++i)
  {
  	cout<<a[i]<<' ';
  }
  cout<<endl;
  return 0;
}
inline void arckt(ll x,int *s)
{
  int i=1,j=0,k=0;
  memset(use,0,sizeof(use));
  for(;x;++i)
  {
  	j=x/js[n-i];
  	for(k=0;j||use[k];++k)
  	{
  	  j-=(!use[k]);
	}
	use[k]=1;
	s[i]=k;
	x%=js[n-i];
  }
  for(k=0;i<=n;++k)
  {
  	if(!use[k])
  	{
  	  s[i++]=k;
	}
  }
  return;
}
inline void init()
{
  int i=1;
  for(js[0]=1;i<=n;++i)
  {
  	js[i]=js[i-1]*i;
  }
  return;
}
inline ll kt(int *a)
{
  int i=1,j=0;
  memset(use,0,sizeof(use));
  ll ans=0;
  for(;i<n;++i)
  {
  	for(j=0;j<a[i];++j)
  	{
  	  if(!use[j])
  	  {
  	    ans++;
	  }
	}
	use[a[i]]=1;
	ans*=n-i;
  }
  return ans;
}
