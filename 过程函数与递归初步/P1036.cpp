#include<iostream>
#include<math.h>
using namespace std;
bool isss(long x);
int tRy(int t,int f);
long s=0,m=0;
int n=0,temp=0;
int a[20];
int main()
{
  int k=0,i=0;
  cin>>n>>k;
  for(i=0;i<=n-1;i++)
  {
  	cin>>a[i];
  }
  tRy(k,0);
  cout<<s<<endl;
  return 0;
}
int tRy(int t,int f)
{
  if(t==0)
  {
  	if(isss(m))
	{
	  s++;
	}
	return 0;
  }
  if(t==(n-f))
  {
  	temp=m;
  	for(int j=f;j<=n-1;j++)
  	{
	  temp+=a[j];
	}
	if(isss(temp))
	{
	  s++;
	}
	return 0;
  }
  for(int j=f;j<=n-1;j++)
  {
  	m+=a[j];
  	tRy(t-1,j+1);
  	m-=a[j];
  }
  return 0;
}
bool isss(long x)
{
  for(int i=2;i<=sqrt(x);i++)
  {
  	if(((x/i)*i)==x)
  	{
  	  return false;
	}
  }
  return true;
}
