#include<iostream>
#define MAXN 110
using namespace std;
int a[MAXN][MAXN],b[MAXN][MAXN],n=0,m=0,t=0;
int main()
{
  register int i=0,j=0,k=0;
  //n=2;m=3;
  cin>>n>>m;
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=m;++j)
  	{
  	  cin>>a[i][j];
	}
  }
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=m;++j)
  	{
  	  if(a[i][j])
  	  {
  	    for(k=1;k<=n;++k)
  	    {
  	      b[k][j]=1;
		}
		for(k=1;k<=m;++k)
		{
		  b[i][k]=1;
		}
	  }
	}
  }
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=m;++j)
  	{
  	  cout<<b[i][j]<<' ';
	}
	cout<<endl;
  }
  return 0;
}
