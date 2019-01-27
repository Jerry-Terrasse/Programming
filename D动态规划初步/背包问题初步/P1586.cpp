#include<iostream>
#define MAXN 40040
#define MAXT 110
using namespace std;
int f[MAXN][5],p[220],a[MAXT],maxa=0,t=0;
inline void init();
int main()
{
  register int i=0;
  cin>>t;
  for(i=1;i<=t;++i)
  {
  	cin>>a[i];
  	if(maxa<a[i])
  	{
  	  maxa=a[i];
	}
  }
  init();
  for(i=1;i<=t;++i)
  {
  	cout<<f[a[i]][1]+f[a[i]][2]+f[a[i]][3]+f[a[i]][4]<<endl;
  }
  return 0;
}
inline void init()
{
  register int i=0,j=0,k=0;
  for(i=1;p[i-1]<maxa;++i)
  {
  	p[i]=i*i;
  }
  for(i=1,f[0][0]=1;p[i]<=maxa;++i)
  {
  	for(j=p[i];j<=maxa;++j)
  	{
  	  for(k=1;k<=4;++k)
  	  {
  	    f[j][k]+=f[j-p[i]][k-1];
	  }
	}
  }
  return;
}
