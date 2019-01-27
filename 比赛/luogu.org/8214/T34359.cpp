#include<iostream>
#define MAXN 15
using namespace std;
int ak[14200][MAXN],ans[MAXN],a[MAXN],b[MAXN<<1],c[MAXN<<1],cnt=0,n=0;
void dfs(int);
int main()
{
  int i=0,j=0;
  ios::sync_with_stdio(0);
  cin>>n;
  dfs(1);
  cout<<cnt<<endl;
  for(i=0;i<cnt;i++)
  {
  	for(j=1;j<=n;j++)
  	{
  	  cout<<ak[i][j]<<' ';
	}
	cout<<endl;
  }
  return 0;
}
void dfs(int x)
{
  int y=0;
  if(x==n+1)
  {
  	for(y=1;y<=n;y++)
  	{
  	  ak[cnt][y]=ans[y];
	}
	cnt++;
    return;
  }
  for(y=1;y<=n;y++)
  {
  	if(a[y]||b[x+y]||c[x+n-y])
  	{
  	  continue;
	}
	a[y]=b[x+y]=c[x+n-y]=ans[x]=y;
	dfs(x+1);
	a[y]=b[x+y]=c[x+n-y]=ans[x]=0;
  }
  return;
}
