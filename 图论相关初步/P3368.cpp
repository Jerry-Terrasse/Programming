#include<iostream>
#define MAXN 500010
#define lb(x) x&-x
using namespace std;
int n=0,m=0,a[MAXN];
void add(int,int);
int sum(int);
int main()
{
  int i=0,x=0,y=0,k=0,t[2]={0,0};
  cin>>n>>m;
  for(i=1;i<=n;i++)
  {
  	cin>>t[i&1];
  	//cout<<"{"<<i<<","<<t[i&1]-t[i&1^1]<<"}"<<endl;
  	add(i,t[i&1]-t[i&1^1]);
  }
  for(i=1;i<=m;i++)
  {
  	cin>>k>>x;
  	if(k&1)
  	{
  	  cin>>y>>k;
  	  add(x,k);
  	  add(y+1,-k);
	}
	else
	{
	  cout<<sum(x)<<endl;
	}
  }
  return 0;
}
void add(int x,int k)
{
  int i=x;
  for(;i<=n;i+=lb(i))
  {
  	a[i]+=k;
  }
  return;
}
int sum(int x)
{
  int s=0,i=x;
  for(;i>=1;i-=lb(i))
  {
  	s+=a[i];
  }
  return s;
}
