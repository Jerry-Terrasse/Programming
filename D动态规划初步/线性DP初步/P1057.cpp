#include<iostream>
#define MAXN 64
using namespace std;
int f[MAXN][MAXN],n=0,m=0;
int main()
{
  int i=2,j=0;
  f[1][1]=1;
  for(cin>>n>>m;i<=m+1;i++)
  {
  	f[i][1]=f[i-1][n]+f[i-1][2];
  	f[i][n]=f[i-1][n-1]+f[i-1][1];
	for(j=2;j<n;j++)
	{
	  f[i][j]=f[i-1][j-1]+f[i-1][j+1];
	}
  }
  cout<<f[m+1][1]<<endl;
  return 0;
}


//f[i][j]=f[i-1][j+1]+f[i-1][j-1]
