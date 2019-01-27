#include<cstdio>
#include<bitset>
#include "memory.h"
#define MAXN 200020
#define min(x,y) ((x)<(y)?(x):(y))
#define dis(x,y) (min(((y)-(x)),((x)+n-(y))))
using namespace std;
int a[MAXN<<2],n=0,m=0,ans=0x7fffffff,d=ans,st=0;
bitset<MAXN<<1>use;
inline void work(int,int);
inline void read(int&);
void write(const int&);
int main()
{
  register int i=0,j=0,u=0,v=0;
  //ios::sync_with_stdio(false);cin.tie(0);
  read(m);
  n=m<<1;
  for(i=1;i<=m;++i)
  {
    read(u);read(v);
    if(u>v)
    {
      u^=v^=u^=v;
    }
    if(d>dis(u,v))
    {
      d=dis(u,v);
      st=u;
    }
    a[u]=a[v]=a[u+n]=a[v+n]=i;
  }
  work(st,st+n-1);
  for(i=st+1;a[i]!=a[st];++i)
  {
    work(i,i+n-1);
  }
  work(i,i+n-1);
  write(ans+1>>1);
  return 0;
}
void write(const int &x)
{
  if(x>9)
  {
    write(x/10);
  }
  putchar(x%10^48);
  return;
}
inline void read(int &x)
{
  register char c=getchar();
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
    x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
inline void work(int l,int r)
{
  register int i=0,ret=0;
  //cout<<"!!!!!!!!!!"<<endl;
  for(i=l;i<r;)
  {
    //memset(use,0,sizeof(use));
    use.reset();
    //use&=0;
    /*for(register int kk=1;kk<=m;++kk)
    {
      use[kk]=0;
    }*/
    ++ret;
    for(;i<r&&!use[a[i]];++i)
    {
      use[a[i]]=1;
    }
  }
  if(ret<ans)
  {
    ans=ret;
  }
  return;
}