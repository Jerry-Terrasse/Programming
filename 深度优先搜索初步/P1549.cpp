#include<iostream>
#include<cstdlib>
#define MAXN 15
using namespace std;
const int dx[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
const bool sz[201]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0};
int f[MAXN][MAXN],n=0;
bool use[MAXN*MAXN];
inline bool ok(int,int);
void dfs(int,int);
void makesz();
int main()
{
  int i=0;
  cin>>n;
  if(n==1)
  {
  	cout<<"NO"<<endl;
    return 0;
  }
  f[1][1]=1;
  dfs(0,0);
  cout<<"NO"<<endl;
  return 0;
}
void dfs(int d,int p)
{
  int x=d+1,y=d+1;
  if(d==n)
  {
  	for(x=1;x<=n;x++)
  	{
  	  for(y=1;y<=n;y++)
  	  {
  	    cout<<f[x][y]<<' ';
	  }
	  cout<<endl;
	}
	exit(0);
  }
  if(p<n-d)
  {
  	x+=p;
  }
  else
  {
  	y+=d+p+1-n;
  }
  //cout<<x<<","<<y<<endl;
  for(f[x][y]=1;f[x][y]<=n*n;f[x][y]++)
  {
  	if(use[f[x][y]])
  	{
  	  continue;
	}
	if(ok(x,y))
	{
	  use[f[x][y]]=1;
	  if(p==(n-d)*2-2)
	  {
	  	dfs(d+1,0);
	  }
	  else
	  {
	  	dfs(d,p+1);
	  }
	  use[f[x][y]]=0;
	}
  }
  f[x][y]=0;
  return;
}
inline bool ok(int a,int b)
{
  int i=0,x=0,y=0;
  for(;i<4;i++)
  {
  	x=a+dx[i][0];y=b+dx[i][1];
  	if(x==0 || y==0)
  	{
  	  continue;
	}
	if(f[x][y]==0)
	{
	  continue;
	}
	if(!sz[f[a][b]+f[x][y]])
	{
	  return false;
	}
  }
  return true;
}
