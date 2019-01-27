#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 16
using namespace std;
struct node
{
  char val;
  node *son,*daughter;
  void build(const int&,const int&,const int&,const int&);
  void output();
}mmp[MAXN],*head;
int len=0,cnt=0;
char a[MAXN],b[MAXN];
int main()
{
  int i=0;
  cin>>a>>b;
  len=strlen(a);
  head=++cnt+mmp;
  head->build(0,len,0,len);
  head->output();
  putchar('\n');
  return 0;
}
void node::output()
{
  putchar(val);
  if(son)
  {
  	son->output();
  }
  if(daughter)
  {
  	daughter->output();
  }
  return;
}
void node::build(const int &il,const int &ir,const int &li,const int &ri)
{
  val=b[ri-1];son=daughter=NULL;
  if(li+1==ri)
  {
  	return;
  }
  int i=0,j=0;
  for(i=il;a[i]!=val;++i);
  j=i-il+li;
  if(il<i)
  {
    son=++cnt+mmp;
  	son->build(il,i,li,j);
  }
  if(i+1<ir)
  {
    daughter=++cnt+mmp;
  	daughter->build(i+1,ir,j,ri-1);
  }
  return;
}
