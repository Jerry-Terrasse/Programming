#include<cstdio>
#include<algorithm>
#define ll long long
#define MAXN 48
#define max(x,y) (x<y)?(y):(x)
using namespace std;
char c='\0';
ll f[1<<(MAXN>>1)],g[1<<(MAXN>>1)],w[MAXN],s=0,ans=0,n=0,cnt=0,flag=0,end=0,now=0;
inline void read(ll&);
void write(const ll&);
void dfs(const ll&,const ll&);
int main()
{
	ll i=1,j=0,k=0;
	for(read(s),read(n);i<=n;i++)
	{
		read(j);read(k);
		for(w[cnt]=1;k--;)
		{
			w[cnt]*=j;
			if(w[cnt]>s)
			{
				break;
			}
		}
		if(w[cnt]==s)
		{
			write(s);
			putchar('\n');
		}
		if(w[cnt]<s)
		{
			cnt++;
		}
	}
	flag=cnt>>1;
	cnt-=flag;
	for(now=0;now<(1<<flag);++now)
	{
		for(i=0;i<flag;++i)
		{
			if(now&(1<<i))
			{
				f[now]+=w[i];
				if(f[now]>s)
				{
					f[now]=0;
					break;
				}
			}
		}
	}
	for(now=0;now<(1<<cnt);++now)
	{
		for(i=0;i<cnt;++i)
		{
			if(now&(1<<i))
			{
				g[now]+=w[i+flag];
				if(g[now]>s)
				{
					g[now]=0;
					break;
				}
			}
		}
		g[now]=s-g[now];
	}
	sort(f,f+(1<<flag));
	sort(g,g+(1<<cnt));
	for(now=0;now<(1<<flag);++now)
	{
		i=lower_bound(g,g+(1<<cnt),f[now])-g;
		ans=max(ans,f[now]+s-g[i]);
	}
	write(ans);
	putchar('\n');
	return 0;
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
