//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void go(int a);
int p[1001];
int main()
{
  int n=0;
  memset(p,-1,sizeof(p));
  cin>>n;
  go(n);
  cout<<p[n]<<endl;
  return 0;
}
void go(int a)
{
  int i=0,k=1;
  for(i=1;i<=a/2;i++)
  {
  	if(p[i]==-1)
  	{
  	  go(i);
	}
  	k+=p[i];
  }
  p[a]=k;
}
