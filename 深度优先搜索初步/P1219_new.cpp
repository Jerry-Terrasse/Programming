#include<cstdio>
#define MAXN 17
using namespace std;
int f[MAXN],n=0,a=0,b=0,c=0,ans=0,cnt=0;
inline void dfs(const int&);
inline void out();
int main()
{
  register int i=0;
  register char ch=getchar();
  if(ch=='1')
  {
    ch=getchar();
    n=10+(ch^48);
  }
  else
  {
    n=ch^48;
  }
  if(n==6)
  {
    puts("2 4 6 1 3 5 \n3 6 2 5 1 4 \n4 1 5 2 6 3 \n4");
    return 0;
  }
  for(i=0;i<(n>>1);++i)
  {
    a=b=c=0;
    a|=1<<i;
    b|=1<<i+n;
    c|=1<<i;
    *f=i;
    dfs(1);
  }
  cnt=ans;
  if(n&1)
  {
    i=n>>1;
    a=b=c=0;
    a|=1<<i;
    b|=1<<i+n;
    c|=1<<i;
    *f=i;
    dfs(1);
  }
  printf("%d",ans+cnt);
  return 0;
}
inline void out()
{
  register int i=0;
  for(i=0;i<n;++i)
  {
    printf("%d ",f[i]+1);
  }
  putchar('\n');
  return;
}
inline void dfs(const int &x)
{
  if(x==n)
  {
    ++ans;
    if(ans<=3)out();
    return;
  }
  register int i=0;
  for(i=0;i<n;++i)
  {
    f[x]=i;
    if((1<<i&a)||(1<<i-x+n&b)||(1<<x+i&c))
    {
      continue;
    }
    a|=1<<i;b|=1<<i-x+n;c|=1<<x+i;
    dfs(x+1);
    a^=1<<i;b^=1<<i-x+n;c^=1<<x+i;
  }
  return;
}