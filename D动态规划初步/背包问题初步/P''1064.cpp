#include<iostream>
#define MAXN 32005
#define MAXM 65
using namespace std;
int v[MAXM][5],w[MAXM][5],p[MAXM],dp[MAXN],n=0,m=0,kkkk=0;
int main()
{
  int i=0,j=0,k=0,q=0;
  cin>>n>>m;
  for(i=1;i<=m;i++)
  {
  	cin>>v[i][0]>>w[i][0]>>p[i];
  	w[i][0]*=v[i][0];
	if(p[i])
  	{
  	  q=p[p[i]];
	  for(k=0;k<q;k++)
  	  {
  	  	v[p[i]][q+k]=v[p[i]][k]+v[i][0];
  	  	w[p[i]][q+k]=w[p[i]][k]+w[i][0];
	  }
	  p[p[i]]*=2;
	  p[i]=0;
	}
	else
	{
	  p[i]=1;
	}
  }
  /*for(int kk=1;kk<=5;kk++)
  {
  	cout<<v[1][kk]<<" ";
  }
  kkkk++;*/
  for(i=1;i<=m;i++)
  {
  	for(j=n;j>=0;j--)
  	{
  	  for(k=0;k<p[i];k++)
  	  {
  	    if(j>=v[i][k])
  	    {
		  dp[j]=max(dp[j-v[i][k]]+w[i][k],dp[j]);
	    }
	    //cout<<v[i][k]<<":"<<w[i][k]<<endl;
	  }
	}
  }
  cout<<dp[n]<<endl;
  /*cout<<'{'<<endl;
  for(i=0;i<=n;i++)
  {
  	cout<<dp[i]<<' ';
  }
  cout<<'}'<<endl;*/
  return 0;
}
