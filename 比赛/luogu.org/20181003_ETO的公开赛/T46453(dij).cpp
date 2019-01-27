#include<cstdio>
#include<algorithm>
#include "memory.h"
#define MAXN 880
#define INF 0x3f3f3f3f
#define FNI 0x80000000
using namespace std;
struct planet
{
	int id,ce,ct;
}s[MAXN];
int dis[MAXN][MAXN],t[3],e=0,n=0,m=0;
inline void read(int&);
inline bool cmp(const planet&,const planet&);
int main()
{
	int i=1,j=0,k=0,c=0;
	memset(dis,0x3f,sizeof(dis));
	for(read(n),read(m);i<=m;++i)
	{
		read(j);read(k);read(c);
		dis[j][k]=c;
	}
	for(read(e),i=0;i<3;++i)
	{
		read(t[i]);
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
			s[i].ct=FNI;
		}
		else
		{
			s[i].ct=min(dis[t[0]][i],min(dis[t[1]][i],dis[t[2]][i]));
		}
	}
	s[e].ct=FNI;
	s[e].id=-1;
	for(i=0;i<3;++i)
	{
		s[t[i]].ct=FNI;
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
