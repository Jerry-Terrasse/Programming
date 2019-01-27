#include<cstdio>
#define MAXN 100010
#define min(x,y) (x<y?x:y)
#define lbt(x) x&-x
using namespace std;
int a[MAXN],s[MAXN],n=0,ans=0,q=0;
inline void read(int&);
void write(const int&);
inline void add(int,int);
inline int sum(int);
int main()
{
	int i=1,x=0,t=0,e=0,l=0,r=0;
	for(read(n);i<=n;++i)
	{
		read(a[i]);
	}
	if(n<=1000)
	{
		for(read(q);q--;)
		{
			read(x);read(t);read(e);
			ans=e;
			if(a[x]==t)
			{
				e--;
			}
			for(l=x-1,r=x+1;e&&l>=1&&r<=n;)
			{
				if(a[l]==t)
				{
					e--;
				}
				l--;
				if(!e)
				{
					break;
				}
				if(a[r]==t)
				{
					e--;
				}
				r++;
			}
			for(;e&&l>=1;l--)
			{
				if(a[l]==t)
				{
					e--;
				}
			}
			for(;e&&r<=n;r++)
			{
				if(a[r]==t)
				{
					e--;
				}
			}
			write(ans-e);putchar(' ');
			for(l++;l<r;l++)
			{
				if(a[l]==t)
				{
					a[l]=0;
					write(l);putchar(' ');
				}
			}
			putchar('\n');
			read(x);read(t);
			a[x]=t;
		}
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			add(i,1);
		}
		for(read(q);q--;)
		{
			read(x);read(t);read(e);
			ans=e;
			/*e-=(a[x]==1);
			if(!e)
			{
				putchar('1');putchar(' ');write(x);putchar('\n');
				if(a[x]==1)
				{
					add(x,-1);
				}
				read(x);read(t);
				if(!a[x])
				{
					add(x,1);
				  a[x]=1;
				}
				continue;
			}*/
			l=0;r=min(x-1,n-x+1)+1;
			for(;l+1<r;)
			{
				t=l+r>>1;
				if(sum(x+t)-sum(x-t-1)<=e)
				{
					l=t;
				}
				else
				{
					r=t;
				}
			}
			t=l+r>>1;
			l=x-t-1;r=x+t+1;
			e-=sum(x+t)-sum(x-t-1);
			for(;e&&l>=1&&r<=n;)
			{
				if(a[l]==t)
				{
					e--;
				}
				l--;
				if(!e)
				{
					break;
				}
				if(a[r]==t)
				{
					e--;
				}
				r++;
			}
			for(;e&&l>=1;l--)
			{
				if(a[l]==t)
				{
					e--;
				}
			}
			for(;e&&r<=n;r++)
			{
				if(a[r]==t)
				{
					e--;
				}
			}
			write(ans-e);putchar(' ');
			for(l++;l<r;l++)
			{
				if(a[l]==t)
				{
					a[l]=0;
					add(l,-1);
					write(l);putchar(' ');
				}
			}
			putchar('\n');
			read(x);read(t);
			if(!a[x])
			{
				add(x,1);
			  a[x]=1;
			}
		}
	}
	return 0;
}
inline int sum(int x)
{
	int ans=0;
	for(;x;)
	{
		ans+=x;
	}
	return ans;
}
inline void add(int x,int k)
{
	for(;x<=n;x+=lbt(x))
	{
		s[x]+=k;
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
	char c=getchar();
	for(x=0;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
	{
		x=(x<<1)+(x<<3)-'0'+c;
	}
	return;
}
