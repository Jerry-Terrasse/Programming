#include<cstdio>
#include<cmath>
#define db double
#define MAXN 64
#define ok(x,y) ((x>=1)&&(y>=1)&&(x<=n)&&(y<=m))
#define sqr(x) ((x)*(x))
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
const int dx[4]={-1,0,0,1};
const int dy[4]={0,1,-1,0};
char a[MAXN][MAXN];
db ans=0;
int xx[MAXN*MAXN],yy[MAXN*MAXN],us[MAXN*MAXN],n=0,m=0,t=0,cnt=0;
inline void cal();
void dfs();
inline int find(const int&);
int main()
{
  int i=1,j=0;
  for(scanf("%d%d%d",&n,&m,&t);i<=n;++i)
  {
  	for(j=1;j<=m;++j)
  	{
  	  for(;a[i][j]<'0'||a[i][j]>'1';a[i][j]=getchar());
  	  if(a[i][j]=='1')
  	  {
  	    xx[++cnt]=i;
  	    yy[cnt]=j;
	  }
	}
  }
  dfs();
  printf("%.6lf",sqrt(ans));
  return 0;
}
inline int find(const int &x)
{
  return us[x]==x?x:us[x]=find(us[x]);
}
void dfs()
{
  if(t)
  {
  	int i=1;
  	for(;i<=cnt;++i)
  	{
  	  if(a[xx[i]][yy[i]]=='1')
  	  {
  	    a[xx[i]][yy[i]]='0';
  	    --t;
  	    dfs();
  	    a[xx[i]][yy[i]]='1';
  	    ++t;
	  }
	}
  }
  else
  {
  	cal();
  }
  return;
}
inline void cal()
{
  int i=1,j=0,k=0,l=0;
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=m;++j)
  	{
  	  us[(i<<5)+j]=(i<<5)+j;
	}
  }
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=m;++j)
  	{
  	  for(k=0;k<4;++k)
  	  {
  	    if(ok(i+dx[k],j+dy[k])&&a[i][j]!='1'&&a[i+dx[k]][j+dy[k]]!='1'&&find((i+dx[k]<<5)+j+dy[k])!=find((i<<5)+j))
  	    {
  	      us[us[(i<<5)+j]]=us[(i+dx[k]<<5)+j+dy[k]];
		}
	  }
	}
  }
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=m;++j)
  	{
  	  for(k=1;k<=n;++k)
  	  {
  	    for(l=1;l<=m;++l)
  	    {
  	      if(find((i<<5)+j)==find((k<<5)+l))
  	      {
  	        ans=max(ans,sqr(i-k)+sqr(j-l));
		  }
		}
	  }
	}
  }
  return;
}
