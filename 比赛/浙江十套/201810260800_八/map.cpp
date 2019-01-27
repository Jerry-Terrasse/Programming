#include<iostream>
#define MAXN 1010
#define ok(x,y) ((x>=0)&&(y>=0)&&(x<n)&&(y<m))
using namespace std;
const int dx[4]={0,1,-1,0};
const int dy[4]={1,0,0,-1};
int us[MAXN*MAXN],ans[MAXN*MAXN],n=0,m=0,tot=0;
char a[MAXN][MAXN];
int find(const int&);
int main()
{
  int i=0,j=0,k=0,u=0,v=0;
  freopen("map.in","r",stdin);freopen("map.out","w",stdout);
  cin>>n>>m;
  for(i=0;i<n;++i)
  {
  	cin>>a[i];
  }
  for(i=0;i<n;++i)
  {
  	for(j=0;j<m;++j)
  	{
  	  us[(i<<10)+j]=(i<<10)+j;
	}
  }
  for(i=0;i<n;++i)
  {
  	for(j=0;j<m;++j)
  	{
  	  if(a[i][j]=='O')
  	  {
  	    continue;
	  }
	  for(k=0;k<4;++k)
  	  {
  	    u=i+dx[k];
  	    v=j+dy[k];
  	    if(ok(u,v)&&a[u][v]=='X')
  	    {
  	      us[find((u<<10)+v)]=find((i<<10)+j);
		}
	  }
	}
  }
  for(i=0;i<n;++i)
  {
  	for(j=0;j<m;++j)
  	{
  	  if(a[i][j]=='X')
	  {
	  	ans[find((i<<10)+j)]=1;
	  }
	}
  }
  for(i=0;i<MAXN*MAXN;++i)
  {
  	tot+=ans[i];
  }
  cout<<tot<<endl;
  return 0;
}
int find(const int &x)
{
  return us[x]==x?x:us[x]=find(us[x]);
}
