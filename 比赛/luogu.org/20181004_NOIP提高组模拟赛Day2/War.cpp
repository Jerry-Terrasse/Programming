#include<cstdio>
#include<vector>
#include "memory.h"
#define ll long long
#define MAXN 20
using namespace std;
char c='\0';
ll f[1<<MAXN],a[MAXN],n=0,m=0,k=0,now=0,ans=0;
vector<pair<int,ll> >ad[MAXN];
inline void read(int&);
inline void read(ll&);
void write(const ll&);
ll dfs(int);
int main()
{
	int i=0,x=0,y=0,cnt=0;
	ll c=0;
	bool bo=0;
	memset(f,-1,sizeof(f));
	f[0]=0;
	for(read(n),read(m),read(k);i<n;++i)
	{
		read(a[i]);
	}
	for(;k--;)
	{
		read(x);read(y);read(c);
		ad[y-1].push_back(make_pair(x-1,c));
	}
	for(now=0;now<(1<<n);++now)
	{
		bo=true;
		for(i=0,cnt=0;i<n;++i)
		{
			if(now&(1<<i))
			{
				cnt++;
				if(cnt>m)
				{
					bo=false;
					break;
				}
			}
		}
		if(bo)
		{
			dfs(now);
			if(cnt==m&&ans<f[now])
			{
				ans=f[now];
			}
		}
	}
	write(ans);
	putchar('\n');
	return 0;
}
ll dfs(int s)
{
	if(f[s]!=-1)
	{
		return f[s];
	}
	ll i=0,j=0,ans=0;
	f[s]=0;
	for(;i<n;++i)
	{
		if(s&(1<<i))
		{
			ans=dfs(s^(1<<i));
			ans+=a[i];
			for(j=0;j<ad[i].size();++j)
			{
				if(s&(1<<ad[i][j].first))
				{
					ans+=ad[i][j].second;
				}
			}
			if(ans>f[s])
			{
				f[s]=ans;
			}
		}
	}
	return f[s];
}
void write(const ll &x)
{
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10+'0');
	return;
}
inline void read(ll &x)
{
	for(x=0,c=getchar();c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
	{
		x=(x<<1)+(x<<3)-'0'+c;
	}
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
