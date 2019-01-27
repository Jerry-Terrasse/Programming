#include<cstdio>
#include<algorithm>
#include "memory.h"
#define ll long long
#define MAXN 19
#define H 4921057
using namespace std;
char ch='\0';
int f[1<<MAXN][MAXN],a[MAXN],b[MAXN],c[MAXN],rnk[MAXN],n=0;
ll ans=0;
int dfs(ll,int);
inline void read(int&);
void write(const int&);
int main()
{
	int i=0,j=0,k=0;
	memset(f,-1,sizeof(f));
	for(read(n);i<n;i++)
	{
		read(a[i]);
		c[i]=a[i];
	}
	for(i=0;i<n;i++)
	{
		read(b[i]);
	}
	sort(c,c+n);
	for(i=1;i<n;i++)
	{
		if(c[i]!=c[j])
		{
			c[++j]=c[i];
		}
	}
	for(i=0;i<=j;i++)
	{
		for(k=0;k<n;k++)
		{
			if(a[k]==c[i])
			{
				rnk[k]=i;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		f[1<<i][i]=1;
	}
	for(i=0;i<n;i++)
	{
		ans+=dfs((1<<n)-1,i);
		ans%=H;
	}
	write(ans);
	putchar('\n');
	return 0;
}
int dfs(ll s,int p)
{
	if(f[s][p]!=-1)
	{
		return f[s][p];
	}
	int i=0,cnt=0;
	f[s][p]=0;
	for(i=p-1;i>=0;i--)
	{
		if(s&(1<<i))
		{
			if(cnt<=b[i]&&(rnk[i]==rnk[p]||rnk[i]+1==rnk[p]))
			{
				f[s][p]+=dfs(s^(1<<p),i);
			}
		}
		else
		{
			cnt++;
		}
	}
	for(i=p+1,cnt=0;i<n;i++)
	{
		if(s&(1<<i))
		{
			if(cnt<=b[i]&&(rnk[i]==rnk[p]||rnk[i]+1==rnk[p]))
			{
				f[s][p]+=dfs(s^(1<<p),i);
			}
		}
		else
		{
			cnt++;
		}
	}
	return f[s][p];
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
	for(x=0,ch=getchar();ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar())
	{
		x=(x<<1)+(x<<3)-'0'+ch;
	}
	return;
}
