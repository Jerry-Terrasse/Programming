#include<cstdio>
#include "memory.h"
#define ll long long
#define ha 19260817
using namespace std;
int arca[ha],cnt[ha],a=0,b=0,t=0;
ll ans=0;
inline int arc(const int&);
inline ll pow(ll,ll);
inline void read(int&);
inline void write(const int&);
int main()
{
	int i=0,j=0,k=0,l=0;
	for(read(t);t--;)
	{
		read(a);read(b);
		memset(cnt,0,sizeof(cnt));
		for(i=a;i<=b;i++)
		{
			for(j=1;j<=i;j++)
			{
				k=i/j;
				cnt[i]+=k;
				if(cnt[j]>=k)
				{
					cnt[j]-=k;
				}
				else
				{
					k-=cnt[j];
					cnt[j]=0;
					cnt[arc(j)]+=k;
				}
			}
		}
		for(ans=1,i=1;i<ha;i++)
		{
			ans*=pow(i,cnt[i]);
			ans%=ha;
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
inline int arc(const int &x)
{
	if(arca[x])
	{
		return arca[x];
	}
	else
	{
		return arca[x]=pow(x,ha-2);
	}
}
inline void read(int &x)
{
	char c=getchar();
	for(x=0;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
	{
		x=(x<<1)+(x<<3)-'0'+c;
	}
	return;
}
inline void write(const int &x)
{
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10+'0');
	return;
}
inline ll pow(ll a,ll b)
{
	ll ans=1;
	for(;b;)
	{
		if(b&1)
		{
			ans*=a;
			ans%=ha;
		}
		a*=a;
		a%=ha;
		b>>=1;
	}
	return ans;
}
