#include<iostream>
#include<cstdio>
#include<sstream>
#include "memory.h"
using namespace std;
char s[60000001];
int u[10001];
int main()
{
  stringstream ac,ak;
  int m=0,n=0,i=0,j=0,t=0,k=0;
  char c='\0';
  string a="",q="";
  scanf("%i %i\n",&m,&n);
  //m=1;n=1;
  for(;i<=m-1;i++)
  {
  	memset(s,0,sizeof(s));
  	memset(u,0,sizeof(u));
  	getline(cin,a);
	ak<<a;
	a=' '+a;
  	for(j=0;j<=n-1;j++)
  	{
	  ak>>q;
	  if(-1!=(k=a.find(q)))
	  {
  	    for(t=1;-1!=(k=a.find(q,k+1));t++);
	  }
	  if(t%2==1)
	  {
	  	cout<<q<<endl;
	  	break;
	  }
	}
  }
  return 0;
}
