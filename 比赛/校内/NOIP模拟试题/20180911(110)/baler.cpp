#include<iostream>
#include<cmath>
#define ll long long
#define ld long double
#define MAXN 1055
#define v0 10000
//#define dis(x,y) sqrt(x*x+y*y)
//#define eql(x,y) (0.0001>abs(x-y))
using namespace std;
struct baler
{
  int x,y,r;
}a[MAXN];
struct edge
{
  int to,next;
}eg[MAXN*MAXN];
ll head[MAXN],t[2]={0,0},s=0,e=0,cnt=0,n=0;
inline void addedge(int,int);
void dfs(int,int,ld,ld);
inline ld dis(ld,ld);
inline bool eql(ld,ld);
int main()
{
  int i=1,j=0;
  freopen("baler.in","r",stdin);freopen("baler.out","w",stdout);
  for(cin>>n>>t[0]>>t[1];i<=n;i++)
  {
  	cin>>a[i].x>>a[i].y>>a[i].r;
  	if(a[i].x==t[0]&&a[i].y==t[1])
  	{
  	  e=i;
	}
	if(a[i].x==0&&a[i].y==0)
	{
	  s=i;
	}
	for(j=1;j<i;j++)
	{
	  //cout<<dis((a[i].x-a[j].x),(a[i].y-a[j].y))<<endl<<a[i].r+a[j].r<<endl;
	  if(eql((dis((a[i].x-a[j].x),(a[i].y-a[j].y))),(a[i].r+a[j].r)))
	  {
	  	//cout<<i<<','<<j<<endl;
		addedge(i,j);
	  }
	}
  }
  dfs(s,0,v0,0);
  fclose(stdin);fclose(stdout);
  return 0;
}
inline ld dis(ld x,ld y)
{
  return sqrt(x*x+y*y);
}
inline bool eql(ld x,ld y)
{
  return 0.0001>abs(x-y);
}
void dfs(int id,int fa,ld v,ld ans)
{
  int i=0;
  if(id==e)
  {
  	ll ssr=ans+v;
	cout<<ssr<<endl;
  	exit(0);
  }
  for(i=head[id];i;i=eg[i].next)
  {
  	if(eg[i].to==fa)
  	{
  	  continue;
	}
	//cout<<id<<"->"<<eg[i].to<<endl;
	dfs(eg[i].to,id,v*(ld)a[id].r/(ld)a[eg[i].to].r,ans+v);
  }
  return;
}
inline void addedge(int u,int v)
{
  eg[++cnt].to=v;
  eg[cnt].next=head[u];
  head[u]=cnt;
  eg[++cnt].to=u;
  eg[cnt].next=head[v];
  head[v]=cnt;
  return;
}
