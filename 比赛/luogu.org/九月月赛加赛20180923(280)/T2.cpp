#include<cstdio>
#include<map>
#define ll long long
#define MAXN 200020
using namespace std;
ll n=0;
ll ans=0;
char c='\0';
map<ll,ll>mp;
inline void read(ll&);
int main()
{
  ll i=1,h=0;
  map<ll,ll>::iterator it;
  for(read(n),read(h);i<=n;i++)
  {
  	read(h);
  	if(!mp.count(i-h))
  	{
  	  mp.insert(make_pair(i-h,1));
	}
	else
	{
	  mp[i-h]++;
	}
	if(!mp.count(i+h))
  	{
  	  mp.insert(make_pair(i+h,1));
	}
	else
	{
	  mp[i+h]++;
	}
  }
  for(it=mp.begin();it!=mp.end();it++)
  {
  	ans+=(it->second)*(it->second-1)>>1;
  }
  printf("%lld\n",ans);
  return 0;
}
inline void read(ll &x)
{
  for(x=0,c=getchar();c<'0'||c>'9';c=getchar());
  for(;c>='0'&&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+c-'0';
  }
  return;
}
