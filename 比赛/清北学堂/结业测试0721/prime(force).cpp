#include<iostream>
#include<cmath>
#define ll long long
#define MAXP 20
using namespace std;
ll zs[MAXP],cnt=0,p=0,q=0,ans=0;
int main()
{
  ll i=0,j=0,pro=0,a=0,b=0,x=0,y=0;
  bool bo=false;
  for(i=2;cnt<MAXP;i++)
  {
  	bo=true;
	for(j=2;j<=sqrt(i);j++)
  	{
  	  if(i%j==0)
  	  {
  	    bo=false;
  	    break;
	  }
	}
	if(bo)
	{
	  zs[cnt++]=i;
	}
  }
  for(;p<MAXP-10;p++)
  {
  	for(q=p;q<MAXP-10;q++)
  	{
  	  ans=0;
	  pro=zs[p]*zs[q];
  	  for(a=0;a*a<=pro;a++)
  	  {
  	    for(b=0;b*b<=pro;b++)
  	    {
  	      if(a*a+b*b==pro)
  	      {
  	        ans++;
		  }
		}
	  }
	  cout<<"p="<<zs[p]<<"q="<<zs[q]<<":"<<ans<<endl;
	}
  }
  return 0;
}
