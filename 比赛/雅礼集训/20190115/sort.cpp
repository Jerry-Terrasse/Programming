//sort_bf.cpp
#include<cstdio>
#include<algorithm>
#include "memory.h"
#define MAXN 100010
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
int use[MAXN],a[MAXN],n=0,ans=0;
inline void read(int&);
void write(const int&);
void dfs1(const int&,const int&);
int main()
{
  register int i=0;
  freopen("sort.in","r",stdin);freopen("sort.out","w",stdout);
  memset(use,-1,sizeof(use));
  read(n);
  for(i=1;i<=n;++i)
  {
    read(a[i]);
  }
  sort(a+1,a+n+1);
  if(n<=10)
  {
    for(i=1;i<=n;++i)
    {
      use[i]=0;
      dfs1(2,a[i]);
      use[i]=1;
    }
    write(ans);
    return 0;
  }
  reverse(a+1,a+n+1);
  if(a[n]==a[n-1])
  {
    ans=0;
  }
  else
  {
    ans=a[n];
  }
  for(i=1;i<n;++i)
  {
    //write(i);
    if(ans<a[i]%a[n])
    {
      ans=a[i]%a[n];
    }
  }
  write(ans);
  return 0;
}
void dfs1(const int &x,const int &ret)
{
  if(x>n)
  {
    if(ans<ret)
    {
      ans=ret;
    }
    return;
  }
  register int i=0;
  for(i=1;i<=n;++i)
  {
    if(use[i]&&ret%a[i]>ans)
    {
      use[i]=0;
      dfs1(x+1,ret%a[i]);
      use[i]=1;
    }
  }
  return;
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
  for(x=0;c<'0'||c>'9';c=getchar());
  for(;c>='0'&&c<='9';c=getchar())
  {
    x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}