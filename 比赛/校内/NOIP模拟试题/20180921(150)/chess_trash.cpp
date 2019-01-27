#include<iostream>
#define MAXN 20200
#define ok(x,y) (x>0&&x<=n&&y>0&&y<=m)
using namespace std;
const int dx[8]={-2,-2,2,2,-1,-1,1,1};
const int dy[8]={-1,1,-1,1,-2,2,-2,2};
int a[MAXN][MAXN],n=0,m=0,ans=0;
int dfs(int,int,int);
int main()
{
  int i=0,j=0,x=0,y=0;
  cin>>n>>m;
  x=(n+1)>>1;
  y=(m+1)>>1;
  for(i=1;i<=x;i++)
  {
  	for(j=1;j<=y;j++)
  	{
  	  a[i][j]=1;
  	  //cout<<'{'<<i<<','<<j<<'}'<<endl;
	  dfs(i,j,1);
	  a[i][j]=0;
	}
  }
  cout<<ans<<endl;
  ans=0;
  main();
  return 0;
}
int dfs(int x,int y,int len)
{
  int i=0,u=0,v=0;
  //cout<<':'<<len<<endl;
  for(i=0;i<8;i++)
  {
  	if(ok(x+dx[i],y+dy[i])&&!a[x+dx[i]][y+dy[i]])
  	{
  	  u=x+dx[i];v=y+dy[i];
  	  a[u][v]=1;
  	  dfs(u,v,len+1);
  	  a[u][v]=0;
	}
  }
  if(ans<len)
  {
  	ans=len;
  	//cout<<ans<<endl;
  }
  return 0;
}
