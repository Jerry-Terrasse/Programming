#include<cstdio>
#define int long long
#define MAXN 1000010
#define H 11111597780929
using namespace std;
struct node
{
  int val,lazy,l,r,mid;
  node *son,*daughter;
  int build(const int&,const int&);
  int add(const int&,const int&,const int&);
  int sum(const int&,const int&);
  inline void pushdown();
}mmp[MAXN<<2],*mmtop=mmp,*head;
int bt[MAXN],arc[MAXN],n=0,m=0;
inline void read(int&);
void write(const int&);
inline void init();
signed main()
{
  register int i=0,j=0,o=0,u=0,v=0;
  read(n);read(m);
  init();
  head=++mmtop;
  head->build(1,n+1);
  for(i=1;i<=m;++i)
  {
    read(o);read(u);read(v);
    if(o&1)
    {
      read(o);
      if(u>v)
      {
      	continue;
      }
      head->add(u,v+1,o%H);
    }
    else
    {
      if(u>v)
      {
      	puts("0");
      	continue;
      }
	  o=head->sum(u,v+1);
      (o*=arc[v+1-u])%=H;
      write(o);
      putchar('\n');
    }
  }
  return 0;
}
inline void init()
{
  register int i=0;
  for(arc[1]=1,i=2;i<=n;++i)
  {
    arc[i]=((-H/i*arc[H%i])%H+H)%H;
  }
  return;
}
int node::sum(const int &il,const int &ir)
{
  if(il==l&&ir==r)
  {
    return val;
  }
  if(lazy)
  {
    pushdown();
  }
  if(ir<=mid)
  {
    return son->sum(il,ir);
  }
  if(mid<=il)
  {
    return daughter->sum(il,ir);
  }
  return (son->sum(il,mid)+daughter->sum(mid,ir))%H;
}
inline void node::pushdown()
{
  (son->lazy+=lazy)%=H;
  (son->val+=(mid-l)*lazy)%=H;
  (daughter->lazy+=lazy)%=H;
  (daughter->val+=(r-mid)*lazy)%=H;
  lazy=0;
  return;
}
int node::add(const int &il,const int &ir,const int &ik)
{
  if(il==l&&ir==r)
  {
    (lazy+=ik)%=H;
    return (val+=(r-l)*ik)%=H;
  }
  if(lazy)
  {
    pushdown();
  }
  if(ir<=mid)
  {
    return (val=son->add(il,ir,ik)+daughter->val)%=H;
  }
  if(mid<=il)
  {
    return (val=son->val+daughter->add(il,ir,ik))%=H;
  }
  return (val=son->add(il,mid,ik)+daughter->add(mid,ir,ik))%=H;
}
int node::build(const int &il,const int &ir)
{
  l=il;r=ir;mid=l+r+1>>1;lazy=0;
  if(l+1==r)
  {
    read(val);
    return val%=H;
  }
  son=++mmtop;daughter=++mmtop;
  return (val=son->build(l,mid)+daughter->build(mid,r))%=H;
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
