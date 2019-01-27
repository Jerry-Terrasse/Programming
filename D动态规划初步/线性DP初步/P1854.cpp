#include<iostream>
#include "memory.h"
#define MAXN 110
using namespace std;
int a[MAXN][MAXN],f[MAXN][MAXN],ans[MAXN][MAXN],tot=0x80808080,n=0,m=0; 
int main()
{
  int i=1,j=0,k=0;
  memset(f,0x80,sizeof(f));
  for(cin>>n>>m;i<=n;i++)
  {
  	for(j=1;j<=m;j++)
  	{
  	  cin>>a[i][j];
	}
  }
  f[1][1]=a[1][1];
  for(i=2;i<=m;i++)
  {
	for(j=1;j<=min(i,n);j++)
  	{
  	  for(k=j-1;k<i;k++)
  	  {
  	    if(f[k][j-1]>f[i][j])
  	    {
  	      ans[i][j]=k;
  	      f[i][j]=f[k][j-1];
		}
	  }
	  f[i][j]+=a[i][ans[i][j]];
	}
  }
  for(j=n;j<=m;j++)
  {
  	if(tot<f[j][n])
  	{
  	  tot=f[j][n];
	}
  }
  cout<<tot<<endl;
  return 0;
}
