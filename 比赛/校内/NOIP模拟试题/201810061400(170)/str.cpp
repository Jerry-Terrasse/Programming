#include<iostream>
using namespace std;
int n=0,k=0;
int main()
{
  int i=0;
  freopen("str.in","r",stdin);freopen("str.out","w",stdout);
  cin>>n>>k;
  if(n<k)
  {
  	cout<<-1<<endl;
  	return 0;
  }
  if(n==k)
  {
  	for(i=0;i<k;++i)
  	{
  	  cout<<(char)('a'+i);
	}
	cout<<endl;
	return 0;
  }
  if(k==1)
  {
  	cout<<-1<<endl;
  	return 0;
  }
  if(k==2)
  {
  	for(i=0;i<n;++i)
  	{
  	  cout<<(char)('a'+(i&1));
	}
	cout<<endl;
	return 0;
  }
  for(i=0;i<n+2-k;++i)
  {
  	cout<<(char)('a'+(i&1));
  }
  for(i=2;i<k;++i)
  {
  	cout<<(char)('a'+i);
  }
  cout<<endl;
  return 0;
}
