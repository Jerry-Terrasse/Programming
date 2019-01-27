#include<iostream>
#define ll long long
#define MAXN 100000010// ******************************************
#define MAXA 5050
using namespace std;
ll f[MAXN],w[5][MAXA],m[5],n=0,ans=0;
int main()
{
  int i=1,j=0,k=0;
  freopen("graph.in","r",stdin);freopen("graph.out","w",stdout);
  ios::sync_with_stdio(0);
  for(cin>>n>>m[1]>>m[2]>>m[3]>>m[4];i<=4;i++)
  {
  	for(j=1;j<=m[i];j++)
  	{
  	  cin>>w[i][j];
	}
  }
  for(j=0;j<=n;j++)
  {
  	f[j]=1;
  }
  for(i=1;i<=4;i++)
  {
  	for(j=n;j>=0;j--)
  	{
  	  for(k=1,f[j]=0;k<=m[i];k++)
  	  {
  	  	if(j>=w[i][k])
  	  	{
  	  	  f[j]+=f[j-w[i][k]];
		}
	  }
	}
  }
  cout<<f[n]<<endl;
  fclose(stdin);fclose(stdout);
  return 0;
}
