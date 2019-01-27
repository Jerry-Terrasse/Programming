#include<cstdio>
#include "memory.h"
#define ll long long
#define MAXN 1000010
#define pp 998244353
#define MAXZ 78498
using namespace std;
ll ans[MAXN];
int f[MAXN],g[MAXN],a[MAXN],v[MAXN],zs[MAXZ],n=0,t=0;
inline void prime();
inline ll pow(ll,ll);
inline void read(int&);
inline void write(const ll&);
int main()
{
	int i=0,j=0,k=0,cnt=0;
	prime();
	for(i=1;i<MAXN;i++)
	{
		f[i]=f[i-1]+pow(i,pp-2);
		if(f[i]>=pp)
		{
			f[i]-=pp;
		}
	}
	for(i=1;i<MAXN;i++)
	{
		a[i]=i;
	}
	for(i=1;i<MAXN;i++)
	{
		g[i]=1;
	}
	for(i=0;i<MAXZ;i++)
	{
		for(j=zs[i];j<MAXN;j+=zs[i])
		{
			for(cnt=0;!(a[j]%zs[i]);++cnt,a[j]/=zs[i]);
			g[j]*=cnt+1;
		}
	}
	for(i=1;i<MAXN;i++)
	{
		g[i]=g[i-1]-g[i];
		if(g[i]<0)
		{
			g[i]+=pp;
		}
	}
	for(i=1;i<MAXN;i++)
	{
		ans[i]=((ll)f[i]*i+g[i]+ans[i-1])%pp;
	}
	for(read(t);t--;)
	{
		read(i);read(j);
		if(ans[j]-ans[i-1]<0)
		{
			write(ans[j]-ans[i-1]+pp);
		}
		else
		{
			write(ans[j]-ans[i-1]);
		}
		putchar('\n');
	}
	return 0;
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
inline void write(const ll &x)
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
			ans%=pp;
		}
		a*=a;
		a%=pp;
		b>>=1;
	}
	return ans;
}
inline void prime()
{
  ll i=0,j=0,n=999983,cnt=0;
  for(i=2;i<=n;i++)
  {
  	if(!v[i])
  	{
  		v[i]=i;
  		zs[cnt++]=i;
		}
		for(j=0;j<cnt;j++)
		{
			if(zs[j]>v[i]||zs[j]>n/i)
			{
				break;
			}
			v[i*zs[j]]=zs[j];
		}
  }
  return;
}
