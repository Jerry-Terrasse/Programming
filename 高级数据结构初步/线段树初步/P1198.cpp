#include<iostream>
#define MAXN 200010
using namespace std;
struct node
{
  int l,r,mid,val;
  node *son,*daughter;
  int build(int,int);
  int add(int,int,int);
  int que(int,int);
  inline void pud();
}*head;
int m=0,p=0,cnt=0;
int main()
{
  int i=0,t=0,x=0;
  char c='\0';
  ios::sync_with_stdio(0);
  head=new node;
  head->build(1,MAXN);
  cin>>m>>p;
  for(;m--;)
  {
  	cin>>c>>x;
  	if(c=='Q')
  	{
  	  t=head->que(cnt+1-x,cnt);
  	  cout<<t<<endl;
	}
	else
	{
	  x+=t;
	  x%=p;
	  cnt++;
	  head->add(cnt,cnt,x);
	}
  }
  return 0;
}
int node::que(int il,int ir)
{
  if(il==l && ir==r)
  {
  	return val;
  }
  if(il>mid)
  {
  	return daughter->que(il,ir);
  }
  if(ir<=mid)
  {
  	return son->que(il,ir);
  }
  return max(son->que(il,mid),daughter->que(mid+1,ir));
}
int node::add(int il,int ir,int dl)
{
  if(il==l && ir==r)
  {
  	return val=dl;
  }
  if(ir<=mid)
  {
  	return val=max(son->add(il,ir,dl),daughter->val);
  }
  if(il>mid)
  {
  	return val=max(son->val,daughter->add(il,ir,dl));
  }
  return val=max(son->add(il,mid,dl),daughter->add(mid+1,ir,dl));
}
int node::build(int il,int ir)
{
  l=il;r=ir;mid=(l+r)>>1;
  son=daughter=NULL;
  if(l==r)
  {
  	val=0;
  	return 0;
  }
  son=new node;
  daughter=new node;
  return val=max(daughter->build(mid+1,r),son->build(l,mid));
}
