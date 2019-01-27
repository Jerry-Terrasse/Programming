//P4867 Gty的二逼妹子序列
//Fenwick Tree
#include<cstdio>
#include<algorithm>
#include<cmath>
#include "memory.h"
#include "memory.h"
#define MAXN 100010
#define MAXM 1000010
#define lbt(x) ((x)&-(x))
using namespace std;
struct que
{
  int l,r,a,b,id;
  inline void input();
}md[MAXM];
int ans[MAXM],ft[MAXN],f[MAXN],a[MAXN],n=0,m=0,s=0;
inline void read(int&);
void write(const int&);
inline bool cmp1(const que&,const que&);
inline bool cmp2(const que&,const que&);
inline void work(que*,que*);
inline void init();
inline void add(int);
inline void mnd(int);
inline int sum(int);
int main()
{
  register int i=0;
  read(n);read(m);s=sqrt(m);
  for(i=1;i<=n;++i)
  {
    read(a[i]);
  }
  for(i=0;i<m;++i)
  {
    md[i].input();
  }
  sort(md,md+m,cmp1);
  for(i=0;i<s;++i)
  {
    sort(md+i*s,md+(i+1)*s,cmp2);
    work(md+i*s,md+(i+1)*s);
  }
  if(s*s<m)
  {
    sort(md+s*s,md+m,cmp2);
    work(md+s*s,md+m);
  }
  for(i=0;i<m;++i)
  {
    write(ans[i]);
    putchar('\n');
  }
  return 0;
}
inline int sum(int x)
{
  register int ret=0;
  for(;x;x-=lbt(x))
  {
    ret+=ft[x];
  }
  return ret;
}
inline void mns(int x)
{
  for(;x<=n;x+=lbt(x))
  {
    --ft[x];
  }
  return;
}
inline void add(int x)
{
  for(;x<=n;x+=lbt(x))
  {
    ++ft[x];
  }
  return;
}
inline void init()
{
  memset(f,0,sizeof(f));
  memset(ft,0,sizeof(ft));
  return;
}
inline void work(que *L,que *R)
{
  register que *p=L;
  register int i=0,l=p->l,r=p->r;
  init();
  for(i=l;i<=r;++i)
  {
    if(!f[a[i]]++)
    {
      add(a[i]);
    }
  }
  ans[p->id]=sum(p->b)-sum(p->a-1);
  for(++p;p!=R;++p)
  {
    for(i=l-1;i>=p->l;--i)
    {
      if(!f[a[i]]++)
      {
        add(a[i]);
      }
    }
    for(i=l;i<p->l;++i)
    {
      if(!--f[a[i]])
      {
        mns(a[i]);
      }
    }
    for(i=r+1;i<=p->r;++i)
    {
      if(!f[a[i]]++)
      {
        add(a[i]);
      }
    }
    ans[p->id]=sum(p->b)-sum(p->a-1);
    l=p->l;r=p->r;
  }
  return;
}
inline bool cmp2(const que &x,const que &y)
{
  return x.r<y.r;
}
inline bool cmp1(const que &x,const que &y)
{
  return x.l<y.l;
}
inline void que::input()
{
  id=this-md;
  read(l);read(r);read(a);read(b);
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