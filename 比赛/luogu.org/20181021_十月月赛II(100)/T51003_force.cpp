#include<iostream>
#include<algorithm> 
#define MAXN 550
#define H 1000000007
using namespace std;
int b[MAXN*MAXN],a[MAXN],n=0,p=0,r=0,ans=0;
inline void work();
void dfs(const int&);
int main()
{
  int i=0;
  cin>>n>>p>>r;
  dfs(1);
  cout<<ans<<endl;
  return 0;
}
inline void work()
{
  int i=0,j=0,cnt=0;
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=n;++j)
  	{
  	  b[++cnt]=a[i]*a[j]%p;
	}
  }
  sort(b+1,b+cnt+1);
  ans+=unique(b+1,b+cnt+1)-b-1;
  ans%=H;
  return;
}
void dfs(const int &x)
{
  if(x==n+1)
  {
  	work();
  	return;
  }
  for(a[x]=1;a[x]<=r;++a[x])
  {
  	dfs(x+1);
  }
  return;
}
