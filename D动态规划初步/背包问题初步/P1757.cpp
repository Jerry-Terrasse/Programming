#include<iostream>
#include<cmath>
#define Mm 1001
#define Mn 1001
#define Mt 101
using namespace std;
int m,n,v[Mn],w[Mn],g[Mt][Mn],dp[Mm],k;
int main()
{
  int i,j,p;
  scanf("%i%i",&m,&n);
  for(i=1;i<=n;i++)
  {
  	scanf("%i%i%i",&v[i],&w[i],&j);
  	k=j>k?j:k;
  	g[j][0]++;
  	g[j][g[j][0]]=i;
  }
  for(i=1;i<=k;i++)
  {
  	for(j=m;j>=0;j--)
  	{
  	  for(p=1;p<=g[i][0];p++)
  	  {
  	  	if(j>=v[g[i][p]])
  	  	{
  	  	  dp[j]=max(dp[j],dp[j-v[g[i][p]]]+w[g[i][p]]);
		}
	  }
	}
  }
  printf("%i",dp[m]);
  return 0;
}
