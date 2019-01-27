#include<iostream>
#include<queue>
#define MAXK 110
using namespace std;
const int dx[4]={2,3,4,5};
struct pr
{
  int v;
  int c;
};
bool operator<(const pr &a,const pr &b)
{
  return a.v<b.v;
}
int d[MAXK],n=0,k=0,ans=0;
void build(int);
int main()
{
  int i=0;
  freopen("c.in","r",stdin);freopen("c.out","w",stdout);
  d[1]=1;
  cin>>n>>k;
  ans=n;
  build(1);
  cout<<ans<<endl;
  fclose(stdin);fclose(stdout);
  return 0;
}
void build(int x)
{
  if(x==k)
  {
  	int i=0;
	pr p={0,0},pp={0,0};
	priority_queue<pr>q;
  	q.push(p);
  	for(;!q.empty();)
  	{
  	  p=q.top();
  	  q.pop();
  	  pp.c=p.c+1;
  	  for(i=1;i<=k;i++)
  	  {
  	    pp.v=p.v+d[i];
  	    if(pp.v==n)
  	    {
  	      if(ans>pp.c)
  	      {
  	      	ans=pp.c;
		  }
		  return;
		}
		else if(pp.v<n)
		{
		  q.push(pp);
		}
	  }
	}
  }
  else
  {
  	int i=0;
	for(;i<4;i++)
	{
	  d[x+1]=d[x]*dx[i];
	  build(x+1);
	}
  }
  return;
}
