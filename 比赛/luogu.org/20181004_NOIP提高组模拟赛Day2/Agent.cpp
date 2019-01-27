#include<cstdio>
#define MAXN 10000010
#define lbt(x) x&-x
using namespace std;
int a[MAXN],n=0,m=0;
char c='\0';
inline void add(int,const int&);
inline int sum(int);
inline void read(int&);
void write(const int&);
int main()
{
	int o=0,a=0,b=0;
	for(read(n),read(m);m--;)
	{
		read(o);
		if(o)
		{
			read(a);
			write(sum(a));
			putchar('\n');
		}
		else
		{
			read(a);read(b);
			add(a,1);
			add(b+1,-1); 
		}
	}
	return 0;
}
inline int sum(int x)
{
	int ans=0;
	for(;x;x-=lbt(x))
	{
		ans+=a[x];
	}
	return ans;
}
inline void add(int x,const int &k)
{
	for(;x<=n;x+=lbt(x))
	{
		a[x]+=k;
	}
	return;
}
void write(const int &x)
{
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10+'0');
	return;
}
inline void read(int &x)
{
	for(x=0,c=getchar();c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
	{
		x=(x<<1)+(x<<3)-'0'+c;
	}
	return;
}
