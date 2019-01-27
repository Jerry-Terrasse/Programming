#include<iostream>
#include<queue>
#define ll long long
#define MAXN 50050
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
struct node
{
  int val,l,r,mid;
  node *son,*daughter;
  int build(const int&,const int&);
  int mns(const int&);
  int find(const int&);
}*head;
ll a[MAXN],c[MAXN],st[MAXN],top=0,n=0,m=0;
int main()
{
  ll i=0,j=0;
  cin>>n>>m;
  c[2]=1;
  for(i=3;i<=n;++i)
  {
  	c[i]=c[i-1]*i/(i-2);
  }
  head=new node;
  head->build(1,n);
  for(i=1;i<=n;++i)
  {
  	j=max(m-c[n-i],0);
  	a[i]=head->find(j+1);
  	head->mns(a[i]);
  	m-=j;
  }
  for(i=1;i<=n;++i)
  {
  	cout<<a[i]<<' ';
  }
  cout<<endl;
  return 0;
}
int node::find(const int &x)
{
  if(l==r)
  {
  	return l;
  }
  if(son->val<x)
  {
  	return daughter->find(x-son->val);
  }
  return son->find(x);
}
int node::mns(const int &x)
{
  if(l==r)
  {
  	return val=0;
  }
  if(x<=mid)
  {
  	return val=son->mns(x)+daughter->val;
  }
  return val=son->val+daughter->mns(x);
}
int node::build(const int &il,const int &ir)
{
  l=il;r=ir;mid=(l+r)>>1;
  if(il==ir)
  {
  	return val=1;
  }
  son=new node;daughter=new node;
  return val=son->build(il,mid)+daughter->build(mid+1,ir);
}
