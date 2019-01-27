#include<iostream>
#define MAXN 1000010
#define MAXA 70070
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
struct node
{
  int val[2],l,r,mid,lazy,lst,cnt;
  node *son,*daughter;
  int build(int,int);
  int change(int,int);
  int set(int,int,int);
  int que(int,int,int);
  void output();
}*head;
int outer[MAXA*3+3],n=0,m=0,ans=0,ccnt=0;
bool bo=false;
char c='\0';
inline void out(int,int);
int main()
{
  int u=0,v=0;
  char ou='\0',ov='\0';
  ios::sync_with_stdio(0);
  head=new node;
  head->build(1,MAXA*3);
  for(;cin>>c;)
  {
  	if(c==EOF)
  	{
  	  break;
	}
	if(c<'A'||c>'Z')
  	{
  	  continue;
	}
	cin>>ou>>u>>ov>>v>>ov;
	u*=3;v*=3;
	if(ou=='(')
	{
	  ++u;
	}
	if(ov==')')
	{
	  --v;
	}
	switch(c)
	{
	  case 'U':
	  	head->set(u,v,1);
	  	break;
	  case 'I':
	  	head->set(1,u-1,0);
	  	head->set(v+1,MAXA*3,0);
	  	break;
	  case 'D':
	  	head->set(u,v,0);
	  	break;
	  case 'C':
	  	head->set(1,u-1,0);
	  	head->set(v+1,MAXA*3,0);
	  	head->change(u,v);
	  	break;
	  case 'S':
	  	head->change(u,v);
	  	break;
	  default:
	  	for(int rp=0;19260817;++rp);
	}
  }
  head->output();
  for(u=1;u<=MAXA*3;++u)
  {
  	if(outer[u])
  	{
  	  for(v=u+1;outer[v];++v);
  	  out(u,v-1);
  	  u=v-1;
	}
  }
  if(!bo)
  {
  	cout<<"empty set"<<endl;
  }
  return 0;
}
void node::output()
{
  if(l==r)
  {
  	if(lst==2)
  	{
  	  outer[++ccnt]=1;
	}
	else if(lst==1)
	{
	  outer[++ccnt]=0;
	}
	else
	{
	  outer[++ccnt]=val[lazy^1];
	}
  }
  else
  {
  	son->output();
  	daughter->output();
  }
  return;
}
inline void out(int u,int v)
{
  bo=true;
  if(u%3)
  {
  	cout<<'(';
  }
  else
  {
  	cout<<'[';
  }
  cout<<u/3<<',';
  if(v%3)
  {
  	cout<<v/3+1<<')';
  }
  else
  {
  	cout<<v/3<<']';
  }
  return;
}
int node::que(int il,int ir,int o)
{
  if(il==l&&ir==r)
  {
  	return val[lazy^o];
  }
  else
  {
  	if(ir<=mid)
  	{
  	  return son->que(il,ir,o^lazy);
	}
	if(il>mid)
	{
	  return daughter->que(il,ir,o^lazy);
	}
	return son->que(il,mid,o^lazy)+daughter->que(mid+1,ir,o^lazy);
  }
}
int node::set(int il,int ir,int o)
{
  if(il==l&&ir==r)
  {
  	lst=o+1;
  	lazy=0;
  	if(o)
  	{
  	  val[1]=cnt;
	  return val[0]=0;
	}
	else
	{
	  val[0]=0;
	  return val[0]=cnt;
	}
  }
  if(lst)
  {
  	val[0]=son->set(l,mid,lst-1)+daughter->set(mid+1,r,lst-1);
  	val[1]=r-l+1-val[0];
  	lst=0;
  }
  if(lazy)
  {
  	val[0]=son->change(l,mid)+daughter->change(mid+1,r);
  	val[1]=r-l+1-val[0];
    lazy=0;
  }
  if(mid>=ir)
  {
  	val[0]=son->set(il,ir,o)+daughter->val[daughter->lazy];
  	val[1]=r-l+1-val[0];
  	return val[0];
  }
  if(mid<il)
  {
  	val[0]=son->val[son->lazy]+daughter->set(il,ir,o);
  	val[1]=r-l+1-val[0];
  	return val[0];
  }
  val[0]=son->set(il,mid,o)+daughter->set(mid+1,ir,o);
  val[1]=r-l+1-val[0];
  return val[0];
}
int node::change(int il,int ir)
{
  if(il==l&&ir==r)
  {
  	if(lst)
	{
	  lst^=3;
	  val[0]^=val[1];val[1]^=val[0];val[0]^=val[1];
	}
	else
	{
	  lazy^=1;
	  val[0]^=val[1];val[1]^=val[0];val[0]^=val[1];
	}
  	return val[lazy];
  }
  if(lst)
  {
  	val[0]=son->set(il,mid,lst-1)+daughter->set(mid+1,ir,lst-1);
  	val[1]=r-l+1-val[0];
  	lst=0;
  }
  if(lazy)
  {
  	val[0]=son->change(l,mid)+daughter->change(mid+1,r);
  	val[1]=r-l+1-val[0];
    lazy=0;
  }
  if(mid>=ir)
  {
  	val[0]=son->change(il,ir)+daughter->val[daughter->lazy];
  	val[1]=r-l+1-val[0];
  	return val[0];
  }
  if(mid<il)
  {
  	val[0]=son->val[son->lazy]+daughter->change(il,ir);
  	val[1]=r-l+1-val[0];
  	return val[0];
  }
  val[0]=son->change(il,mid)+daughter->change(mid+1,ir);
  val[1]=r-l+1-val[0];
  return val[0];
}
int node::build(int il,int ir)
{
  if(il==ir)
  {
  	l=r=mid=il;lst=lazy=0;cnt=1;
  	val[1]=0;
  	return val[0]=1;
  }
  l=il;r=ir;mid=l+r>>1;lst=lazy=0;
  son=new node;daughter=new node;
  val[0]=son->build(l,mid)+daughter->build(mid+1,r);
  cnt=son->cnt+daughter->cnt;
  val[1]=r-l+1-val[0];
  return val[0];
}
