#include<iostream>
#include<queue>
#define MAXN 2020
#define ok(x,y) ((x>=1)&&(y>=1)&&(x<=n)&&(y<=n))
using namespace std;
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,1,-1};
int us[MAXN*MAXN],cnt[MAXN*MAXN],n=0,m=0;
char a[MAXN][MAXN];
inline int find(const int&);
int main()
{
  int i=0,j=0,k=0,u=0,v=0;
  cin>>n>>m;
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=n;++j)
  	{
  	  cin>>a[i][j];
	}
  }
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=n;++j)
  	{
  	  us[(i<<10)+j]=(i<<10)+j;
	}
  }
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=n;++j)
  	{
	  for(k=0;k<4;++k)
	  {
	  	u=i+dx[k];
	  	v=j+dy[k];
	  	if(ok(u,v)&&a[i][j]!=a[u][v]&&find((u<<10)+v)!=find((i<<10)+j))
	  	{
	  	  us[us[(u<<10)+v]]=(i<<10)+j;
		}
	  }
	}
  }
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=n;++j)
  	{
  	  cnt[find((i<<10)+j)]++;
	}
  }
  for(;m--;)
  {
  	cin>>i>>j;
  	cout<<cnt[find((i<<10)+j)]<<endl;
  }
  return 0;
}
inline int find(const int &x)
{
  return us[x]==x?x:us[x]=find(us[x]);
}
