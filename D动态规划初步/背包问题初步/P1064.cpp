#include<iostream>
using namespace std;
const int Mn=60;
int v[Mn],w[Mn],t[Mn][3][2],dp[Mn][Mn],m,n;
int b[Mn];
int main()
{
  int i=1,j=1,p=0,q=0;
  cin>>n>>m;
  for(;j<=m;j++)//循环迥异 
  {
  	cin>>v[i]>>p>>q;
  	w[i]=v[i]*p;
  	if(q)
  	{
  	  q--;//主件下标 
	  if(b[q])
	  {
	  	t[q][1][0]=v[i]+v[q];
	  	t[q][1][1]=w[i]+w[q];
	  	t[q][2][0]=v[i]+t[q][0][0];
	  	t[q][2][1]=w[i]+t[q][0][1];
	  	b[q]=3;
	  }
	  else
	  {
	  	t[q][0][0]=v[i]+v[q];
	  	t[q][0][1]=w[i]+w[q];
	  	b[q]=1;
	  }
	}
	else
	{
	  i++;
	}
  }
  for(j=1;j<=m;j++)
  {
    for(p=0;p<b[j];p++)
    {
      v[i]=t[j][p][0];
      w[i]=t[j][p][1];
	  i++;
	}
  }
  cout<<i<<endl;
  m=i;
  //cout<<v[m]<<
  //memset(dp,0,sizeof(dp));
  for(i=1;i<=m;i++)
  {
  	for(j=0;j<=n;j++)
  	{
	  //cout<<i<<','<<j<<endl;
	  if(j>=v[i])
	  {
	  	dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
	  }
	  else
	  {
	  	dp[i][j]=dp[i-1][j];
	  }
	}
  }
  cout<<dp[m][n]<<endl;
  //cout<<i<<endl;
  return 0;
}
