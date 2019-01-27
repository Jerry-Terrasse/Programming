#include<iostream>
#include "memory.h"
using namespace std;
int n=0;
void dg(int);
int main()
{
  cin>>n;
  dg(n);
  cout<<endl;
  return 0;
}
void dg(int x)
{
  if(x==0)
  {
  	cout<<'0';
  	return;
  }
  if(x==2)
  {
  	cout<<'2';
  	return;
  }
  int st[30],p=0,i=0;
  memset(st,0,sizeof(st));
  for(;x;x>>=1,i++)
  {
  	if(x&1)
  	{
  	  st[++p]=i;
	}
  }
  for(;p;p--)
  {
  	if(st[p]==1)
  	{
  	  cout<<'2';
	}
	else
	{
	  cout<<'2'<<'(';
  	  dg(st[p]);
  	  cout<<')';
	}
  	if(p>1)
  	{
  	  cout<<'+';
	}
  }
  return;
}
