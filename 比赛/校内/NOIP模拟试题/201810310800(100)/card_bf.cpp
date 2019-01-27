#include<iostream>
#include<algorithm>
#include "memory.h"
#define MAXN 100010
using namespace std;
struct card
{
  int x,y;
}a[MAXN];
int f[MAXN],n=0,cnt=0,ans=0x7fffffff;
inline bool cmp(const card&,const card&);
int main()
{
  int i=0,j=0;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n;
  for(i=1;i<=n;++i)
  {
  	cin>>a[i].x>>a[i].y;
  }
  sort(a+1,a+n+1,cmp);
  for(i=1;i<=n;++i)
  {
  	if(a[i].x!=a[i-1].x)
  	{
  	  memset(f,0,sizeof(f));
  	  for(j=1;j<=n;++j)
  	  {
  	    if(a[j].x==a[i].x)
  	    {
  	      f[a[j].y]=1;
		}
	  }
	}
	for(cnt=0,j=1;j<n;++j)
	{
	  if(!f[a[i].y+j])
	  {
	  	++cnt;
	  }
	}
	ans=min(ans,cnt);
  }
  cout<<ans<<endl;
  return 0;
}
inline bool cmp(const card &a,const card &b)
{
  return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
