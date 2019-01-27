#include<iostream>
#include "memory.h"
#define MAXN 256
using namespace std;
const int dx[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
struct Queue
{
  int emm[MAXN*MAXN][2],h,t;
  inline void init();
  inline void push(int,int);
  //inline void pop();
}q;
int vis[MAXN][MAXN],h[MAXN][MAXN],n=0,m=0,ans=0;
int main()
{
  int i=1,j=0,u=0,v=0,x=0,y=0;
  freopen("mountain.in","r",stdin);freopen("mountain.out","w",stdout);
  for(cin>>n>>m>>u>>v;i<=n;i++)
  {
  	for(j=1;j<=m;j++)
  	{
  	  cin>>h[i][j];
	}
  }
  for(i=0;i<=n+1;i++)
  {
  	vis[i][0]=vis[i][m+1]=1;
  }
  for(i=0;i<=m+1;i++)
  {
  	vis[0][i]=vis[n+1][i]=1;
  }
  /*for(i=0;i<=n+1;i++)
  {
  	for(j=0;j<=m+1;j++)
  	{
  	  cout<<vis[i][j];
	}
	cout<<endl;
  }*/
  q.init();
  q.push(u,v);
  vis[u][v]=1;
  ans=h[u][v];
  for(;q.h<q.t;q.h++)
  {
  	u=q.emm[q.h][0];v=q.emm[q.h][1];
  	for(i=0;i<4;i++)
  	{
  	  x=u+dx[i][0];y=v+dx[i][1];
  	  if(!vis[x][y]&&h[x][y]>=h[u][v])
  	  {
  	    q.push(x,y);
  	    vis[x][y]=1;
  	    if(ans<h[x][y])
  	    {
  	      ans=h[x][y];
		}
	  }
	}
  }
  cout<<ans<<endl;
  fclose(stdin);fclose(stdout);
  return 0;
}
inline void Queue::init()
{
  memset(emm,0,sizeof(emm));
  h=t=1;
  return;
}
inline void Queue::push(int x,int y)
{
  emm[t][0]=x;
  emm[t++][1]=y;
  return;
}
/*
inline void Queue::pop()
{
  h++;
  return;
}
*/
