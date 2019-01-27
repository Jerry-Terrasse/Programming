#include<iostream>
#include<algorithm>
#include "memory.h"
#define MAXN 1010
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
struct tr
{
  int s,p;
}a[MAXN];
int f[MAXN],n=0,k=0,ans=0;
inline char cmp(const tr&,const tr&);
int main()
{
  int i=0,j=0;
  for(;;)
  {
    cin>>n>>k;
    if(!(n||k))
    {
      return 0;
    }
    ans=0;
    memset(a,0,sizeof(a));
    memset(f,0,sizeof(f));
    for(i=1;i<=n;++i)
    {
      cin>>a[i].s;
    }
    for(i=1;i<=n;++i)
    {
      cin>>a[i].p;
    }
    sort(a+1,a+n+1,cmp);
    for(i=1;i<=n;++i)
    {
      for(j=max(k,i);j;--j)
      {
        f[j]=max(f[j],f[j-1]+max(a[i].s-a[i].p*(j-1),0));
      }
    }
    for(i=1;i<=k;++i)
    {
      ans=max(ans,f[i]);
	}
	cout<<ans<<endl;
  }
  return 0;
}
inline char cmp(const tr &a,const tr &b)
{
  return a.p>b.p||(a.p==b.p&&a.s>b.s);
}
