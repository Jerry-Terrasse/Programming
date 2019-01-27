#include<iostream>
#include "memory.h"
#include<queue>
#define MAXN 1000010
#define ok(x) (x>=0)&&(x<=MAXN)
#define inf 0x3f3f3f3f
using namespace std;
int f[MAXN],b[MAXN],ff=0,bb=0,ans=0;
queue<pair<int,int> >q,p;
int n=0,m=0;
int main()
{
  int i=0;
  pair<int,int>x=make_pair(0,0);
  cin>>n>>m;
  if(n==m)
  {
  	cout<<0<<endl;
  	return 0;
  }
  memset(f,0x3f,sizeof(f));
  memset(b,0x3f,sizeof(b));
  q.push(make_pair(n,0));
  p.push(make_pair(m,0));
  f[n]=0;b[m]=0;
  for(;1;)
  {
  	x=q.front();
  	if(x.second+4<ff)q.pop();
  	ff++;
  	if(ok(x.first+2))
  	{
	  if(b[x.first+2]<inf)
	  {
	  	ans=x.second+1+b[x.first+2];
	  	break;
	  }
	  if(f[x.first+2]==inf)
	  {
	    q.push(make_pair(x.first+2,x.second+1));
	  	f[x.first+2]=x.second+1;
	  }
	}
  	if(x.second+2<=ff && ok(x.first-3))
  	{
	  if(b[x.first-3]<inf)
	  {
	  	ans=x.second+2+b[x.first-3];
	  	break;
	  }
	  if(f[x.first-3]==inf)
	  {
  	    q.push(make_pair(x.first-3,x.second+2));
	  	f[x.first-3]=x.second+2;
	  }
	}
  	if(x.second+3<=ff && ok(x.first*4))
  	{
	  if(b[x.first*4]<inf)
	  {
	  	ans=x.second+3+b[x.first*4];
	  	break;
	  }
	  if(f[x.first*4]==inf)
	  {
  	    q.push(make_pair(x.first*4,x.second+3));
	  	f[x.first*4]=x.second+3;
	  }
	}
  	if(x.second+4<=ff && x.first%5==0 && ok(x.first/5))
  	{
	  if(b[x.first/5]<inf)
	  {
	  	ans=x.second+4+b[x.first/5];
	  	break;
	  }
	  if(f[x.first/5]==inf)
	  {
  	    q.push(make_pair(x.first/5,x.second+4));
	  	f[x.first/5]=x.second+4;
	  }
	}
	x=p.front();
	if(x.second+4<bb)p.pop();
	bb++;
	if(ok(x.first-2))
  	{
	  if(f[x.first-2]<inf)
	  {
	  	ans=x.second+1+f[x.first-2];
	  	break;
	  }
	  if(b[x.first-2]==inf)
	  {
	    p.push(make_pair(x.first-2,x.second+1));
	  	b[x.first-2]=x.second+1;
	  }
	}
  	if(x.second+2<=bb && ok(x.first+3))
  	{
	  if(f[x.first+3]<inf)
	  {
	  	ans=x.second+2+f[x.first+3];
	  	break;
	  }
	  if(b[x.first+3]==inf)
	  {
  	    p.push(make_pair(x.first+3,x.second+2));
	  	b[x.first+3]=x.second+2;
	  }
	}
  	if(x.second+3<=bb && x.first%4==0 && ok(x.first/4))
  	{
	  if(f[x.first/4]<inf)
	  {
	  	ans=x.second+3+f[x.first/4];
	  	break;
	  }
	  if(b[x.first/4]==inf)
	  {
  	    p.push(make_pair(x.first/4,x.second+3));
	  	b[x.first/4]=x.second+3;
	  }
	}
  	if(x.second+4<=bb && ok(x.first*5))
  	{
	  if(f[x.first*5]<inf)
	  {
	  	ans=x.second+4+f[x.first*5];
	  	break;
	  }
	  if(b[x.first*5]==inf)
	  {
  	    p.push(make_pair(x.first*5,x.second+4));
	  	b[x.first*5]=x.second+4;
	  }
	}
  }
  cout<<ans<<endl;
  return 0;
}
