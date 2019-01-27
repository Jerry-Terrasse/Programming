#include<iostream>
using namespace std;
struct node
{
  int l,r,mid,lft,tag;
  node *son,*daughter;
  int build(int,int);
  int add(int,int,int);
  inline void pud();
}*head;
int n=0,m=0;
inline int min(const int&,const int&);
int main()
{
  int i=0,d=0,s=0,t=0;
  ios::sync_with_stdio(0);
  head=new node;
  cin>>n>>m;
  head->build(1,n);
  for(;i<m;i++)
  {
  	cin>>d>>s>>t;
  	if(head->add(s,t,-d)<0)
  	{
  	  cout<<-1<<endl;
  	  cout<<i+1<<endl;
  	  return 0;
	}
  }
  cout<<0<<endl;
  return 0;
}
inline int min(const int &a,const int &b)
{
  return a>b?b:a;
}
inline void node::pud()
{
  son->tag+=tag;
  son->lft+=tag;
  daughter->tag+=tag;
  daughter->lft+=tag;
  tag=0;
  lft=min(son->lft,daughter->lft);
  return;
}
int node::add(int il,int ir,int dl)
{
  if(il==l && ir==r)
  {
  	tag+=dl;
  	return lft+=dl;
  }
  if(tag)
  {
  	pud();
  }
  if(ir<=mid)
  {
  	return lft=min(son->add(il,ir,dl),daughter->lft);
  }
  if(il>mid)
  {
  	return lft=min(son->lft,daughter->add(il,ir,dl));
  }
  return lft=min(son->add(il,mid,dl),daughter->add(mid+1,ir,dl));
}
int node::build(int il,int ir)
{
  l=il;r=ir;mid=(l+r)>>1;tag=0;
  son=daughter=NULL;
  if(l==r)
  {
  	cin>>lft;
  	return lft;
  }
  son=new node;
  daughter=new node;
  return lft=min(daughter->build(mid+1,r),son->build(l,mid));
}
