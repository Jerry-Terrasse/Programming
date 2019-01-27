#include<iostream>
#define MAXN 10000010
using namespace std;
int f[MAXN][25],n=0,m=0,ans=0;
inline void prime();
int main()
{
  int i=0,j=0,u=0,v=0;
  cin>>n>>m;
  prime();
  for(i=2;i<=n;i++)
  {
  	f[i][0]=1-f[i][0];
  }
  for(i=1;(1<<i)<=n;i++)
  {
    for(j=1;(1<<i)+j<=n;j++)
    {
      f[j][i]=f[j][i-1]+f[j+(1<<i>>1)][i-1];
	}
  }
  for(i=1;i<=m;i++)
  {
  	ans=0;
	cin>>u>>v;
  	for(j=0;u+(1<<j<<1)-1<=v;j++);
  	for(;j>=0;j--)
  	{
  	  if(u+(1<<j)-1<=v)
  	  {
  	    ans+=f[u][j];
	    u+=(1<<j);
	  }
	}
	cout<<ans<<endl;
  }
  return 0;
}
inline void prime()
{
  int i=0,j=0;
  for(i=2;i<=n;i++)
  {
  	if(f[i][0])
  	{
  	  continue;
	}
	for(j=i;j<=n/i;j++)
	{
	  f[i*j][0]=1;
	}
  }
  return;
}
/*

  for(int kk=1;kk<=n;kk++)
  {
  	cout<<f[kk][0]<<' ';
  }
  cout<<'{'<<endl;
*/
