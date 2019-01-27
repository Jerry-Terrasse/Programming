#include<iostream>
#include<cstdio>
using namespace std;
string a[501];
int main()
{
  char c='\0';
  int i=0;
  for(c=getchar();c!='.';c=getchar())
  {
  	if(c!=' ')
  	{
  	  a[i]+=c;
	}
	else
	{
	  i++;
	}
  }
  for(c=i;c>=0;c--)
  {
  	if(a[c].length()>=a[500].length())
  	{
  	  a[500]=a[c];
	}
  }
  cout<<a[500]<<endl;
  return 0;
}
