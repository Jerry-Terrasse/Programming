#include<iostream>
#define MAXN 100010
#define lbt(x) x&-x
using namespace std;
int t[MAXN],n=0,q=0;
inline void add(int,int);
inline int sum(int);
int main()
{
  int i=0,o=0,x=0,y=0;
  ios::sync_with_stdio(0);
  for(cin>>n>>q;i<q;i++)
  {
  	cin>>o>>x>>y;
  	switch(o)
  	{
  	  case 1:
  	  	add(x,y);
  	  	break;
  	  case 2:
  	  	o=sum(x)-sum(x-1);
  	  	add(x,y-o);
  	  	break;
  	  case 3:
  	  	cout<<sum(y)-sum(x-1)<<endl;
  	  	break;
	}
  }
  return 0;
}
inline void add(int x,int y)
{
  int i=x;
  for(;i<=n;i+=lbt(i))
  {
  	t[i]+=y;
  }
  return;
}
inline int sum(int x)
{
  int ans=0,i=x;
  for(;i>=1;i-=lbt(i))
  {
  	ans+=t[i];
  }
  return ans;
}
