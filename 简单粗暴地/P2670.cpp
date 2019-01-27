#include<iostream>
#include "memory.h"
#define MAXN 110
#define ok(x,y) ((x>=0)&&(y>=0)&&(x<n)&&(y<m))
using namespace std;
const int dx[8]={1,1,1,0,0,-1,-1,-1};
const int dy[8]={1,-1,0,1,-1,1,-1,0};
int b[MAXN][MAXN],n=0,m=0,cnt=0;
char a[MAXN][MAXN];
void echo(int,int);
inline void output();
int main()
{
  int i=0,j=0,x=0,y=0;
  //freopen("b.in","r",stdin);
  memset(b,-1,sizeof(b));
  for(cin>>n>>m;i<n;++i)
  {
  	cin>>a[i];
  }
  for(i=0;i<n;++i)
  {
  	for(j=0;j<m;++j)
  	{
  	  if(a[i][j]!='*')
  	  {
  	    echo(i,j);
	  }
	}
  }
  output();
  return 0;
}
void echo(int x,int y)
{
  int i=0;
  cnt+=((a[x][y]!='*')&&(b[x][y]==-1));
  b[x][y]=0;
  if(a[x][y]=='*')
  {
  	return;
  }
  else
  {
  	for(i=0;i<8;++i)
  	{
  	  if(ok(x+dx[i],y+dy[i])&&a[x+dx[i]][y+dy[i]]=='*')
  	  {
  	    ++b[x][y];
	  }
	}
  }
  if(!b[x][y])
  {
  	for(i=0;i<8;++i)
  	{
  	  if(ok(x+dx[i],y+dy[i])&&(b[x+dx[i]][y+dy[i]]==-1))
  	  {
  	    echo(x+dx[i],y+dy[i]);
	  }
	}
  }
  return;
}
inline void output()
{
  int i=0,j=0;
  for(;i<n;++i)
  {
  	for(j=0;j<m;++j)
  	{
	  	if(a[i][j]=='*')
	  	{
	  	  cout<<'*';
		}
		else
		{
		  cout<<b[i][j];
		}
	}
	cout<<endl;
  }
  return;
}
