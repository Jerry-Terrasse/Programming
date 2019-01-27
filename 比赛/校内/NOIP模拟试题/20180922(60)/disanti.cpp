#include<iostream>
#include<iomanip>
#define ld long double
#define MAXN 25020
#define MAXT 3030
using namespace std;
int l[MAXN],p[MAXN],n=0,t=0,q=0;
ld f[MAXN][MAXT];
inline void dp();
int main()
{
  int i=1,e=0;
  freopen("disanti.in","r",stdin);freopen("disanti.out","w",stdout);
  for(cin>>n>>t>>q;i<=n;i++)
  {
  	cin>>p[i];
  }
  for(i=1;i<=n;i++)
  {
  	cin>>l[i];
  }
  for(;q--;)
  {
  	cin>>e>>i;
  	if(e==1)
  	{
  	  l[i]++;
	}
	else
	{
	  l[i]--;
	}
	for(i=1;i<=n;i++)
	{
	  for(e=1;e<=t;e++)
	  {
	  	f[i][e]=0;
	  }
	}
	dp();
	cout<<fixed<<setprecision(8)<<f[n][t]<<endl;
  }
  return 0;
}
inline void dp()
{
  int i=0,j=0,k=0;
  for(i=1;i<=n;i++)
  {
  	for(j=1;j<=t;j++)
  	{
  	  for(k=0;k<=j;k++)
  	  {
  	    f[i][j]=max(f[i][j],max(f[i-1][j],f[i-1][k]+(ld)p[i]*(j-k)/(l[i]+j-k)));
	  }
	}
  }
  return;
}
