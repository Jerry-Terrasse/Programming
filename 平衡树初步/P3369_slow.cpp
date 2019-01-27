// P3369 【模板】普通平衡树
//just BST
#include<iostream>
#define MAXN 100010
#define INF 0x3f3f3f3f
using namespace std;
struct bst
{
  int val,cnt,siz;
  bst *son,*daughter;
  inline bst();
  void insert(const int&);
  void remove(const int&);
  inline void pushup();
  int getrank(const int&);
  int getval(int);
  int getpre(const int&);
  int getnxt(const int&);
}mmp[MAXN],*head=NULL,*mtp=mmp+1;
int n=0;
inline bst* newbst(const int&);
int main()
{
  register int o=0,x=0;
  ios::sync_with_stdio(false);cin.tie(0);
  head=newbst(INF);
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
      daughter=newbst(x);
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
      son=newbst(x);
    }
  }
  else
  {
    ++cnt;
  }
  pushup();
  return;
}
inline bst* newbst(const int &x)
{
  mtp->val=x;
  mtp->cnt=mtp->siz=1;
  return mtp++;
}
inline bst::bst()
{
  val=cnt=siz=0;
  son=daughter=mmp;
  return;
}