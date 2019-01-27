#include<iostream>
#include<cmath>
#define MAXN 10010
using namespace std;
int n=0,ss=0,ans=0,d[MAXN][2];
long double l[MAXN][MAXN],p=0,s=0;
int main()
{
  int i=0,j=0,k=0;
  ios::sync_with_stdio(0);
  cin>>n>>ss;
  for(;i<n;i++)
  {
    cin>>d[i][0]>>d[i][1];
  }
  for(i=0;i<n;i++)
  {
	for(j=i+1;j<n;j++)
  	{
  	  l[i][j]=sqrt((d[i][0]-d[j][0])*(d[i][0]-d[j][0])+(d[i][1]-d[j][1])*(d[i][1]-d[j][1]));
  	  //cout<<l[i][j]<<endl;
	}
  }
  for(i=0;i<n;i++)
  {
  	for(j=i+1;j<n;j++)
  	{
  	  for(k=j+1;k<n;k++)
  	  {
  	    s=sqrt((long double)(l[i][j]+l[i][k]+l[j][k])*(l[i][j]+l[i][k]-l[j][k])*(l[i][j]-l[i][k]+l[j][k])*(-l[i][j]+l[i][k]+l[j][k])/8);
  	    //cout<<s<<endl;
		if((0<s)&&(s<=ss))
  	    {
  	      ans++;
		}
	  }
	}
  }
  cout<<ans<<endl;
  return 0;
}
