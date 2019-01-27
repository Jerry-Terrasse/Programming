#include<cstdio>
#include<algorithm>
#include "memory.h"
#define MAXN 880
#define INF 0x3f3f3f3f
using namespace std;
struct planet
{
	int id,ce,ct;
}s[MAXN];
int dis[MAXN][MAXN],c[3][MAXN],t[3],e=0,n=0,m=0;
inline void read(int&);
inline bool cmp(const planet&,const planet&);
int main()
{
	int i=1,j=0,k=0,l=0;
	memset(dis,0x3f,sizeof(dis));
	for(read(n),read(m);i<=m;++i)
	{
		read(j);read(k);read(l);
		dis[j][k]=l;
	}
	for(read(e),i=0;i<3;++i)
	{
		read(t[i]);
	}
	for(i=0;i<3;++i)
	{
		for(j=1;j<=n;++j)
		{
			c[i][j]=dis[t[i]][j];
		}
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			for(k=1;k<=n;++k)
			{
				if(dis[i][j]>max(dis[i][k],dis[k][j]))
				{
					dis[i][j]=max(dis[i][k],dis[k][j]);
				}
			}
		}
	}
	for(i=1;i<=n;++i)
	{
		s[i].id=i;
		s[i].ce=dis[e][i];
		if(dis[e][i]==INF)
		{
			s[i].id=-1;
			s[i].ct=-1;
		}
		else
		{
			s[i].ct=min(c[0][i],min(c[1][i],c[2][i]));
		}
	}
	s[e].ct=-1;
	s[e].id=-1;
	for(i=0;i<3;++i)
	{
		s[t[i]].ct=-1;
		s[t[i]].id=-1;
	}
	sort(s+1,s+n+1,cmp);
	printf("%d",s[1].id);
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
inline bool cmp(const planet &a,const planet &b)
{
	return (a.ct>b.ct)||(a.ct==b.ct&&a.ce<b.ce)||(a.ct==b.ct&&a.ce==b.ce&&a.id<b.id);
}
