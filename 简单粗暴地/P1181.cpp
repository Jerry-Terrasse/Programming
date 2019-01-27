#include<iostream>
#define MAXN 100010
using namespace std;
int a[MAXN],n=0,m=0,cnt=0,sum=0;
int main()
{
  int i=0;
  ios::sync_with_stdio(0);
  cin>>n>>m;
  for(;i<n;i++)
  {
    cin>>a[i];
  }
  for(i=0;i<n;i++)
  {
  	if(sum+a[i]>m)
  	{
  	  cnt++;
  	  i--;
  	  sum=0;
	}
	else
	{
	  sum+=a[i];
	}
  }
  cout<<cnt+1<<endl;
  return 0;
}
