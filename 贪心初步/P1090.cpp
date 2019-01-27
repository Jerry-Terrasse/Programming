#include<cstdio>
#define MAXN 10010
using namespace std;
class node
{
  public: 
  long long val,s;
  node *next;
}*head;
long long n=0,a=0,ans=0;
void insert(long long);
int main()
{
  //freopen("P1090#2.in","r",stdin);
  long long i=0;
  head=new node;
  head->val=-1;
  head->next=new node;
  head->next->val=0x7FFFFFFFFFFFFFFF;
  scanf("%lli",&n);
  for(i=0;i<n;i++)
  {
    scanf("%lli",&a);
    insert(a);
  }
  for(;head->next->next->val!=0x7FFFFFFFFFFFFFFF;)
  {
  	a=head->next->val+head->next->next->val;
  	head->next=head->next->next->next;
  	insert(a);
  	ans+=a;
  }
  printf("%lli",ans);
  return 0;
}
void insert(long long x)
{
  node *h=head;
  for(;h->next->val<x;)
  {
  	h=h->next;
  }
  	node *p=new node;
  	p->val=x;
  	p->next=h->next;
  	h->next=p;
  return;
}
