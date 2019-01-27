#include<iostream>
#define MAXN 1000010
using namespace std;
int a[MAXN],t=0,n=0,ans=0;
int main()
{
  int i=0;
  ios::sync_with_stdio(0);
  for(cin>>t;t;t--)
  {
  	ans=0;
  	cin>>n;
  	for(i=0;i<n;i++)
  	{
  	  cin>>a[i];
  	  if(a[i]%8==0)
  	  {
  	  	ans^=(a[i]-1);
	  }
	  else if(a[i]%8==7)
	  {
	  	ans^=a[i]+1;
	  }
	  else
	  {
	  	ans^=a[i];
	  }
	}
	if(ans)
	{
	  cout<<"First player wins."<<endl;
	}
	else
	{
	  cout<<"Second player wins."<<endl;
	}
  }
  return 0;
}
