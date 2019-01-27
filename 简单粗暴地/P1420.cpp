#include<iostream>
#define MAXN 10010
using namespace std;
int f,a[2],n=0;
int main()
{
  int i=1,n=0,s=0;
  a[0]=0x3f3f3f3f;
  for(cin>>n;i<n;i++)
  {
  	cin>>a[i&1];
  	if(a[i&1]==a[i&1^1]+1)
  	{
  	  f++;
	}
	else
	{
	  f=1;
	}
	s=s<f?f:s;
  }
  cout<<s<<endl;
  return 0;
}
