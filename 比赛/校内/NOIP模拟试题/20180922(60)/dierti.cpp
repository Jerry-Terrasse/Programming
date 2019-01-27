#include<iostream>
#define us unsigned short
#define MAXN 5010
#define in(x,y,z) ((x>=y)&&(x<=z))
using namespace std;
struct edge
{
  us to,next;
}e[MAXN<<1];
int head[MAXN],cnt=0,n=0,q=0;
us f[MAXN][MAXN];
inline void read(int&);
inline void addedge(const us&,const us&);
us dfs(us,us);
inline void read(int&);
int main()
{
  int i=1,u=0,v=0;
  freopen("dierti.in","r",stdin);freopen("dierti.out","w",stdout);
  for(read(n),read(q);i<n;i++)
  {
  	read(u);read(v);
  	addedge(u,v);
  }
  for(i=1;i<=n;i++)
  {
  	f[i][i]=1;
  }
  for(;q--;)
  {
  	read(u);read(v);
  	cout<<dfs(u,v)<<endl;
  }
  return 0;
}
inline void read(int &x)
{
  char c=getchar();
  for(x=0;c<'0'||c>'9';c=getchar());
  for(;c>='0'&&c<='9';c=getchar())
  {
  	x=(x<<3)+(x<<1)+c-'0';
  }
  return;
}
us dfs(us u,us v)
{
  if(f[u][v])
  {
  	return f[u][v];
  }
  us ans=dfs(u,v-1)+1,k=0;
  for(k=head[v];k;k=e[k].next)
  {
  	ans-=in(e[k].to,u,v-1);
  }
  return f[u][v]=ans;
}
inline void addedge(const us &u,const us &v)
{
  e[++cnt].to=v;
  e[cnt].next=head[u];
  head[u]=cnt;
  e[++cnt].to=u;
  e[cnt].next=head[v];
  head[v]=cnt;
  return;
}
