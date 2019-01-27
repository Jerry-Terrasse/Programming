#include<cstdio>
#define ll long long
#define MAXN 32
using namespace std;
struct edge
{
	int to,next;
}e[MAXN*MAXN];
char c='\0';
int head[MAXN],n=0,cnt=0,id=0,ans=0x7fffffff;
ll a[MAXN],now=0,cos=0;
inline void read(int&);
void write(const int&);
inline void addedge(const int&,const int&);
void dfs1(const int&);
void dfs2(const int&);
int main()
{
	int i=1,j=0,v=0,bit=0;
	for(read(n);i<=n;++i)
	{
		read(j);
		for(;j--;)
		{
			read(v);
			addedge(i,v);
		}
	}
	for(id=0;id<n;id++)
	{
		dfs1(id+1);
	}
	for(cos=1;cos<(1<<n);cos++)
	{
		now=(1<<n)-1;
		bit=0;
		for(i=0;i<n;i++)
		{
			if(cos&(1<<i))
			{
				bit++;
				now^=a[i];
			}
		}
		if((!now)&&ans>bit)
		{
			ans=bit;
		}
	}
	if(ans==0x7fffffff)
	{
		printf("Change an alarm clock£¬please!\n");
	}
	else
	{
		write(ans);
		putchar('\n');
	}
	return 0;
}
void dfs2(const int &x)
{
	int i=0;
	a[id]^=1<<x-1;
	for(i=head[x];i;i=e[i].next)
	{
		a[id]^=1<<e[i].to-1;
	}
}
void dfs1(const int &x)
{
	int i=0;
	a[id]^=1<<x-1;
	for(i=head[x];i;i=e[i].next)
	{
		dfs2(e[i].to);
	}
	return;
}
inline void addedge(const int &u,const int &v)
{
	e[++cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
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
