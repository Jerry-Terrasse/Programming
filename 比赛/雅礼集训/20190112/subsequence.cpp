#include<cstdio>
#define int long long
#define MAXN 100010
#define MEM 1<<19
using namespace std;
struct node
{
  int cnt,key,val,lazy;
  node *son,*daughter;
  inline node();
  void insert(const int&,const int&);
  int sum(int);
  void add(int,int,const int&);
  inline void pushdown();
  inline void pushup();
}mmp[MEM],*head=NULL,*mtp=mmp;
int a[MAXN],n=0,maxn=0;
inline void read(int&);
void write(const int&);
inline void _write(const int&);
signed main()
{
  register int i=0,l=0,r=0,mid=0;
  maxn=1<<17;
  maxn*=maxn;
  head=mtp++;
  read(n);
  for(i=1;i<=n;++i)
  {
    read(a[i]);
  }
  head->insert(1,a[1]);
  for(i=2;i<=n;++i)
  {
    for(l=0,r=i;l+1<r;)
    {
      mid=l+r+1>>1;
      if(head->sum(mid)-head->sum(mid-1)<a[i]*mid)
      {
        r=mid;
      }
      else
      {
        l=mid;
      }
    }
    head->insert(r,a[i]*r);
    head->add(r+1,i,a[i]);
  }
  for(i=1;i<=n;++i)
  {
    _write(head->sum(i));
  }
  return 0;
}
void node::add(int il,int ir,const int &k)
{
  if(lazy)
  {
    pushdown();
  }
  if(il>1)
  {
    register int sct=0;
    if(son)
    {
      sct=son->cnt;
    }
    if(il<=sct+1&&ir>=sct+1)
    {
      key+=k;
      son->add(il,sct,k);
      if(ir>sct+1)
      {
        daughter->add(1,ir-sct-1,k);
      }
      pushup();
      return;
    }
    else if(ir<=sct)
    {
      son->add(il,ir,k);
      pushup();
      return;
    }
    else
    {
      daughter->add(il,ir,k);
      pushup();
      return;
    }
  }
  else
  {
    if(ir==cnt)
    {
      lazy+=k;
      key+=k;
      val+=cnt*k;
      return;
    }
    else
    {
      if(son)
      {
        if(son->cnt>=ir)
        {
          son->add(1,ir,k);
          pushup();
          return;
        }
        else
        {
          ir-=son->cnt;
          son->add(1,son->cnt,k);
        }
      }
      if(ir==1)
      {
        key+=k;
        pushup();
        return;
      }
      --ir;
      daughter->add(1,ir,k);
      pushup();
      return;
    }
  }
}
int node::sum(int x)
{
  if(x==cnt)
  {
    return val;
  }
  if(lazy)
  {
    pushdown();
  }
  register int ret=0;
  if(son)
  {
    if(son->cnt>=x)
    {
      return son->sum(x);
    }
    else
    {
      ret+=son->val;
      x-=son->cnt;
    }
  }
  if(x==1)
  {
    return ret+key;
  }
  --x;
  return ret+daughter->sum(x);
}
inline void node::pushup()
{
  cnt=1;val=key;
  if(son)
  {
    cnt+=son->cnt;
    val+=son->val;
  }
  if(daughter)
  {
    cnt+=daughter->cnt;
    val+=daughter->val;
  }
  return;
}
inline void node::pushdown()
{
  if(son)
  {
    son->lazy+=lazy;
    son->key+=lazy;
    son->val+=son->cnt*lazy;
  }
  if(daughter)
  {
    daughter->lazy+=lazy;
    daughter->key+=lazy;
    daughter->val+=daughter->cnt*lazy;
  }
  lazy=0;
  return;
}
void node::insert(const int &x,const int &k)
{
  if(!cnt)
  {
    cnt=1;key=val=k;
    return;
  }
  if(lazy)
  {
    pushdown();
  }
  if(son)
  {
    if(son->cnt+1>=x)
    {
      son->insert(x,k);
    }
    else
    {
      daughter->insert(x-son->cnt-1,k);
    }
  }
  else
  {
    if(x==1)
    {
      son=mtp++;
      son->insert(1,k);
    }
    else
    {
      daughter->insert(x-1,k);
    }
  }
  pushup();
  return;
}
inline node::node()
{
  key=val=cnt=lazy=0;
  son=daughter=NULL;
  return;
}
inline void _write(const int &x)
{
  if(x<0)
  {
    putchar('-');
    write(-x);
  }
  else
  {
    write(x);
  }
  putchar(' ');
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
  register bool bo=false;
  for(x=0;c<'0'||c>'9';c=getchar())
  {
    if(c=='-')
    {
      bo=true;
    }
  }
  for(;c>='0'&&c<='9';c=getchar())
  {
    x=(x<<1)+(x<<3)+(c^48);
  }
  if(bo)
  {
    x=~x+1;
  }
  return;
}