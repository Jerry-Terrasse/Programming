#include<cstdio>
#include<algorithm>
#define ld long double
#define MAXN 100010
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
int st[MAXN][19],a[MAXN],b[MAXN],num[MAXN],lg[MAXN],n=0,m=0,cnt=0,ans=0;
int main()
{
  int i=1,u=0,v=0,uu=0,vv=0;
  ld x=0,y=20021015;
  for(scanf("%d",&n);i<=n;++i)
  {
  	scanf("%llf",&x);
  	if(x==y)
  	{
  	  ++a[cnt];
	}
	else
	{
	  a[++cnt]=1;
	  y=x;
	}
	num[i]=cnt;
  }
  for(i=1;i<=cnt;++i)
  {
  	b[i]=b[i-1]+a[i];
  }
  for(u=1;(1<<u)<=cnt;++u)
  {
  	for(v=1<<u;v<(1<<u+1);++v)
  	{
  	  lg[v]=u;
	}
  }
  for(i=1;i<=cnt;++i)
  {
  	st[i][0]=a[i];
  }
  for(u=1;(1<<u)<=cnt;++u)
  {
  	for(v=1;v+(1<<u)-1<=cnt;++v)
  	{
  	  st[v][u]=max(st[v][u-1],st[v+(1<<u-1)][u-1]);
	}
  }
  for(scanf("%d",&m);m--;)
  {
  	scanf("%d%d",&u,&v);
  	ans=0;
  	uu=num[u]+1;
  	vv=num[v]-1;
  	if(uu<=vv)
  	{
  	  ans=max(st[uu][lg[vv-uu]],st[vv-(1<<lg[vv-uu])+1][lg[vv-uu]]);
	  ans=max(b[uu-1]-u+1,max(v-b[vv],ans));
	}
	else if(uu==vv+1)
	{
	  ans=max(b[uu-1]-u+1,max(v-b[vv],ans));
	}
	else
	{
	  ans=v-u+1;
	}
	printf("%d\n",ans);
  }
  return 0;
}
