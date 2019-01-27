#include<iostream>
#define ld long double
#define MAXN 110
#define eps 1e-7
#define sqr(x) ((x)*(x))
#define dis(x,y,a,b) (sqr((x)-(a))+sqr((y)-(b)))
using namespace std;
struct node
{
  int son[MAXN],fa,cnt;
}tr[MAXN];
int f[MAXN][MAXN],g[MAXN],x[MAXN],y[MAXN],d[MAXN],r[MAXN],n=0;
inline bool in(const int&,const int&);
inline void join(const int&,const int&);
int main()
{
  int i=0,j=0;
  freopen("circle.in","r",stdin);freopen("circle.out","w",stdout);
  tr[0].fa=-1;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n;
  for(i=1;i<=n;++i)
  {
  	cin>>x[i];
  }
  for(i=1;i<=n;++i)
  {
  	cin>>y[i];
  }
  for(i=1;i<=n;++i)
  {
  	cin>>r[i];
  	d[i]=y[i]+r[i];
  }
  cin>>x[n+1]>>y[n+1]>>x[n+2]>>y[n+2];
  d[n+1]=y[n+1];d[n+2]=y[n+2];
  n+=2;
  for(i=1;i<=n;++i)
  {
  	f[0][i]=-1;
  }
  for(i=1;i<=n;++i)
  {
  	for(j=i+1;j<=n;++j)
  	{
	  f[i][j]=in(i,j)-in(j,i);
	}
  }
  for(i=1;i<=n;++i)
  {
  	for(j=i+1;j<=n;++j)
  	{
  	  if(f[i][j]==1)
  	  {
  	    join(i,j);
	  }
	  if(f[i][j]==-1)
	  {
	  	join(j,i);
	  }
	}
  }
  for(i=1;i<=n;++i)
  {
  	tr[tr[i].fa].son[++tr[tr[i].fa].cnt]=i;
  }
  for(i=n,j=0;i!=-1;i=tr[i].fa,++j)
  {
  	g[i]=j;
  }
  for(i=n-1,j=0;i!=-1;i=tr[i].fa,++j)
  {
  	if(g[i])
  	{
  	  cout<<j+g[i]-2<<endl;
	  break;
	}
  }
  return 0;
}
inline void join(const int &u,const int &v)
{
  #define x (tr[u].fa)
  #define y (v)
  if(x>y)
  {
    if(f[y][x]==1)
    {
      x=y;
    }
  }
  else
  {
    if(f[x][y]==-1)
    {
      x=y;
	}
  }
  #undef x
  #undef y
  return;
}
inline bool in(const int &a,const int &b)
{
  return dis(x[a],d[a],x[b],y[b])<sqr(r[b]);
}
