#include<iostream>
#define ll long long
using namespace std;
struct node
{
  ll l,r,mid,val,atag,ptag;
  node *son,*daughter;
  ll build(ll,ll);
  ll add(ll,ll,ll);
  ll pro(ll,ll,ll);
  ll sum(ll,ll);
  void pd();
}*head;
int n=0,m=0,p=0;
int main()
{
  int i=0,x=0,y=0,o=0;
  ios::sync_with_stdio(0);
  head=new node;
  cin>>n>>m>>p;
  head->build(1,n);
  for(;i<m;i++)
  {
  	cin>>o>>x>>y;
  	switch(o)
  	{
  	  case 1:
  	  	cin>>o;
  	  	head->pro(x,y,o); 
  	  	break;
  	  case 2:
  	  	cin>>o;
  	  	head->add(x,y,o);
  	  	break;
  	  case 3:
  	  	cout<<head->sum(x,y)<<endl;
  	  	break;
	}
  }
  return 0;
}
ll node::build(ll il,ll ir)
{
  l=il;r=ir;mid=(l+r)>>1;atag=0;ptag=1;
  if(l==r)
  {
  	cin>>val;
  	return val;
  }
  son=new node;daughter=new node;
  val=son->build(l,mid);
  val+=daughter->build(mid+1,r);
  return val%=p;
}
void node::pd()
{
  if(atag)
  {
  	son->add(l,mid,atag);
  	daughter->add(mid+1,r,atag);
  	atag=0;
  }
  if(ptag-1)
  {
  	son->pro(l,mid,ptag);
  	daughter->pro(mid+1,r,ptag);
  	ptag=1;
  }
  return;
}
ll node::sum(ll il,ll ir)
{
  if(l!=r)pd();
  if(il==l && ir==r)
  {
  	return val;
  }
  if(ir<=mid)
  {
  	return son->sum(il,ir);
  }
  if(il>=mid+1)
  {
  	return daughter->sum(il,ir);
  }
  return (son->sum(il,mid)+daughter->sum(mid+1,ir))%p;
}
ll node::add(ll il,ll ir,ll a)
{
  if(l!=r)pd();
  if(il==l && ir==r)
  {
  	val+=(r+1-l)*a;
  	atag=a;
  	return val%=p;
  }
  if(ir<=mid)
  {
  	val=son->add(il,ir,a);
  	val+=daughter->val;
  	return val%=p;
  }
  if(il>=mid+1)
  {
  	val=daughter->add(il,ir,a);
  	val+=son->val;
  	return val%=p;
  }
  val=son->add(il,mid,a);
  val+=daughter->add(mid+1,ir,a);
  return val%=p;
}
ll node::pro(ll il,ll ir,ll k)
{
  if(l!=r)pd();
  if(il==l && ir==r)
  {
  	val*=k;
  	ptag=k;
  	return val%=p;
  }
  if(ir<=mid)
  {
  	val=son->pro(il,ir,k);
  	val+=daughter->val;
  	return val%=p;
  }
  if(il>=mid+1)
  {
  	val=daughter->pro(il,ir,k);
  	val+=son->val;
  	return val%=p;
  }
  val=son->pro(il,mid,k);
  val+=daughter->pro(mid+1,ir,k);
  return val%=p;
}
