#include<iostream>
#include "memory.h"
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
#define ld long double
#define MAXN 32
#define MINT 1e-15
using namespace std;
int a[MAXN],p[MAXN],sum[MAXN],n=0,m=0;
ld av=0,sigma=0,newsigma=0,t=0,ans=1e20;
inline int rr(int);
inline void cal(ld&);
inline void simulate();
int main()
{
  int i=0,j=0,k=0;
  srand(time(NULL));
  for(cin>>n>>m;i<n;i++)
  {
  	cin>>a[i];
  	av+=a[i];
  }
  av/=m;
  /*sort(a,a+n);
  for(i=0,j=n-1,k=0;i+1<=j;i++,j--,k++)
  {
  	p[i]=p[j]=k%m;
  	sum[k%m]+=a[i]+a[j];
  }
  if(i==j)
  {
  	p[i]=k%m;
  	sum[k%m]+=a[i];
  }*/
  /*if(n<=4)
  {
  	j=5600/n;
  }
  else if(n<=5)
  {
  	j=8565/n;
  }
  else if(n<=7)
  {
  	j=8870/n;
  }
  else if(n<=8)
  {
  	j=9940/n;
  }
  else if(n<=10)
  {
  	j=10420/n;
  }
  else if(n<=11)
  {
  	j=11800/n;
  }
  else if(n<=12)
  {
  	j=12223/n;
  }
  else if(n<=13)
  {
  	j=13520/n;
  }
  else if(n<=16)
  {
  	j=15889/n;
  }
  else if(n<=18)
  {
  	j=18320/n;
  }
  else if(n<=20)
  {
  	j=19001/n;
  }
  else
  {
  	j=23333/n;
  }
  for(i=0;i<j;i+=(ans==sigma)+1)
  {
  	simulate();
  }*/
  for(;(ld)clock()/CLOCKS_PER_SEC<0.99;)
  {
  	simulate();
  }
  ans/=m;
  ans=sqrt(ans);
  cout<<fixed<<setprecision(2)<<ans<<endl;
  return 0;
}
inline void simulate()
{
  int i=0,j=0,k=0;
  memset(sum,0,sizeof(sum));
  for(i=0;i<n;i++)
  {
  	p[i]=rr(m);
  	sum[p[i]]+=a[i];
  }
  for(cal(sigma),t=10000;t>MINT;t*=0.99)
  {
  	/*for(;;)
  	{
  	  i=rr(n);j=0;
	  for(k=1;k<m;k++)
  	  {
  	    if(sum[j]>sum[k])
  	    {
  	      j=k;
	    }
	  }
	  if(i!=j)
	  {
	  	break;
	  }
	}*/
	for(i=rr(n),j=rr(m);p[i]==j;j=rr(m));
  	sum[p[i]]-=a[i];
  	sum[j]+=a[i];
  	cal(newsigma);
  	if(newsigma<sigma)
  	{
  	  p[i]=j;
  	  sigma=newsigma;
  	  //t*=1.00001;
	}
	else if(exp(-t)<rr(10000000)/10000000)
	{
	  p[i]=j;
	}
	else
	{
	  sum[p[i]]+=a[i];
	  sum[j]-=a[i];
	}
  }
  if(ans>sigma)
  {
  	ans=sigma;
  }
  return;
}
inline void cal(ld &sigma)
{
  int i=0;
  for(i=0,sigma=0;i<m;i++)
  {
  	sigma+=(sum[i]-av)*(sum[i]-av);
  }
  return;
}
inline int rr(int x)
{
  return rand()*rand()%x;
}
