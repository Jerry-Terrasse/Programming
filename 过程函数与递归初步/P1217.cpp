#include<iostream>
#include<cmath>
using namespace std;
int leng(long long);
int bit(long long,long long);
bool isss(long long);
bool ishw(long long);
const long long p[12]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000};
int main()
{
  long long a=0,b=0,i=0,j=0;
  cin>>a>>b;
  for(i=a;(i<=b)&&(i<=9989899);i++)
  {
  	if(ishw(i)&&isss(i))
  	{
  		cout<<i<<endl;
	}
  }
}
bool isss(long long x)
{
  for(long long i=2;i<=sqrt(x);i++)
  {
  	if((double)x/i==(int)x/i)
  	{
  	  return false;
	}
  }
  return true;
}
int leng(long long x)
{
  return log(x)/log(10)+1;
}
bool ishw(long long x)
{
  int l=leng(x),j=0;
  for(j=1;j<=l/2;j++)
  {
	if(bit(x,j)!=bit(x,l-j+1))
  	{
  	  return false;
	}
  }
  return true;
}
int bit(long long x,long long b)
{
  return (int)(x%p[b]/p[b-1]);
}
