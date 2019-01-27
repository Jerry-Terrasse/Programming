#include<iostream>
#define MAXM 2000020
using namespace std;
int m=0,sum=0;
int main()
{
  int i=0,j=0;
  cin>>m;
  for(;i<m;++i)
  {
  	for(;sum<m;++j)
  	{
  	  sum+=j;
	}
	if(sum==m)
	{
	  cout<<i<<' '<<j-1<<endl;
	}
	sum-=i;
  }
  return 0;
}
