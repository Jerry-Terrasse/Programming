#include<cstdio>
#include<map>
#include<cmath>
#define ll long long
using namespace std;
ll x=0,z=1;
int d=0,p=0,m=0;
char c='\0';
map<ll,int>mp;
inline void read(int&);
void write(const ll&);
int gcd(const int&,const int&);
int main()
{
	register int i=0;
	read(p);read(i);
	d=gcd(i,p);
	x=i;
	if(d==1)
	{
		m=ceil(sqrt(p));
		mp.insert(make_pair(1,0));
		for(i=1;i<m;++i)
		{
			z*=x;
			z%=p;
			if(mp.count(z))
			{
				mp[z]=i;
		  }
		  else
		  {
		  	mp.insert(make_pair(z,i));
			}
		}
		z*=x;
		z%=p;
		x=1;
		for(i=1;i<=m;++i)
		{
			x*=z;
			x%=p;
			if(mp.count(x))
			{
				write(i*m-mp[x]);
				return 0;
			}
		}
	}
	printf("Let's go Blue Jays!");
	return 0;
}
int gcd(const int &a,const int &b)
{
	return b?gcd(b,a%b):a;
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
inline void read(int &x)
{
	for(x=0;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
	{
		x=(x<<1)+(x<<3)+(c^48);
	}
	return;
}
