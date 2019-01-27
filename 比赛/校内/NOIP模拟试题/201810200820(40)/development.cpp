#include<iostream>
#define MAXN 55
using namespace std;
struct node
{
  int son[MAXN],val,cnt;
}tr[MAXN];
int s[10000000],fa[MAXN],mul[MAXN],n=0,p=0,r=0,cnt=0,ans=0;
void work(const int&);
inline void init();
void dfs(const int&);
int main()
{
  int i=0;
  freopen("development.in","r",stdin);freopen("development.out","w",stdout);
  cin>>n>>p>>r;
  if(n>9)
  {
  	cout<<-1<<endl;
  	return 0;
  }
  for(i=1;i<n;++i)
  {
  	mul[i]=i*(n-i);
  }
  fa[1]=1;
  work(2);
  for(i=0;i<10000000;++i)
  {
  	if(s[i]&&i%p==r)
  	{
  	  cout<<i<<endl;
  	  return 0;
	}
  }
  cout<<-1<<endl;
  return 0;
}
void dfs(const int &x)
{
  int i=0;
  for(i=0;i<tr[x].cnt;++i)
  {
  	dfs(tr[x].son[i]);
  	tr[x].val+=tr[tr[x].son[i]].val;
  }
  ans+=mul[tr[x].val];
  return;
}
inline void init()
{
  int i=0;
  ans=0;
  for(i=1;i<=n;++i)
  {
  	tr[i].cnt=0;
	tr[i].val=1;
  }
  for(i=2;i<=n;++i)
  {
  	tr[fa[i]].son[tr[fa[i]].cnt++]=i;
  }
  return;
}
void work(const int &x)
{
  if(x==n+1)
  {
  	init();
  	dfs(1);
  	s[ans]=1;
  	return;
  }
  for(fa[x]=1;fa[x]<=n;++fa[x])
  {
  	if(fa[x]==x)
  	{
  	  continue;
	}
	work(x+1);
  }
  return;
}
