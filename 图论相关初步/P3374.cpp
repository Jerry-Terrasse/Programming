#include<iostream>
#define MAXN 1000100
using namespace std;
int n=0,m=0,s[MAXN],a=0;
inline int lb(int);//lowbit
inline void add(int,int);
inline int sum(int);
int main()
{
  int i=0,x=0;
  cin>>n>>m;
  for(i=1;i<=n;i++)
  {
    cin>>a;
    add(i,a);
  }
  for(i=1;i<=m;i++)
  {
  	cin>>a;
  	if(a==1)
  	{
  	  cin>>x>>a;
  	  add(x,a);
	}
	else
	{
	  cin>>x>>a;
	  cout<<sum(a)-sum(x-1)<<endl;
	}
  }
  return 0;
}
inline int lb(int x)
{//acg1
  return x&(-x);
}
inline void add(int x,int k)
{
  int i=x;
  for(;i<=n;i+=lb(i))
  {
  	s[i]+=k;
  }
  return;
}
inline int sum(int x)
{
  int ans=0,i=x;
  for(;i>0;i-=lb(i))
  {
  	ans+=s[i];
  }
  return ans;
}
