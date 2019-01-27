#include<cstdio>
#include<iostream>
#define int long long
#define H 1000000007
using namespace std;
int h=0,w=0,n=0,m=0;
inline int pow(int,int);
signed main()
{
  register int i=0,j=0;
  freopen("grid.in","r",stdin);freopen("grid.out","w",stdout);
  cin>>h>>w>>m>>n;
  if(1)//n==0)
  {
  	cout<<pow(m,h*w)<<endl;
  }
  return 0;
}
inline int pow(int a,int b)
{
  int ans=1;
  for(;b;b>>=1)
  {
  	if(b&1)
  	{
  	  (ans*=a)%=H;
  	}
  	(a*=a)%=H;
  }
  return ans;
}
