#include<cstdio>
#define ll long long
using namespace std;
char c='\0';
inline void read(ll&);
void write(const ll&);
int main()
{
	register ll i=0,n=0,ans=0;
	read(n);
	for(i=n>>2<<2|3;i>n;--i)
	{
		ans^=i;
	}
	write(ans);
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
