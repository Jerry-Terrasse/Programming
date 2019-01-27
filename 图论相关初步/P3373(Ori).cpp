#include<iostream>
#define MAXN 400040//100010*4
using namespace std;
int n=0,m=0,p=0;
struct node
{
  int l,r,val,mid,ptag,atag;
}st[MAXN];//Segment Tree
int build(int,int,int);
int add(int,int,int,int);
int pro(int,int,int,int);
int sum(int,int,int);
int main()
{
  int i=0,a=0,x=0,y=0;
  cin>>n>>m>>p;
  build(1,1,n);
  for(i=1;i<=m;i++)
  {
  	cin>>a>>x>>y;
  	if(a==1)
  	{
  	  cin>>a;
  	  pro(1,x,y,a);
	  continue;
	}
	if(a==2)
	{
	  cin>>a;
	  add(1,x,y,a);
	  continue;
	}
	if(a==3)
	{
	  cout<<sum(1,x,y)%p<<endl;
	  continue;
	}
  }
  return 0;
}
int sum(int k,int l,int r)
{
  if(st[k].l==l && st[k].r==r)
  {
  	return st[k].val;
  }
  pro(k<<1,st[k].l,st[k].mid,st[k].ptag);
  pro(k<<1|1,st[k].mid+1,st[k].r,st[k].ptag);
  st[k].ptag=1;
  add(k<<1,st[k].l,st[k].mid,st[k].atag);
  add(k<<1|1,st[k].mid+1,st[k].r,st[k].atag);
  st[k].atag=0;
  if(l>st[k].mid)
  {
  	return sum(k<<1|1,l,r);
  }
  if(r<=st[k].mid)
  {
  	return sum(k<<1,l,r);
  }
  return sum(k<<1,l,st[k].mid)+sum(k<<1|1,st[k].mid+1,r);
}
int pro(int k,int l,int r,int a)
{
  if(st[k].l==st[k].r)
  {
  	return st[k].val*=a;
  }
  pro(k<<1,st[k].l,st[k].mid,st[k].ptag);
  pro(k<<1|1,st[k].mid+1,st[k].r,st[k].ptag);
  st[k].ptag=1;
  add(k<<1,st[k].l,st[k].mid,st[k].atag);
  add(k<<1|1,st[k].mid+1,st[k].r,st[k].atag);
  st[k].atag=0;
  if(st[k].l==l && st[k].r==r)
  {
  	st[k].ptag*=a;
  	return st[k].val*=a;
  }
  if(l<=st[k].mid)
  {
  	pro(k<<1,l,st[k].mid,a);
  }
  if(r>st[k].mid)
  {
  	pro(k<<1|1,st[k].mid+1,r,a);
  }
  return st[k].val=st[k<<1].val+st[k<<1|1].val;
}
int add(int k,int l,int r,int a)
{
  if(st[k].l==st[k].r)
  {
  	return st[k].val+=a;
  }
  pro(k<<1,st[k].l,st[k].mid,st[k].ptag);
  pro(k<<1|1,st[k].mid+1,st[k].r,st[k].ptag);
  st[k].ptag=1;
  add(k<<1,st[k].l,st[k].mid,st[k].atag);
  add(k<<1|1,st[k].mid+1,st[k].r,st[k].atag);
  st[k].atag=0;
  if(st[k].l==l && st[k].r==r)
  {
  	st[k].atag+=a;
  	return st[k].val+=(r+1-l)*a;
  }
  if(l<=st[k].mid)
  {
  	add(k<<1,l,st[k].mid,a);
  }
  if(r>st[k].mid)
  {
  	add(k<<1|1,st[k].mid+1,r,a);
  }
  return st[k].val=st[k<<1].val+st[k<<1|1].val;
}
int build(int k,int l,int r)
{
  st[k].l=l;st[k].r=r;st[k].mid=(l+r)>>1;
  st[k].atag=0;st[k].ptag=1;
  if(l==r)
  {
  	cin>>st[k].val;
  	return st[k].val;
  }
  return st[k].val=build(k<<1,l,st[k].mid)+build(k<<1|1,st[k].mid+1,r);
}
