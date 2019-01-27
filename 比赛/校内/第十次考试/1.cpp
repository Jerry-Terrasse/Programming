#include<iostream>
#define MAXN 20
using namespace std;
const bool szs[20]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1};
const bool zs[8]={0,2,3,5,7,11,13,17};
int f[MAXN],use[MAXN],n=0,m=0;
void dfs(int);
int main()
{
  freopen("circle.in","r",stdin);freopen("circle.out","w",stdout);
  cin>>n>>m;
  f[1]=1;
  use[1]=1;
  dfs(1);
  fclose(stdin);fclose(stdout);
  return 0;
}
void dfs(int x)
{
  int i=0;
  if(x==m)
  {
  	if(szs[f[m]+f[1]])
  	{
  	  for(int k=1;k<=m;k++)
  	  {
  	    cout<<f[k]<<' ';
	  }
	  cout<<endl;
	}
	else
	{
	  return;
	}
  }
  for(i=2;i<=n;i++)
  {
  	if(!use[i] && szs[i+f[x]])
  	{
  	  f[x+1]=i;
  	  use[i]=1;
  	  dfs(x+1);
  	  use[i]=0;
	}
  }
  return;
}
