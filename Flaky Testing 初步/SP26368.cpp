#include<cstdio>
#define ll long long
using namespace std;
ll a=0,b=0,m=0,t=0;
char c='\0';
inline void read(ll&);
void write(const ll&);
inline ll pow();
int main()
{
  int i=0;
  scanf("%lld",&t);
  for(;t--;)
  {
    scanf("%lld%lld%lld",&a,&b,&m);
	write(pow());
    putchar('\n');
  }
  return 0;
}
inline ll pow()
{
  ll ans=1%m;
  for(;b;b>>=1)
  {
  	if(b&1)
  	{
  	  ans*=a;
  	  ans%=m;
	}
	a*=a;
	a%=m;
  }
  return ans;
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
  for(x=0;c<'0'||c>'9';c=getchar());
  for(;c>='0'&&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
