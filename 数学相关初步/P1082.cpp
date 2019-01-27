#include<iostream>
using namespace std;
int a=0,b=0,x=0,y=0;
int gcd(int,int);
void ex_gcd(int,int,int&,int&);
int main()
{
  cin>>a>>b;
  ex_gcd(a,b,x,y);
  for(;x<=0;x+=b);
  for(;x>b;x-=b);
  cout<<x<<endl;
  return 0;
}
void ex_gcd(int a,int b,int &x,int &y)
{
  if(b)
  {
  	ex_gcd(b,a%b,x,y);
  	x^=y;
  	y^=x;
  	x^=y;
  	y-=a/b*x;
  }
  else
  {
  	x=1;
  	y=0;
  }
  return;
}
int gcd(int a,int b)
{
  return b?gcd(b,a%b):a;
}
