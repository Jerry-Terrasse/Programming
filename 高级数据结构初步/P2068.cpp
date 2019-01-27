#include<iostream>
#define MAXN 100010
#define lbt(x) (x&-x)
using namespace std;
int a[MAXN],n=0,m=0;
inline void add(int,int);
inline int sum(int);
int main()
{
  int i=1,u=0,v=0;
  char c='\0';
  for(cin>>n>>m;i<=m;i++)
  {
  	cin>>c>>u>>v;
  	if(c=='x')
  	{
  	  add(u,v);
	}
	else
	{
	  cout<<sum(v)-sum(u-1)<<endl;
	}
  }
  return 0;
}
inline void add(int x,int k)
{
  int i=x;
  for(;i<=n;i+=lbt(i))
  {
  	a[i]+=k;
  }
  return;
}
inline int sum(int x)
{
  int ans=0,i=x;
  for(;i>0;i-=lbt(i))
  {
  	ans+=a[i];
  }
  return ans;
}
