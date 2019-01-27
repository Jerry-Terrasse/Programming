#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
void make(int);
int dg(int);
int temp[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int n=0,zs[8000],szs=0,s[3]={0,0,0};
int main()
{
  cin>>n;
  make(n);
  dg(0);
}
void make(int maxn)
{
  for(szs=0;zs[szs-1]<=maxn;szs++)
  {
  	if(szs<=24)
  	{
  	  zs[szs]=temp[szs];
  	  //cout<<zs[szs]<<endl;
  	  continue;
	}
	for(int i=zs[szs-1]+2;i<=maxn+72;i+=2)
	{
	  bool b=true;
	  for(int j=0;zs[j]<=sqrt(i);j++)
	  {
	  	if(i%zs[j]==0)
	  	{
	  	  b=false;
	  	  break;
		}
	  }
	  if(b)
	  {
	  	zs[szs]=i;
	  	//cout<<i<<endl;
	  	break;
	  }
	}
  }
}
int dg(int x)
{
  if(x==3)
  {
  	if(s[0]+s[1]+s[2]==n)
  	{
  	  cout<<s[0]<<" "<<s[1]<<" "<<s[2]<<endl;
  	  exit(0);
	}
	//s[2]=0;
	return 0;
  }
  for(int i=0;i<=szs-1;i++)
  {
  	s[x]=zs[i];
  	if(s[0]+s[1]+s[2]>n)
  	{
  	  s[x]=0;
	  return 0;
	}
  	dg(x+1);
  	s[x]=0;
  }
}
