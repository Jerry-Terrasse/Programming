#include<iostream>
#define MAXN 110
#define H 998244353
using namespace std;
int f[MAXN][MAXN*MAXN],n=0,m=0;
int main()
{
  int i=0,j=0,k=0;
  cin>>n>>m;
  f[1][0]=1;
  for(i=2;i<=n;i++)
  {
  	for(j=0;j<i;j++)
  	{
  		for(k=0;f[i-1][k];k++)
  		{
  			f[i][k+i-j-1]+=f[i-1][k];
			}
		}
	}
	for(i=1;i<=9;i++)
	{
		for(j=0;f[i][j];j++)
		{
			cout<<f[i][j]<<' ';
		}
		cout<<':'<<j<<endl;
	}
	//cout<<f[n][m]<<endl;
	return 0;
}
