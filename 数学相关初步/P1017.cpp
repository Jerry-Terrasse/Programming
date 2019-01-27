#include<iostream>
#include<cmath>
#define ld long double
#define _ 0
#define abs(x) (x<0?-x:x)
using namespace std;
int a=0,r=0;
void dg(int);
inline void write(int);
int main()
{
  int i=0;
  cin>>a>>r;
  cout<<a<<'=';
  dg(a);
  if(a==0)
  {
  	putchar('0');
  }
  cout<<"(base"<<r<<')'<<endl;
  return ~~(0^_^0);
}
inline void write(int x)
{
  if(x<=9)
  {
  	putchar(x+'0');
  }
  else
  {
  	putchar(x-10+'A');
  }
  return;
}
void dg(int x)
{
  if(x)
  {
  	int p=x/r,q=x%r;
  	if(q<0)
  	{
  	  q-=r;
  	  p++;
	}
	dg(p);
    write(q);
  }
  return;
}
