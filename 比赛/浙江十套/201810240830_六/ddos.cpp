#include<iostream>
#include<queue>
#include "memory.h"
#define MAXN 220
#define ok(x,y) ((x>=0)&&(y>=0)&&(x<n)&&(y<n))
using namespace std;
struct now
{
  int x,y;
  inline now(const int &ix=0,const int &iy=0){x=ix,y=iy;}
}work;
const int dx[4]={-1,0,0,1};
const int dy[4]={0,1,-1,0};
int f[MAXN][MAXN],i=0,n=0;
char a[MAXN][MAXN];
queue<now>q;
int main()
{
  int i=0,j=0,x=0,y=0,k=0,w=0;
  freopen("ddos.in","r",stdin);freopen("ddos.out","w",stdout);
  memset(f,0x3f,sizeof(f));
  cin>>n;
  for(i=0;i<n;++i)
  {
  	for(j=0;j<n;++j)
  	{
  	  cin>>a[i][j];
  	  switch(a[i][j])
  	  {
  	    case 'A':
  	      q.push(now(i,j));
  	      f[i][j]=0;
  	      a[i][j]=1;
  	      break;
  	    case 'x':
  	      a[i][j]=0;
		  break;
  	    case '.':
  	      a[i][j]=1;
  	      break;
	  }
	}
  }
  for(;q.size();)
  {
  	x=q.front().x;
  	y=q.front().y;
  	w=f[x][y]+1;
  	q.pop();
  	for(k=0;k<4;++k)
  	{
  	  for(work.x=x+dx[k],work.y=y+dy[k];ok(work.x,work.y)&&a[work.x][work.y]&&f[work.x][work.y]>=w;work.x+=dx[k],work.y+=dy[k])
  	  {
  	    if(a[work.x][work.y]=='B')
  	    {
  	      cout<<w-1<<endl;
  	      return 0;
		}
		f[work.x][work.y]=w;
		q.push(work);
	  }
	}
  }
  cout<<-1<<endl;
  return 0;
}
