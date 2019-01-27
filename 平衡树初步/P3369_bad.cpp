// P3369 【模板】普通平衡树
//Treap
#include<iostream>
#include<ctime>
#include<cstdlib>
#define MAXN 100010
#define INF 0x3f3f3f3f
using namespace std;
struct bst
{
  int val,cnt,siz,key;
  bst *son,*daughter,*father;
  inline bst();
  void insert(const int&);
  void remove(const int&);
  inline void pushup();
  int getrank(const int&);
  int getval(int);
  int getpre(const int&);
  int getnxt(const int&);
  inline void zig();
  inline void zag();
}mmp[MAXN],*head=NULL,*mtp=mmp+1;
int n=0;
inline bst* newbst(const int&,bst*);
int main()
{
  register int o=0,x=0;
  //srand(time(NULL));
  ios::sync_with_stdio(false);cin.tie(0);
  head=newbst(INF,mmp);
  head->key=INF;
  head->insert(-INF);
  head->cnt=head->siz=0;
  head->son->cnt=head->son->siz=0;
  cin>>n;
  for(;n--;)
  {
    cin>>o>>x;
    switch(o)
    {
      case 1:
        head->insert(x);
        break;
      case 2:
        head->remove(x);
        break;
      case 3:
        cout<<head->getrank(x)<<endl;
        break;
      case 4:
        cout<<head->getval(x)<<endl;
        break;
      case 5:
        cout<<head->getpre(x)<<endl;
        break;
      case 6:
        cout<<head->getnxt(x)<<endl;
        break;
    }
  }
  return 0;
}
inline void bst::zag()
{
  daughter->father=father;
  father->daughter=daughter;
  father=daughter;
  daughter=daughter->son;
  father->son=this;
  daughter->father=this;
  pushup();father->pushup();
  return;
}
inline void bst::zig()
{
  son->father=father;
  father->son=son;
  father=son;
  son=son->daughter;
  father->daughter=this;
  son->father=this;
  pushup();father->pushup();
  return;
}
int bst::getnxt(const int &x)
{
  if(val<=x)
  {
    if(daughter!=mmp)
    {
      return daughter->getnxt(x);
    }
    else
    {
      return INF;
    }
  }
  else
  {
    register int ret=INF;
    if(son!=mmp)
    {
      ret=son->getnxt(x);
      if(ret<INF)
      {
        return ret;
      }
    }
    if(cnt)
    {
      return val;
    }
    if(daughter!=mmp)
    {
      return daughter->getnxt(x);
    }
    return INF;
  }
}
int bst::getpre(const int &x)
{
  if(val>=x)
  {
    if(son!=mmp)
    {
      return son->getpre(x);
    }
    else
    {
      return -INF;
    }
  }
  else
  {
    register int ret=-INF;
    if(daughter!=mmp)
    {
      ret=daughter->getpre(x);
      if(ret>-INF)
      {
        return ret;
      }
    }
    if(cnt)
    {
      return val;
    }
    if(son!=mmp)
    {
      return son->getpre(x);
    }
    return -INF;
  }
}
int bst::getval(int x)
{
  if(son->siz>=x)
  {
    return son->getval(x);
  }
  x-=son->siz;
  if(x>cnt)
  {
    return daughter->getval(x-cnt);
  }
  return val;
}
int bst::getrank(const int &x)
{
  if(val<x)
  {
    return son->siz+cnt+daughter->getrank(x);
  }
  if(val>x)
  {
    return son->getrank(x);
  }
  return son->siz+1;
}
inline void bst::pushup()
{
  siz=son->siz+daughter->siz+cnt;
  return;
}
void bst::remove(const int &x)
{
  if(val<x)
  {
    daughter->remove(x);
  }
  else if(val>x)
  {
    son->remove(x);
  }
  else
  {
    --cnt;
  }
  pushup();
  return;
}
void bst::insert(const int &x)
{
  if(val<x)
  {
    if(daughter!=mmp)
    {
      daughter->insert(x);
    }
    else
    {
      daughter=newbst(x,this);
    }
    if(daughter->key>key)
    {
      zag();
    }
  }
  else if(val>x)
  {
    if(son!=mmp)
    {
      son->insert(x);
    }
    else
    {
      son=newbst(x,this);
    }
    if(son->key>key)
    {
      zig();
    }
  }
  else
  {
    ++cnt;
  }
  pushup();
  return;
}
inline bst* newbst(const int &x,bst *fa)
{
  mtp->val=x;
  mtp->cnt=mtp->siz=1;
  mtp->key=rand();
  mtp->father=fa;
  return mtp++;
}
inline bst::bst()
{
  val=cnt=siz=key=0;
  son=daughter=father=mmp;
  return;
}