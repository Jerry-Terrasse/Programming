#include<iostream>
#define MAXN 30010
#define in(x,y,z) ((x>=y)&&(x<=z))
using namespace std;
struct edge
{
  int to,next;
}e[MAXN<<1];
int head[MAXN],cnt=0,n=0,q=0;
unsigned short f[MAXN][MAXN];
inline void read(int&);
inline void addedge(const int&,const int&);
int main()
{
  int i=1,j=0,k=0,u=0,v=0;
  for(cin>>n>>q;i<n;i++)
  {
  	cin>>u>>v;
  	addedge(u,v);
  }
  for(i=1;i<=n;i++)
  {
  	f[i][i]=1;
  }
  for(i=1;i<=n;i++)
  {
  	for(j=1;j+i<=n;j++)
  	{
  	  f[j][j+i]=f[j][j+i-1]+1;
  	  for(k=head[j+i];k;k=e[k].next)
  	  {
  	    f[j][j+i]-=in(e[k].to,j,j+i-1);
	  }
	}
  }
  for(;q--;)
  {
  	cin>>u>>v;
  	cout<<f[u][v]<<endl;
  }
  return 0;
}
inline void addedge(const int &u,const int &v)
{
  e[++cnt].to=v;
  e[cnt].next=head[u];
  head[u]=cnt;
  e[++cnt].to=u;
  e[cnt].next=head[v];
  head[v]=cnt;
  return;
}
