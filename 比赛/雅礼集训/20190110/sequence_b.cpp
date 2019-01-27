#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
#define MAXN 100010
//#define MAXN 2020
#define MAXQ 500050
using namespace std;
struct que
{
  int l,r,id;
}md[MAXQ];
int a[MAXN],n=0,q=0,k=0,s=0;
ll ans[MAXQ];
bool flag=false;
inline void read(int&);
void write(const ll&);
inline bool cmp1(const que&,const que&);
inline bool cmp2(const que&,const que&);
inline void work(que*,que*);
inline int rwk(const int&,const int&);
inline int lwk(const int&,const int&);
inline void work();
int main()
{
  register int i=0;
  read(n);read(q);read(k);//s=pow(q,(double)9/16);
  if(!q)
  {
    return 0;
  }
  s=sqrt(q*log(n));
  for(i=1;i<=n;++i)
  {
    read(a[i]);
  }
  for(i=0;i<q;++i)
  {
    md[i].id=i;
    read(md[i].l);read(md[i].r);
  }
  if(k==1)
  {
    work();
    return 0;
  }
  flag=(k==2);
  sort(md,md+q,cmp1);
  for(i=0;(i+1)*s<=q;++i)
  {
    sort(md+i*s,md+(i+1)*s,cmp2);
    work(md+i*s,md+(i+1)*s);
  }
  if(i*s<q)
  {
    sort(md+i*s,md+q,cmp2);
    work(md+i*s,md+q);
  }
  for(i=0;i<q;++i)
  {
    write(ans[i]);
    putchar('\n');
  }
  return 0;
}
inline void work()
{
  register int i=0;
  register que *p=md;
  for(;p!=md+q;++p)
  {
    ++p->r-=p->l;
    write(((ll)p->r*(p->r-1)>>1)+p->r);
    putchar('\n');
  }
  return;
}
inline int lwk(const int &l,const int &r)
{
  register int i=0,ret=0,sum=a[l];
  if(flag)
  {
    for(i=l;i<=r;++i)
    {
      sum&=a[i];
      if(sum&1^1)
      {
        ++ret;
      }
    }
    return ret;
  }
  for(i=l;i<=r;++i)
  {
    sum&=a[i];
    if(!(sum%k))
    {
      ++ret;
    }
  }
  return ret;
}
inline int rwk(const int &l,const int &r)
{
  register int i=0,ret=0,sum=a[r];
  if(flag)
  {
    for(i=r;i>=l;--i)
    {
      sum&=a[i];
      if(sum&1^1)
      {
        ++ret;
      }
    }
    return ret;
  }
  for(i=r;i>=l;--i)
  {
    sum&=a[i];
    if(!(sum%k))
    {
      ++ret;
    }
  }
  return ret;
}
inline void work(que *L,que *R)
{
  register que *p=L;
  register int i=0,l=p->l,r=p->r;
  register ll ret=0;
  for(i=l,ret=0;i<=r;++i)
  {
    ret+=rwk(l,i);
  }
  ans[p->id]=ret;
  for(++p;p!=R;++p)
  {
    for(i=l-1;i>=p->l;--i)
    {
      ret+=lwk(i,r);
    }
    for(i=l;i<p->l;++i)
    {
      ret-=lwk(i,r);
    }
    l=p->l;
    for(i=r+1;i<=p->r;++i)
    {
      ret+=rwk(l,i);
    }
    r=p->r;
    ans[p->id]=ret;
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
void write(const ll &x)
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