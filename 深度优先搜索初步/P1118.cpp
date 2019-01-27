#include<iostream>
#include<cstdlib>
#define _ 0
#define MAXN 16
using namespace std;
int a[MAXN],use[MAXN],ans[MAXN],n=0,s=0;
void dfs(const int&);
inline void init();
inline void output();
int main()
{
  int i=0;
  cin>>n>>s;
  --n;
  init();
  ++n;
  dfs(0);
  return ~~(0^_^0);
}
inline void output()
{
  int i=0;
  for(;i<n;++i)
  {
  	cout<<ans[i]<<' ';
  }
  cout<<endl;
  return;
}
void dfs(const int &x)
{
  if(s<0)
  {
  	return;
  }
  if(x==n)
  {
  	if(s)
  	{
  	  return;
	}
	else
	{
	  output();
	  exit(0);
	}
  }
  for(ans[x]=1;ans[x]<=n;++ans[x])
  {
  	if(!use[ans[x]])
  	{
  	  s-=a[x]*ans[x];use[ans[x]]=1;
  	  dfs(x+1);
  	  s+=a[x]*ans[x];use[ans[x]]=0;
	}
  }
  return;
}
inline void init()
{
  int i=0;
  a[0]=1;
  for(i=1;i<=n;++i)
  {
  	a[i]=a[i-1]*(n-i+1)/i;
  }
  return;
}
