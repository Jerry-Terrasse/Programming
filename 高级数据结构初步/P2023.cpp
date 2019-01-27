#include<iostream>
#define ll long long
using namespace std;
struct node
{
  ll l,r,mid,val,atag,ptag;
  node *son,*daughter;
  ll bud(ll,ll);
  ll sum(ll,ll);
  ll add(ll,ll,ll);
  ll pro(ll,ll,ll);
  inline void pud();
}*head;
ll n=0,m=0,p=0;
int main()
{
  ll o=0,t=0,g=0;
  head=new node;
  cin>>n>>p;
  head->bud(1,n);
  for(cin>>m;m--;)
  {
  	cin>>o>>t>>g;
  	switch(o)
  	{
  	  case 1:
  	  	cin>>o;
  	  	head->pro(t,g,o);
  	  	break;
  	  case 2:
  	  	cin>>o;
  	  	head->add(t,g,o);
  	  	break;
  	  case 3:
  	  	cout<<head->sum(t,g)<<endl;
  	  	break;
	}
  }
  return 0;
}
ll node::add(ll il,ll ir,ll a)
{
  if(l==il && r==ir)
  {
  	atag+=a;
  	atag%=p;
  	val+=(r+1-l)*a;
  	return val%=p;
  }
  if(atag || ptag!=1)
  {
  	pud();
  }
  if(ir<=mid)
  {
  	val=son->add(il,ir,a)+daughter->val;
  	return val%=p;
  }
  if(il>mid)
  {
  	val=daughter->add(il,ir,a)+son->val;
  	return val%=p;
  }
  val=son->add(il,mid,a)+daughter->add(mid+1,ir,a);
  return val%=p;
}
ll node::bud(ll il,ll ir)
{
  l=il;r=ir;mid=(l+r)>>1;val=atag=0;ptag=1;
  son=daughter=NULL;
  if(l==r)
  {
  	cin>>val;
  	return val%=p;
  }
  son=new node;
  daughter=new node;
  val=son->bud(l,mid)+daughter->bud(mid+1,r);
  return val%=p;
}
ll node::pro(ll il,ll ir,ll a)
{
  if(l==il && r==ir)
  {
  	ptag*=a;
  	ptag%=p;
  	atag*=a;
  	atag%=p;
  	val*=a;
  	return val%=p;
  }
  if(atag || ptag!=1)
  {
  	pud();
  }
  if(ir<=mid)
  {
  	val=son->pro(il,ir,a)+daughter->val;
  	return val%=p;
  }
  if(il>mid)
  {
  	val=daughter->pro(il,ir,a)+son->val;
  	return val%=p;
  }
  val=son->pro(il,mid,a)+daughter->pro(mid+1,ir,a);
  return val%=p;
}
inline void node::pud()
{
  son->ptag*=ptag;
  son->ptag%=p;
  son->atag*=ptag;
  son->atag%=p;
  son->atag+=atag;
  son->atag%=p;
  son->val*=ptag;
  son->val%=p;
  son->val+=(son->r+1-son->l)*atag;
  son->val%=p;
  daughter->ptag*=ptag;
  daughter->ptag%=p;
  daughter->atag*=ptag;
  daughter->atag%=p;
  daughter->atag+=atag;
  daughter->atag%=p;
  daughter->val*=ptag;
  daughter->val%=p;
  daughter->val+=(daughter->r+1-daughter->l)*atag;
  daughter->val%=p;
  atag=0;
  ptag=1;
  return;
}
ll node::sum(ll il,ll ir)
{
  if(il==l && ir==r)
  {
  	return val;
  }
  if(atag || ptag!=1)
  {
  	pud();
  }
  if(ir<=mid)
  {
  	return son->sum(il,ir);
  }
  if(il>mid)
  {
  	return daughter->sum(il,ir);
  }
  /*int kkk=son->sum(il,mid);
  kkk+=daughter->sum(mid+1,ir);
  return kkk%p;*/
  return (son->sum(il,mid)+daughter->sum(mid+1,ir))%p;
}
