#include<iostream>
#include<iomanip>
#include "memory.h"
using namespace std;
void bfs(int);
void output();
struct hor
{
  int x;
  int y;
}re[160000];
const int go[8][2]={{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};
int n=0,m=0,t=0,c[400][400];
int main()
{
  cin>>n>>m>>re[0].x>>re[0].y;
  n--;m--;re[0].x--;re[0].y--;
  memset(c,-1,sizeof(c));
  t=0;
  c[re[0].x][re[0].y]=0;
  bfs(0);
}
void bfs(int s)
{
  if(s==(n+1)*(m+1)-1)
  {
  	output();
  	return;
  }
  int k=0,gx=re[s].x,gy=re[s].y;
  for(k=0;k<=7;k++)
  {
  	gx+=go[k][0];gy+=go[k][1];
  	if((0<=gx)&&(gx<=n)&&(0<=gy)&&(gy<=m)&&(c[gx][gy]==-1))
  	{
  	  t++;
  	//cout<<"Try:"<<gx<<" "<<gy<<endl;
  	  re[t].x=gx;re[t].y=gy;
  	  c[gx][gy]=c[re[s].x][re[s].y]+1;
	}
  	gx-=go[k][0];gy-=go[k][1];
  }
  bfs(s+1);
  return;
}
void output()
{
  int i=0,j=0;
  for(i=0;i<=n;i++)
  {
  	for(j=0;j<=m;j++)
  	{
  	  cout<<left<<setw(5)<<c[i][j];
	}
	cout<<endl;
  }
  return;
}
