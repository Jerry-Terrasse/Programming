#include<iostream>
#define ll long long
#define MAXN 10000010// ******************************************
#define MAXA 5050
using namespace std;
ll f[5][MAXN],w[5][MAXA],m[5],n=0;
int main()
{
  int i=1,j=0,k=0;
  for(cin>>n>>m[1]>>m[2]>>m[3]>>m[4];i<=4;i++)
  {
  	for(j=1;j<=m[i];j++)
  	{
  	  cin>>w[i][j];
	}
  }
  for(j=0;j<=n;j++)
  {
  	f[0][j]=1;
  }
  for(i=1;i<=4;i++)
  {
  	for(j=n;j>=0;j--)
  	{
  	  for(k=1;k<=m[i];k++)
  	  {
  	  	if(j>=w[i][k])
  	  	{
  	  	  f[i][j]+=f[i-1][j-w[i][k]];
		}
	  }
	}
  }
  cout<<f[4][n]<<endl;
  return 0;
}
