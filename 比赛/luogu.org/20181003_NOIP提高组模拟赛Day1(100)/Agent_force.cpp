#include<iostream>
#define ll long long
#define MAXN 10000010
#define H 1000000007
using namespace std;
ll js[MAXN],ajs[MAXN],arc[MAXN],n=0,ans=0;
inline void init();
inline ll C(const ll&,const ll&);
int main()
{
  int i=1;
  cin>>n;
  init();
  for(;i<n;++i)
  {
  	ans+=i*C(n,i+1);
  	ans%=H;
	}
	cout<<ans<<endl;
	return 0;
}
inline ll C(const ll &n,const ll &m)
{
	return js[n]*ajs[m]%H*ajs[n-m]%H;
}
inline void init()
{
	int i=1;
	for(js[0]=1;i<=n;++i)
	{
		js[i]=js[i-1]*i%H;
	}
	for(i=2,arc[1]=1;i<=n;i++)
	{
		arc[i]=-(H/i)*arc[H%i];
		arc[i]=(arc[i]%H+H)%H;
	}
	for(ajs[0]=1,i=1;i<=n;i++)
	{
		ajs[i]=ajs[i-1]*arc[i]%H;
	}
	return;
}
