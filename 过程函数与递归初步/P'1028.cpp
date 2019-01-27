#include<iostream>
#include<string>
using namespace std;
int bit(int m)
{
  int i=0;
  for(i=0;m!=0;i++)
  {
  	m/=10;
  }
  return i;
}
int fly(int a)
{
  int m=a/2,i=0;
  if(m==0)
  {
  	return 0;
  }
  for(i=1;i<=m;i++)
  {
  	//s++;
  	//fly()
  }
}
int main()
{
  int n=0,s=0;
  string k="";
  cin>>n;
  fly(n);
  cout<<s<<endl;
  return 0;
}
