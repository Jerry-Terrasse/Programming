#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
ll t=0,a=0,b=0,n=0,m=0,k=0,ans=0,cnt=0,r1=0,r2=0;
inline void read(ll&);
void write(const ll&);
inline ll work(ll,ll,ll,ll);
int main()
{
  register ll i=0,j=0;
  //freopen("b.in","r",stdin);
  read(t);
  for(;t--;)
  {
  	a=b=n=m=k=ans=cnt=r1=r2=0;
	read(a);read(b);read(n);
  	m=floor(sqrt(n));
  	for(i=0;(1<<i)<=m;++i);
  	m=1LL<<i>>1;
  	ans=work(a,b,m,m)*k;
  	ans+=work(cnt,org,1LL<<63,k);
  	for(i=m*k,b=r2*m+r1;i<=n;++i)
  	{
  	  ans+=__builtin_popcount(b+=a);
	}
	write(ans);
	putchar('\n');
  }
  return 0;
}
inline ll work(ll a,ll b,ll p,ll n)
{
  register ll i=0,ans=0;
  for(i=1;i<=n;++i)
  {
  	b+=a;
  	
  }
}
void write(const ll &x)
{
  if(x>9)
  {
  	write(x/10);
  }
  putchar(x%10^48);
  return;
}
inline void read(ll &x)
{
  register int c=getchar();
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
