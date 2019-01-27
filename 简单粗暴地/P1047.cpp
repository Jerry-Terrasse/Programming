#include<iostream>
using namespace std;
int main()
{
  int l=0,m=0,i=0,j=0,a=0,b=0,s=0;
  cin>>l>>m;
  int t[l+1];
  for(i=0;i<=l;i++)
  {
  	t[i]=1;
  }
  for(i=1;i<=m;i++)
  {
  	cin>>a>>b;
  	for(j=a;j<=b;j++)
  	{
  	  t[j]=0;
	}
  }
  for(i=0;i<=l;i++)
  {
  	if(t[i])
  	{
  	  s++;
	}
  }
  cout<<s<<endl;
  return 0;
}
