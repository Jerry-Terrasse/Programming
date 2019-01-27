#include<iostream>
#define MAXN 100010
using namespace std;
struct node
{
  int l,r,mid,;
  long long val,atag,ptag;
  node *son,*daughter;
  long long build(int,int);
  long long add(int,int,int);
  long long pro(int,int,int);
}*head;
long long n=0,m=0,p=0;
int main()
{
  int i=0;
  ios::sync_with_stdio(0);
  head=new node;
  cin>>n>>m>>p;
  head->build(1,n);
  
  return 0;
}
long long node::add(int il,int ir,int a)
{
  
  if(mid>=ir)
  {
  	
  }
}
long long node::build(int il,int ir)
{
  l=il;r=ir;mid=(l+r)>>1;
  if(l==r)
  {
  	cin>>val;
  	return val;
  }
  else
  {
    son=new node;daughter=new node;
	return val=son->build(l,mid)+daughter->build(mid+1,r);
  }
}
