#include<iostream>
#include<cmath>
using namespace std;
void output(int,int);
int n=0;
int main()
{
  int i=0;
  cin>>n;
  int a=0;
  for(i=n;i>=0;i--)
  {
  	cin>>a;
	if(a!=0)
  	{
	  output(a,i);
	}
  }
  cout<<endl;
  return 0;
}
void output(int a,int m)
{
  if(m!=n)
  {
  	if(a>0)
  	{
  	  cout<<"+";
	}
	else
	{
	  cout<<"-";
	}
  }
  else if(a<0)
  {
  	cout<<"-";
  }
  a=abs(a);
  if(a!=1)
  {
  	cout<<a;
  }
  else if(m==0)
  {
  	cout<<1;
  }
  if(m==1)
  {
  	cout<<"x";
  }
  if(m>1)
  {
  	cout<<"x^"<<m;
  }
  return;
}
