//P1494 [国家集训队]小Z的袜子
//ChongGou
#include<cstdio>
#include<algorithm>
#include<cmath>
#include "memory.h"
#define int long long
#define MAXN 50050
#define C(x) ((x)*((x)-1)>>1)
using namespace std;
struct que
{
  int l,r,id,ans;
}md[MAXN];
int f[MAXN],a[MAXN],n=0,m=0,s=0;
inline void read(int&);
void write(const int&);
inline bool cmp1(const que&,const que&);
inline bool cmp2(const que&,const que&);
inline bool cmp3(const que&,const que&);
inline void work(que*,que*);
signed main()
{
  register int i=0,j=0;
  register que *p=NULL,*end=NULL;
  read(n);read(m);s=sqrt(m);
  for(i=1;i<=n;++i)
  {
    read(a[i]);
  }
  for(p=md,end=md+m;p!=end;++p)
  {
    p->id=p-md;read(p->l);read(p->r);
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
  sort(md,md+m,cmp3);
  for(p=md;p!=end;++p)
  {
    if(p->l==p->r)
    {
      puts("0/1");
    }
    else
    {
      i=__gcd(p->ans,j=C(p->r+1-p->l));
      write(p->ans/i);
      putchar('/');
      write(j/i);
      putchar('\n');
    }
  }
  return 0;
}
inline void work(que *L,que *R)
{
  register que *p=L;
  register int i=0,l=0,r=0,ret=0;
  memset(f,0,sizeof(f));
  for(;p->l==p->r;++p);
  l=p->l;r=p->r;
  for(i=l;i<=r;++i)
  {
    ret-=C(f[a[i]]);
    ++f[a[i]];
    ret+=C(f[a[i]]);
  }
  for(p->ans=ret,++p;p!=R;p->ans=ret,++p)
  {
    if(p->l==p->r)
    {
      continue;
    }
    for(i=l-1;i>=p->l;--i)
    {
      ret-=C(f[a[i]]);
      ++f[a[i]];
      ret+=C(f[a[i]]);
    }
    for(i=l;i<p->l;++i)
    {
      ret-=C(f[a[i]]);
      --f[a[i]];
      ret+=C(f[a[i]]);
    }
    for(i=r+1;i<=p->r;++i)
    {
      ret-=C(f[a[i]]);
      ++f[a[i]];
      ret+=C(f[a[i]]);
    }
    l=p->l;r=p->r;
  }
  return;
}
inline bool cmp3(const que &x,const que &y)
{
  return x.id<y.id;
}
inline bool cmp2(const que &x,const que &y)
{
  return x.r<y.r;
}
inline bool cmp1(const que &x,const que &y)
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