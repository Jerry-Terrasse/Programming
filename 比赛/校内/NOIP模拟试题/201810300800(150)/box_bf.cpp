#include<iostream>
#include "memory.h"
#define MAXN 5050
using namespace std;
int usse[MAXN],use[MAXN],us[MAXN],a[MAXN],b[MAXN],n=0,ans=0x7fffffff;
void dfs(const int&);
inline void judge();
inline void calc();
int find(const int&);
int main()
{
  register int i=0;
  cin>>n;
  for(i=1;i<=n;++i)
  {
  	cin>>a[i];
  }
  dfs(1);
  cout<<ans<<endl;
  return 0;
}
int find(const int &x)
{
  return us[x]==x?x:us[x]=find(us[x]);
}
inline void calc()
{
  register int i=0,j=0;
  memset(use,0,sizeof(use));
  for(i=1;i<=n;++i)
  {
  	us[i]=i;
  }
  for(i=1;i<=n;++i)
  {
  	for(j=b[i];j;j=b[j])
  	{
  	  us[find(j)]=find(i);
	}
  }
  for(i=1;i<=n;++i)
  {
  	++use[find(i)];
  }
  for(i=1,j=0;i<=n;++i)
  {
  	if(use[i])
  	{
  	  ++j;
	}
  }
  if(j<ans)
  {
  	ans=j;
  }
  return;
}
inline void judge()
{
  register int i=0,j=0,cnt=0;
  bool bo=true;
  for(i=1;i<=n;++i)
  {
  	for(cnt=0,j=b[i];j&&cnt<=a[i];++cnt,j=b[j]);
  	if(cnt>a[i])
  	{
  	  bo=false;
  	  break;
	}
  }
  if(bo)
  {
  	calc();
  }
  return;
}
void dfs(const int &x)
{
  if(x==n+1)
  {
  	judge();
  	return;
  }
  register int i=0;
  for(b[x]=0;b[x]<=n;++b[x])
  {
  	if(b[x]&&usse[b[x]])
  	{
  	  continue;
	}
	usse[b[x]]=1;
    dfs(x+1);
	usse[b[x]]=0;
  }
  return;
}
