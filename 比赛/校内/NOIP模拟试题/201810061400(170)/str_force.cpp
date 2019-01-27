#include<iostream>
#include "memory.h"
#define MAXN 100010
#define MAXK 30
using namespace std;
int n=0,k=0;
bool use[MAXK],done=false;
char a[MAXN];
void dfs(const int&);
inline void judge();
inline void output();
int main()
{
  int i=0;
  ios::sync_with_stdio(0);
  cin>>n>>k;
  dfs(1);
  if(!done)
  {
  	cout<<-1<<endl;
  }
  //done=false;
  //main();
  return 0;
}
inline void output()
{
  int i=1;
  for(;i<=n;++i)
  {
  	cout<<a[i];
  }
  cout<<endl;
  return;
}
inline void judge()
{
  int i=1;
  memset(use,0,sizeof(use));
  for(;i<=n;++i)
  {
  	use[a[i]-'a']=1;
  }
  for(done=true,i=0;i<k;++i)
  {
  	if(!use[i])
  	{
  	  done=false;
  	  break;
	}
  }
  if(done)
  {
  	output();
  }
  return;
}
void dfs(const int &x)
{
  if(x==n+1)
  {
  	if(done)
  	{
  	  return;
	}
  	judge();
  	return;
  }
  if(done)
  {
  	return;
  }
  for(a[x]='a';a[x]<'a'+k;++a[x])
  {
  	if(a[x-1]!=a[x])
	{
	  dfs(x+1);
	  if(done)
	  {
	  	return;
	  }
	}
  }
  return;
}
