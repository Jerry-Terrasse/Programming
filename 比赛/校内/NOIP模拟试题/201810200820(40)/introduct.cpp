#include<iostream>
#include<memory.h>
#define MAXN 7
using namespace std;
struct node
{
  int son[MAXN],fa,id,cnt;
}tr[MAXN];
struct now
{
  int b[MAXN],r[MAXN],t[MAXN],turn,ans;
  now *next;
  int work();
  void dfs1(const int&);
  void dfs2(const int&);
}*head;
int n=0,m=0,k=0;
int main()
{
  int i=0,j=0;
  freopen("introduct.in","r",stdin);freopen("introduct.out","w",stdout);
  cin>>n>>m>>k;
  for(i=1;i<n;++i)
  {
  	cin>>j;
  	tr[j].son[tr[j].cnt++]=i;
  	tr[i].fa=j;
  	tr[i].id=i;
  }
  head=new now;
  memset(head->b,0,sizeof(head->b));
  memset(head->r,0,sizeof(head->r));
  memset(head->t,0,sizeof(head->t));
  head->turn=0;
  for(i=0;i<m;++i)
  {
  	cin>>head->r[i];
  	head->t[head->r[i]]=-1;
  }
  for(i=0;i<k;++i)
  {
  	cin>>head->b[i];
  	head->t[head->b[i]]=1;
  }
  head->work();
  cout<<head->ans<<endl;
  return 0;
}
void now::dfs1(const int &x)
{
  if(!ans)
  {
  	return;
  }
  if(x==m)
  {
  	next->work();
  	return;
  }
  int pre=next->b[x],i=0,u=0;
  if(tr[pre].fa!=pre&&(next->t[tr[pre].fa]==-1))
  {
  	ans=0;
  	return;
  }
  for(i=0;i<tr[pre].cnt;++i)
  {
  	if(next->t[tr[pre].son[i]]==-1)
  	{
  	  ans=0;
  	  return;
	}
  }
  if(tr[pre].fa!=pre&&(!next->t[tr[pre].fa]))
  {
  	next->b[x]=tr[pre].fa;
  	next->t[pre]=0;
  	next->t[next->b[x]]=1;
  	dfs1(x+1);
  	next->t[next->b[x]]=0;
  	next->t[pre]=1;
  	next->b[x]=pre;
    if(!ans)
    {
  	  return;
    }
  }
  for(i=0;i<tr[pre].cnt;++i)
  {
  	u=tr[pre].son[i];
	if(!t[u])
	{
	  next->b[x]=u;
	  next->t[pre]=0;
	  next->t[u]=-1;
	  dfs1(x+1);
	  next->t[u]=0;
	  next->t[pre]=-1;
	  next->b[x]=pre;
	  if(!ans)
	  {
	  	return;
	  }
	}
  }
  dfs1(x+1);
  return;
}
void now::dfs2(const int &x)
{
  if(x==m)
  {
  	next->work();
  	ans=max(ans,next->ans);
  	return;
  }
  dfs2(x+1);
  int pre=next->r[x],i=0,u=0;
  if(tr[pre].fa!=pre&&(!next->t[tr[pre].fa]))
  {
  	next->r[x]=tr[pre].fa;
  	next->t[pre]=0;
  	next->t[next->r[x]]=-1;
  	dfs2(x+1);
  	next->t[next->r[x]]=0;
  	next->t[pre]=-1;
  	next->r[x]=pre;
  }
  for(i=0;i<tr[pre].cnt;++i)
  {
  	u=tr[pre].son[i];
	if(!next->t[u])
	{
	  next->r[x]=u;
	  next->t[pre]=0;
	  next->t[u]=-1;
	  dfs2(x+1);
	  next->t[u]=0;
	  next->t[pre]=-1;
	  next->r[x]=pre;
	}
  }
  return;
}
int now::work()
{
  int i=0;
  next=new now;
  memcpy(next->t,t,sizeof(t));
  memcpy(next->b,b,sizeof(b));
  memcpy(next->r,r,sizeof(r));
  if(turn)
  {
  	ans=0x3f3f3f3f;
	next->turn=0;
	dfs1(0);
  }
  else
  {
  	ans=0;
  	next->turn=1;
	dfs2(0);
  }
  return ++ans;
}
