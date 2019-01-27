#include<iostream>
#include<math.h>
using namespace std;
bool isss(long x);
int leng(long x);
int make(int a,bool b);
const int p[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int main()
{
  int a=0,b=0,i=0,l=0,m=0;
  cin>>a>>b;
  l=leng(a);
  l=p[l/2];
  //cout<<a/l;
  for(i=1/*a/l*/;i<=b;i++)
  {
  	m=make(i,true);
  	if((a<=m)&&(m<=b)&&isss(m))
  	{
  	  cout<<m<<endl;
	}
	//
	m=make(i,false);
	if((a<=m)&&(m<=b)&&isss(m))
  	{
  	  cout<<m<<endl;
	}
  }
  return 0;
}
bool isss(long x)
{
  for(int i=2;i<=sqrt(x);i++)
  {
  	if(x/i*i==x)
  	{
  	  return false;
	}
  }
  return true;
}
int leng(long x)
{
  return log(x)/log(10)+1;
}
int make(int a,bool b)
{
  int i=0,r=0,l=0,t=0;
  l=leng(a);
  if(b)//xiao de
  {
	t=2;
  }
  else
  {
	t=1;
  }
  for(i=t;i<=l;i++)
  {
  	r+=a%p[i]/p[i-1]*p[leng(r)];
  }
  return a*p[l-t+1]+r;
}
