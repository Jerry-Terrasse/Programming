#include<iostream>
#include<algorithm>
#include "memory.h"
#define ld long double
#define eps 1e-2
#define MAXN 32
using namespace std;
struct mtd
{
  ld a,b;
  int crs1,crs2;
  inline void work(const int&,const int&);
}f[MAXN*MAXN];
struct dtm
{
  ld a,b;
  bool ctn[MAXN];
  int cnt;
}g[MAXN*MAXN];
int use[MAXN],t=0,n=0,m=0,cnt=0,cut=0,ans=0,kill=0;
ld x[MAXN],y[MAXN];
inline bool cmp(const mtd&,const mtd&);
inline bool eql(const ld&,const ld&);
inline bool cmp2(const dtm&,const dtm&);
int main()
{
  register int i=0,j=0,k=0;
  freopen("angrybirds.in","r",stdin);freopen("angrybirds.out","w",stdout);
  ios::sync_with_stdio(false);
  cin>>t;
  for(;t--;)
  {
	cnt=ans=0;cut=1;
	memset(f,0,sizeof(f));
	memset(use,0,sizeof(use));
	cin>>n>>m;
	for(i=1;i<=n;++i)
  	{
  	  cin>>x[i]>>y[i];
	}
	for(i=1;i<=n;++i)
	{
	  for(j=i+1;j<=n;++j)
	  {
	  	f[++cnt].work(i,j);
	  }
	}
	sort(f+1,f+cnt+1,cmp);
	g[1].a=f[1].a;g[1].b=f[1].b;
	g[1].cnt=2;g[1].ctn[f[1].crs1]=g[2].ctn[f[1].crs2]=1;
	for(i=2;i<=cnt;++i)
	{
	  if(eql(f[i].a,g[cut].a)&&eql(f[i].b,g[cut].b))
	  {
	  	if(!g[cut].ctn[f[i].crs1])
	  	{
	  	  ++g[cut].cnt;
	  	  g[cut].ctn[f[i].crs1]=1;
		}
		if(!g[cut].ctn[f[i].crs2])
	  	{
	  	  ++g[cut].cnt;
	  	  g[cut].ctn[f[i].crs2]=1;
		}
	  }
	  else
	  {
	  	g[++cut].a=f[i].a;
	  	g[cut].b=f[i].b;
	  	g[cut].cnt=2;
	  	g[cut].ctn[f[i].crs1]=g[cut].ctn[f[i].crs2]=1;
	  }
	}
	for(i=1,kill=0;kill<n;++i)
	{
	  sort(g+1,g+cut+1,cmp2);
	  ++ans;
	  kill+=g[i].cnt;
	  for(j=1;j<=n;++j)
	  {
	  	if(g[i].ctn[j])
	  	{
	  	  for(k=1;k<=n;++k)
	  	  {
	  	    if(g[k].ctn[j])
	  	    {
	  	      g[k].ctn[j]=0;
	  	      --g[k].cnt;
			}
		  }
		}
	  }
	}
	cout<<ans<<endl;
  }
  return 0;
}
inline bool cmp2(const dtm &a,const dtm &b)
{
  return a.a>-eps&&a.cnt>b.cnt;
}
inline bool eql(const ld &a,const ld &b)
{
  return a-b>-eps&&a-b<eps;
}
inline bool cmp(const mtd &a,const mtd &b)
{
  return a.a<b.a||(eql(a.a,b.a)&&a.b<b.b);
}
inline void mtd::work(const int &u,const int &v)
{
  a=(y[u]*x[v]-y[v]*x[u])/(x[u]*x[v]*(x[u]-x[v]));
  b=y[u]/x[u]-a*x[u];
  crs1=u;
  crs2=v;
  return;
}
