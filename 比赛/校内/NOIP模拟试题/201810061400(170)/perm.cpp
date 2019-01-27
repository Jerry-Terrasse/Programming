#include<iostream>
#include<algorithm>
#include "memory.h"
#define ll long long
#define MAXN 5050
using namespace std;
int use[MAXN],a[MAXN],b[MAXN],n=0;
ll js[MAXN],oa=0,ob=0;
inline ll kt(int*);
inline void arckt(ll,int*);
inline void init(int);
inline bool cmp(const int&,const int&);
int main()
{
  int i=1,j=0;
  freopen("perm.in","r",stdin);freopen("perm.out","w",stdout);
  cin>>n;
  for(;i<=n;++i)
  {
  	cin>>a[i];
  }
  for(i=1;i<=n;++i)
  {
  	cin>>b[i];
  }
  if(n<=20)
  {
    init(n);
  	oa=kt(a);
    ob=kt(b);
    arckt((oa+ob)%js[n],a);
  }
  else
  {
  	init(20);
  	for(;;)
  	{
  	  for(i=n;i>=1&&b[i]>=b[i+1];--i);
  	  ob+=js[n-i]-1;
  	  sort(b+i+1,b+n+1);
  	  for(;i>=1&&b[i]<b[i+1];--i);
  	  if(i==0)
  	  {
  	    break;
	  }
  	  for(j=n;b[j]>=b[i];j--);
  	  b[j]^=b[i];b[i]^=b[j];b[j]^=b[i];
  	  sort(b+i+1,b+n+1,cmp);
  	  ob++;
	}
	for(;ob;)
	{
	  for(i=n;i>=1&&a[i]>=a[i+1];--i);
	  if(i==0)
	  {
	  	sort(a+1,a+n+1);
	  	ob--;
	  	continue;
	  }
	  for(j=n;a[j]<a[i];--j);
	  a[i]^=a[j];a[j]^=a[i];a[i]^=a[j];
	  sort(a+i+1,a+n+1);
	  ob--;
	}
  }
  for(i=1;i<=n;++i)
  {
  	cout<<a[i]<<' ';
  }
  cout<<endl;
  return 0;
}
inline bool cmp(const int &a,const int &b)
{
  return a>b;
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
inline void init(int n)
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
