#include<cstdio>
#define MAXN 1000010
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
struct node
{
  int val[2],l,r,mid,lazy,cnt;
  node *son,*daughter;
  int build(int,int);
  int change(int,int);
  int que(int,int,int);
}*head;
int n=0,m=0,ans=0;
char c='\0';
inline void read(int&);
void write(const  int&);
int main()
{
  int i=0,u=0,v=0,aans;
  read(n);read(m);
  head=new node;
  head->build(1,n);
  for(;m--;)
  {
  	for(c=getchar();c!='c'&&c!='s';c=getchar());
  	if(c=='s')
  	{
  	  read(u);read(v);
	  head->change(u,v);
	}
	else
	{
	  ans=head->que(1,n,1);
	  for(i=1;i<n;++i)
	  {
	  	aans=0;
	  	aans=head->que(1,i,0);
	  	aans+=head->que(i+1,n,1);
	  	ans=max(ans,aans);
	  }
	  aans=head->que(1,n,0);
	  ans=max(ans,aans);
	  write(ans);
	  putchar('\n');
	}
  }
  return 0;
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
int node::change(int il,int ir)
{
  if(il==l&&ir==r)
  {
  	lazy^=1;
  	return val[lazy];
  }
  if(lazy)
  {
  	son->change(l,mid);
    daughter->change(mid+1,r);
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
  	l=r=mid=il;lazy=0;cnt=1;
  	for(c=getchar();c!='4'&&c!='7';c=getchar());
  	val[1]=(c=='7');
  	return val[0]=val[1]^1;
  }
  l=il;r=ir;mid=l+r>>1;lazy=0;
  son=new node;daughter=new node;
  val[0]=son->build(l,mid)+daughter->build(mid+1,r);
  cnt=son->cnt+daughter->cnt;
  val[1]=r-l+1-val[0];
  return val[0];
}
inline void read(int &x)
{
  for(x=0,c=getchar();c<'0'||c>'9';c=getchar());
  for(;c>='0'&&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)-'0'+c;
  }
  return;
}
void write(const int &x)
{
  if(x>9)
  {
  	write(x/10);
  }
  putchar(x%10+'0');
  return;
}
