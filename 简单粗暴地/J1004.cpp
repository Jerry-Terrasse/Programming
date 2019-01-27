#include<iostream>
using namespace std;
int n=0;
int main()
{
  int i=0,a[2]={0,0},s[2]={0,0};
  bool bo=0;
  for(cin>>n;i<n;i++)
  {
  	cin>>a[i&1];
	if(a[i&1])
	{
	  s[1]++;
	  if(bo)
	  {
	    bo=0;
	  }
	  else
	  {
	    s[0]++;
	  	bo=1;
	  }
	}
	else
	{
	  bo=0;
	}
  }
  cout<<s[0]<<' '<<s[1]<<endl;
  return 0;
}
