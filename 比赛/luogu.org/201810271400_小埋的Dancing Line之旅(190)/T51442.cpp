#include<cstdio>
#include<map>
#include<cmath>
#define ll long long
using namespace std;
ll n=0,p=0,m=0,a=0,b=0,d=0,x=0,y=0;
char c='\0';
map<ll,ll>mp;
inline ll pow(ll,ll);
ll gcd(const ll&,const ll&);
inline void read(ll&);
void write(const ll&);
int main()
{
	ll i=0;
	read(n);read(p);read(b);
	b-=n;a=(n<<1)-1;
	b=((b%p)+p)%p;
	a%=p;
	if(!a)
	{
		if(b)
		{
			putchar('I');putchar('N');putchar('F');
		}
		else
		{
			putchar('1');
		}
		return 0;
	}
	d=gcd(a,p);
	if(d==1)
	{
	m=ceil(sqrt(p));
	x=b;
	mp.insert(make_pair(x,0));
	for(i=1;i<m;++i)
	{
		x*=a;
		x%=p;
		if(mp.count(x))
		{
			mp[x]=i;
		}
		else
		{
			mp.insert(make_pair(x,i));
		}
	}
	x=pow(a,m);
	for(i=1,y=1;i<=m;++i)
	{
		y*=x;
		y%=p;
		if(mp.count(y))
		{
			write(i*m-mp[y]);
			return 0;
		}
	}
			putchar('I');putchar('N');putchar('F');
  }
  else
  {
  if(b%d)
  {
			putchar('I');putchar('N');putchar('F');
	}
	else
	{
		b/=d;
		p/=d;
	m=ceil(sqrt(p));
	x=b;
	mp.insert(make_pair(x,0));
	for(i=1;i<=m;++i)
	{
		x*=a;
		x%=p;
		if(mp.count(x))
		{
			mp[x]=i;
		}
		else
		{
			mp.insert(make_pair(x,i));
		}
	}
	x=pow(a,m);
	for(i=1,y=a/d;i<=m;++i)
	{
		y*=x;
		y%=p;
		if(mp.count(y))
		{
			write(i*m-mp[y]+1);
			return 0;
		}
	}
			putchar('I');putchar('N');putchar('F');
	}
	}
	return 0;
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
ll gcd(const ll &a,const ll &b)
{
	return a?gcd(b%a,a):b;
}
inline ll pow(ll a,ll b)
{
	ll ans=1;
	for(;b;b>>=1)
	{
		if(b&1)
		{
			ans*=a;
			ans%=p;
		}
		a*=a;
		a%=p;
	}
	return ans;
}
