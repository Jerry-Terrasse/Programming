#include<iostream>
#define MAXT 100010
using namespace std;
#define int long long
struct node
{
  int l,r,mid,val,vev,tag;
  node *son,*daughter;
  int bud(int,int);
  int add(int,int,int);
  int que(int,int);
  int qev(int,int);
  int change(int,int,int);
  void pud();
}*head;
int t=0;
#undef int
int main()
#define int long long
{
  int i=0,x=0,y=0,z=0;
  char o='\0';
  cin>>t;
  head=new node;
  head->bud(1,t);
  for(cin>>i;i;i--)
  {
  	cin>>o>>x>>y;
  	switch(o)
  	{
  	  case 'Q':
  	  	cout<<head->que(x,y)<<endl;
  	    break;
  	  case 'A':
  	  	cout<<head->qev(x,y)<<endl;
  	    break;
  	  case 'P':
  	  	cin>>z;
  	  	head->add(x,y,z);
  	    break;
  	  case 'C':
  	  	cin>>z;
  	  	head->change(x,y,z);
  	    break;
	}
  }
  return 0;
}
int node::bud(int il,int ir)
{
  l=il;r=ir;mid=(l+r)>>1;tag=0;
  if(l==r)
  {
  	cin>>val;
  	return vev=val;
  }
  son=new node;
  daughter=new node;
  return vev=val=max(daughter->bud(mid+1,r),son->bud(l,mid));
}
int node::que(int il,int ir)
{
  if(il==l && ir==r)
  {
  	return val;
  }
  if(tag)
  {
  	pud();
  }
  if(ir<=mid)
  {
  	return son->que(il,ir);
  }
  if(il>mid)
  {
  	return daughter->que(il,ir);
  }
  return max(son->que(il,mid),daughter->que(mid+1,ir));
}
void node::pud()
{
  son->add(l,mid,tag);
  daughter->add(mid+1,r,tag);
  tag=0;
  return;
}
int node::add(int il,int ir,int a)
{
  if(il==l && ir==r)
  {
  	val+=a;
  	vev=max(val,vev);
  	tag+=a;
  	return val;
  }
  if(tag)
  {
  	pud();
  }
  if(ir<=mid)
  {
  	val=max(son->add(il,ir,a),daughter->val);
  	vev=max(vev,val);
  	return val;
  }
  if(il>mid)
  {
  	val=max(daughter->add(il,ir,a),son->val);
  	vev=max(val,vev);
  	return val;
  }
  val=max(son->add(il,mid,a),daughter->add(mid+1,ir,a));
  vev=max(vev,val);
  return val;
}
int node::qev(int il,int ir)
{
  //cout<<il<<' '<<ir<<endl;
  if(il==l && ir==r)
  {
  	return vev;
  }
  if(tag)
  {
  	pud();
  }
  if(ir<=mid)
  {
  	return son->qev(il,ir);
  }
  if(il>mid)
  {
  	return daughter->qev(il,ir);
  }
  return max(son->qev(il,mid),daughter->qev(mid+1,ir));
}
int node::change(int il,int ir,int a)
{
  if(l==r)
  {
  	val=a;
  	vev=max(vev,val);
  	return val;
  }
  if(tag)
  {
  	pud();
  }
  if(ir<=mid)
  {
  	val=max(son->change(il,ir,a),daughter->val);
  	vev=max(val,vev);
  	return val;
  }
  if(il>mid)
  {
  	val=max(daughter->change(il,ir,a),son->val);
  	vev=max(val,vev);
  	return val;
  }
  val=max(son->change(il,mid,a),daughter->change(mid+1,ir,a));
  vev=max(vev,val);
  return val;
}
