// luogu-judger-enable-o2
#include<iostream>
//#define hey cout<<'{';head->echo(1,n);cout<<'}'<<endl;
//#define hey head->check();
//#define hey ;
using namespace std;
struct node
{
  node *son,*daughter;
  long long l,r,mid,val,lazy;
  long long build(int,int);
  long long add(int,int,int);
  long long sum(int,int);
  void echo(int,int);
  void check();
}*head;
long long n=0,m=0;
int main()
{
  long long i=0,x=0,y=0,k=0;
  head=new node;
  cin>>n>>m;
  head->build(1,n);
  //hey
  for(i=1;i<=m;i++)
  {
  	cin>>x;
  	if(x&1)
  	{
  	  cin>>x>>y>>k;
  	  head->add(x,y,k);
  	  //hey
    }
    else
    {
      cin>>x>>y;
      cout<<head->sum(x,y)<<endl;
      //hey
    }
  }
  //hey
  return 0;
}
long long node::build(int bl,int br)
{
  lazy=0;
  l=bl;
  r=br;
  if(bl==br)
  {
    mid=br;
    son=daughter=NULL;
    cin>>val;
    return val;
  }
  mid=(l+r)>>1;
  son=new node;
  daughter=new node;
  return val=son->build(l,mid)+daughter->build(mid+1,r);
}
long long node::add(int bl,int br,int k)
{
  if(bl==l && br==r)
  {
    lazy+=k;
    return val+=k*(r+1-l);
  }
  if(lazy)
  {
  	son->add(l,mid,lazy);daughter->add(mid+1,r,lazy);
  	lazy=0;
  }
  if(br<=mid)
  {
  	return val=son->add(bl,br,k)+daughter->val;
  }
  if(bl>=mid+1)
  {
  	return val=daughter->add(bl,br,k)+son->val;
  }
  return val=son->add(bl,mid,k)+daughter->add(mid+1,br,k);
}
long long node::sum(int bl,int br)
{
  if(bl==l && br==r)
  {
    return val;
  }
  if(lazy)
  {
  	son->add(l,mid,lazy);daughter->add(mid+1,r,lazy);
  	lazy=0;
  }
  if(br<=mid)
  {
  	return son->sum(bl,br);
  }
  if(bl>=mid+1)
  {
  	return daughter->sum(bl,br);
  }
  return son->sum(bl,mid)+daughter->sum(mid+1,br);
}
void node::echo(int bl,int br)
{
  if(bl==br)
  {
    cout<<val<<' ';
    return;
  }
  son->echo(l,mid);daughter->echo(mid+1,r);
  return;
}
void node::check()
{
  for(int i=1;i<=n;i++)
  {
  	head->sum(i,i);
  }
  //cout<<'{';head->echo(1,n);cout<<'}'<<endl;
  return;
}
