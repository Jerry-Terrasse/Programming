#include<iostream>
#include<cmath>
#include<cstdlib>
#define ll long long
#define ld long double
#define MAXN 100010
#define min_T 1e-5
using namespace std;
struct line
{
  ll u,v;
}a[MAXN];
struct selc
{
  ll u,v,id;
  selc *next;
}*head;
ll n=0,k=0,ans=0,ak=0,last=0;
ld T=100;
bool used[MAXN];
inline ll rr(ll);
inline ll len();
int main()
{
  int i=0,j=0,l=0;
  selc *p=NULL,*q=NULL;
  freopen("cover.in","r",stdin);freopen("cover.out","w",stdout);
  ios::sync_with_stdio(0);
  srand(19260817);
  cin>>n>>k;
  for(;i<n;i++)
  {
  	cin>>a[i].u>>a[i].v;
  	if(a[i].u>a[i].v)
  	{
  	  a[i].u^=a[i].v;
  	  a[i].v^=a[i].u;
  	  a[i].u^=a[i].v;
	}
  }
  for(i=0;i<k;i++)
  {
  	for(j=rr(n);used[j];j=rr(n));
  	used[j]=1;
  	q=new selc;
  	q->u=a[j].u;
	q->v=a[j].v;
	q->id=j;
	q->next=NULL;
	if(head==NULL)
	{
	  head=q;
	  continue;
	}
  	for(p=head;p->next!=NULL && p->next->u<q->u;p=p->next);
  	q->next=p->next;
  	p->next=q;
  }
  for(ans=len();T>min_T;T*=0.8+(ld)n/1000000)
  {
  	//cout<<ans<<":"<<T<<endl;
  	//system("pause");
	for(j=rr(n);used[j];j=rr(n));
  	used[j]=1;
  	i=rr(k);
  	//cout<<"j="<<j<<" i="<<i<<endl;
  	//cout<<
  	if(i==0)
  	{
  	  used[head->id]=0;
  	  last=head->id;
	  q=head;
  	  head=head->next;
  	  delete q;
	}
  	else
  	{
	  for(p=head,l=1;l<i;l++)
  	  {
  	    p=p->next;
	  }
	  used[p->next->id]=0;
	  last=p->next->id;
	  q=p->next;
	  p->next=p->next->next;
	  delete q;
	}
	q=new selc;
	q->id=j;
	q->u=a[j].u;
	q->v=a[j].v;
	q->next=NULL;
	if(head->u>q->u)
	{
	  q->next=head;
	  head=q;
	}
	else
	{
	  for(p=head;p->next!=NULL && p->next->u<q->u;p=p->next);
	  q->next=p->next;
  	  p->next=q;
	}
	ak=len();
	if(ak>ans)
	{
	  ans=ak;
	}
	else
	{
	  if(exp(-T)<(double)rr(1000000)/1000000)
	  {
	  	ans=ak;
	  }
	  else
	  {
	  	used[last]=1;
	  	used[j]=0;
	  	q=new selc;
	  	q->u=a[last].u;
	  	q->v=a[last].v;
	  	q->id=last;
	  	q->next=NULL;
	  	if(head->u<q->u)
	    {
	      q->next=head;
	      head=q;
	    }
	    else
	    {
	      for(p=head;p->next!=NULL && p->next->u<q->u;p=p->next);
	      q->next=p->next;
  	      p->next=q;
	    }
	    if(head->id==j)
	    {
	      q=head;
	      head=head->next;
	      delete q;
		}
		else
		{
		  for(p=head;p->next->id!=j;p=p->next);
		  q=p->next;
		  p->next=q->next;
		  delete q;
		}
	  }
	}
  }
  cout<<ans<<endl;
  fclose(stdin);fclose(stdout);
  return 0;
}
inline ll len()
{
  ll ans=0,left=-1,right=-1;
  selc *p=NULL;
  if(k==1)
  {
  	return head->v-head->u;
  }
  for(p=head;p!=NULL;)
  {
  	left=p->u;
  	right=p->v;
  	for(;p!=NULL && p->u<=right;p=p->next)
  	{
  	  right=max(right,p->v);
	}
  	ans+=right-left;
  }
  return ans;
}
inline ll rr(ll x)
{
  return (ll)rand()*rand()%x;
}
