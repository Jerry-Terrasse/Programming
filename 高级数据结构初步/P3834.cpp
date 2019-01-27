#include<iostream>
#include<algorithm>
#define MAXN 200020
using namespace std;
struct node
{
  int l,r,mid,val;
  node *son,*daughter;
  void bud(int,int);
  node* add(int);
  int que(node*,int);
}*head[MAXN];
int a[MAXN],t[MAXN],n=0,cnt=1,m=0;
int main()
{
  int i=1,lll=0,rrr=0;
  head[0]=new node;
  ios::sync_with_stdio(0);
  for(cin>>n>>m;i<=n;i++)
  {
  	cin>>a[i];
  	t[i]=a[i];
  }
  sort(t+1,t+n+1);
  for(i=2;i<=n;)
  {
  	for(;t[cnt]==t[i] && i<=n;i++);
  	if(i<=n)
	{
	  t[++cnt]=t[i];
	}
  }
  cnt++;
  head[0]->bud(1,cnt);
  for(i=1;i<=n;i++)
  {
  	head[i]=head[i-1]->add(a[i]);
  }
  for(;m--;)
  {
  	cin>>lll>>rrr>>i;
  	cout<<head[rrr]->que(head[lll-1],i)<<endl;
  }
  return 0;
}
int node::que(node *p,int x)
{
  if(l==r)
  {
  	return t[mid];
  }
  if(x<=son->val-p->son->val)
  {
  	return son->que(p->son,x);
  }
  x+=p->son->val;
  x-=son->val; 
  return daughter->que(p->daughter,x);
}
node* node::add(int x)
{
  node *p=new node;
  *p=*this;
  if(l==r)
  {
  	p->val++;
  	return p;
  }
  if(x<=t[mid])
  {
  	p->son=son->add(x);
  	p->val=p->son->val+daughter->val;
  	return p;
  }
  p->daughter=daughter->add(x);
  p->val=son->val+p->daughter->val;
  return p;
}
void node::bud(int il,int ir)
{
  l=il;r=ir;mid=(l+r)>>1;val=0;
  son=daughter=NULL;
  if(l==r)
  {
  	return;
  }
  son=new node;
  daughter=new node;
  son->bud(il,mid);
  daughter->bud(mid+1,ir);
  return; 
}
