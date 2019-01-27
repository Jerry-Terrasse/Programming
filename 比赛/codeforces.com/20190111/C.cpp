#include<cstdio>
#include<algorithm>
#include "memory.h"
#define MAXN 100010
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
struct seg
{
  int l,r,id;
}a[MAXN];
int ans[MAXN],f=0,n=0,t=0;
inline void read(int&);
void write(const int&);
inline void init();
inline bool cmp1(const seg&,const seg&);
int main()
{
  register int i=0;
  read(t);
  for(;t--;)
  {
    init();
    sort(a+1,a+n+1,cmp1);
    f=a[1].r;ans[a[1].id]=1;
    for(i=2;i<=n;++i)
    {
      if(a[i].l<=f)
      {
        f=max(f,a[i].r);
        ans[a[i].id]=1;
      }
      else
      {
        break;
      }
    }
    if(i>n)
    {
      puts("-1");
    }
    else
    {
      for(;i<=n;++i)
      {
        ans[a[i].id]=2;
      }
      for(i=1;i<=n;++i)
      {
        write(ans[i]);
        putchar(' ');
      }
      putchar('\n');
    }
  }
  return 0;
}
inline void init()
{
  register int i=0;
  memset(a,0,sizeof(a));
  f=0;
  read(n);
  for(i=1;i<=n;++i)
  {
    read(a[i].l);read(a[i].r);
    a[i].id=i;
  }
  return;
}
inline bool cmp1(const seg &x,const seg &y)
{
  return x.l<y.l;
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