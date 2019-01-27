#include<iostream>
#define MAXN 1010
using namespace std;
int a[MAXN],m[MAXN],b[10],n=0,ans1=0,ans2=0x7fffffff;
char ch='\0';
void dfs(const int&);
inline void judge();
int main()
{
  int i=0;
  cin>>n;
  for(i=1;i<=n;++i)
  {
  	cin>>ch;
  	a[i]=ch-'0';
  }
  for(i=1;i<=n;++i)
  {
  	cin>>ch;
  	++b[ch^48];
  }
  dfs(1);
  cout<<ans1<<endl;
  cout<<ans2<<endl;
  return 0;
}
inline void judge()
{
  int i=0,win=0,lose=0;
  for(i=1;i<=n;++i)
  {
  	if(a[i]<m[i])
  	{
  	  ++win;
	}
	else if(a[i]>m[i])
	{
	  ++lose;
	}
  }
  if(win>ans1)
  {
  	ans1=win;
  }
  if(lose<ans2)
  {
  	ans2=lose;
  }
}
void dfs(const int &x)
{
  if(x==n+1)
  {
  	judge();
  }
  for(m[x]=0;m[x]<=9;++m[x])
  {
  	if(b[m[x]])
  	{
  	  --b[m[x]];
  	  dfs(x+1);
  	  ++b[m[x]];
	}
  }
  return;
}
