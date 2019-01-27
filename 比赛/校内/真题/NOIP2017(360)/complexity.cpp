#include<cstdio>
#include "memory.h"
#define MAXL 1010
#define MAXC 256
#define INF 0x3f3f3f
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
struct rpt
{
  char id;
  int son[MAXL],x,y,sons,ans;
  void input();
  void check();
} a[MAXL];
int use[MAXC],t=0,n=0,fail=false,ans=0,res=0,cnt=0,now=0;
inline void init();
int main()
{
  register int i=0,j=0;
  char c='\0';
  scanf("%d",&t);
  for(; t--;)
  {
    init();
    scanf("%d O(%c",&n,&c);
    if(c=='n')
    {
      scanf("^%d)\n",&ans);
    }
    else
    {
      scanf(")\n");
      ans=0;
    }
    for(; n;)
    {
      --n;
      for(c=getchar(); c!='F'&c!='E'; c=getchar());
      if(c=='E')
      {
        fail=true;
        continue;
      }
      for(c=getchar(); c<'a'|c>'z'; c=getchar());
      a[++cnt].id=c;
      now=cnt;
      for(c=getchar(); (c<'a'|c>'z')&(c<'0'|c>'9'); c=getchar());
      if(c>='a'&&c<='z')
      {
        a[now].x=-1;
      }
      else
      {
        for(; c>='0'&c<='9'; c=getchar())
        {
          a[now].x=a[now].x*10+(c^48);
        }
      }
      for(c=getchar(); (c<'a'|c>'z')&(c<'0'|c>'9'); c=getchar());
      if(c>='a'&&c<='z')
      {
        a[now].y=-1;
      }
      else
      {
        for(; c>='0'&c<='9'; c=getchar())
        {
          a[now].y=a[now].y*10+(c^48);
        }
      }
      a[now].input();
      a[now].check();
      res=max(a[now].ans,res);
    }
    if(fail)
    {
      puts("ERR");
    }
    else if(ans==res)
    {
      puts("Yes");
    }
    else
    {
      puts("No");
    }
  }
  return 0;
}
void rpt::check()
{
  if(use[id])
  {
    fail=true;
    return;
  }
  use[id]=true;
  if(x>0)
  {
  	if(y>0)
  	{
  	  if(x<=y)
  	  {
  	    ans=0;
	  }
	  else
	  {
	  	ans=-INF;
	  }
	}
	else
	{
	  ans=1;
	}
  }
  else
  {
  	if(y>0)
  	{
  	  ans=-INF;
	}
	else
	{
	  ans=0;
	}
  }
  register int i=0,maxans=0;
  for(i=1;i<=sons;++i)
  {
  	a[son[i]].check();
  	if(fail)
  	{
  	  return;
	}
  	if(maxans<a[son[i]].ans)
  	{
  	  maxans=a[son[i]].ans;
	}
  }
  ans+=maxans;
  use[id]=false;
  return;
}
void rpt::input()
{
  register char c='\0';
  register int i=0;
  for(; n;)
  {
    --n;
	for(c=getchar(); c!='F'&c!='E'; c=getchar());
    if(c=='E')
    {
      return;
    }
    for(c=getchar(); c<'a'|c>'z'; c=getchar());
    son[++sons]=++cnt;
    a[cnt].id=c;
    for(c=getchar(); (c<'a'|c>'z')&(c<'0'|c>'9'); c=getchar());
    if(c>='a'&&c<='z')
    {
      a[cnt].x=-1;
    }
    else
    {
      for(; c>='0'&c<='9'; c=getchar())
      {
        a[cnt].x=a[cnt].x*10+(c^48);
      }
    }
    for(c=getchar(); (c<'a'|c>'z')&(c<'0'|c>'9'); c=getchar());
    if(c>='a'&&c<='z')
    {
      a[cnt].y=-1;
    }
    else
    {
      for(; c>='0'&c<='9'; c=getchar())
      {
        a[cnt].y=a[cnt].y*10+(c^48);
      }
    }
    a[cnt].input();
  }
  fail=true;
  return;
}
inline void init()
{
  memset(a,0,sizeof(a));
  memset(use,0,sizeof(use));
  fail=false;
  cnt=ans=res=now=0;
  return;
}
