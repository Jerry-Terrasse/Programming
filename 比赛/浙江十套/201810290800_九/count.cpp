#include<iostream>
#define ll long long
#define MAXA 1000010
#define MAXK 8
#define sqr(x) ((x)*(x)*(x))
using namespace std;
const int lim[7]={0,0,99,1999,19999,229999,999999};
int h[MAXA],a=0,b=0,k=6;
inline ll S(ll);
inline int pow(int,int);
int main()
{
  int i=0;
  freopen("count.in","r",stdin);freopen("count.out","w",stdout);
  cin>>a>>b>>k;
  //for(;;)
  cout<<a*k+a+(b<<1)<<endl;
  return 0;
}
inline int pow(int a,int b)
{
  int ans=1;
  for(;b;b>>=1)
  {
  	if(b&1)
  	{
  	  ans*=a;
	}
	a*=a;
  }
  return ans;
}
inline ll S(ll x)
{
  ll ans=0;
  for(;x;x/=10)
  {
  	ans+=pow(x%10,k);
  }
  return ans;
}
