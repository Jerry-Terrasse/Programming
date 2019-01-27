#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int n=0,k=0,bo=0;
#define max maxx
void max(string,string);
string a[2]={"",""};
int main()
{
  int i=0;
  scanf("%i",&n);
  for(i=1;i<=n;i++)
  {
  	//scanf("%s",a[0].c_str());
  	cin>>a[0];
  	max(a[1],a[0]);
  	if(bo)
  	{
  	  a[1]=a[0];
  	  k=i;
	}
  }
  printf("%i\n%s\n",k,a[1].c_str());
  return 0;
}
void max(string a,string b)
{
  if(a.length()>b.length())
  {
  	bo=0;
	return;
  }
  else if(a.length()<b.length())
  {
  	bo=1;
	return;
  }
  else
  {
  	bo=(b>a);
  	return;
  }
  return;
}
#undef max
