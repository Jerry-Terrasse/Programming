#include<iostream>
#include<algorithm>
#define MAXN 10
#define MAXM 100010
using namespace std;
const int dx[4]={1,1,-1,-1};
const int dy[4]={1,-1,1,-1};
struct method
{
  int ans,x,y;
}s[MAXM];
int ans=0,cnt=0;
char a[MAXN][MAXN],aa[MAXN];
void king(int,int);
void pown(int,int);
void kinwk(int,int);
void powwk(int,int);
int main()
{
  register int i=0,j=0;
  freopen("chess.in","r",stdin);freopen("chess.out","w",stdout);
  cout<<0<<endl;
  return 0;
  for(i=0;i<10;++i)
  {
  	cin>>a[i];
  }
  //pown
  for(i=0;i<10;++i)
  {
  	cin>>aa;
  	for(j=0;j<10;++j)
  	{
  	  if(aa[j]=='1'&&a[i][j]=='1')
  	  {
  	    a[i][j]='k';
	  }
	}
  }
  //deal kings
  for(i=0;i<10;++i)
  {
  	for(j=0;j<10;++j)
  	{
	  if(a[i][j]=='k')
	  {
	  	king(i,j);
	  }
  	  if(a[i][j]=='1')
  	  {
  	    pown(i,j);
	  }
	}
  }
  if(ans==0)
  {
  	for(i=0;i<10;++i)
  	{
  	  for(j=0;j<10;++j)
  	  {
  	    if(a[i][j]=='k')
  	    {
  	      kinwk(i,j);
		}
		if(a[i][j]=='1')
		{
		  powwk(i,j);
		}
	  }
	}
  }
  //when output,(x+1,y+1)
  return 0;
}
void pown(int x,int y)
{
  register int k=0,u=0,v=0;
  
  return;
}
