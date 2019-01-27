#include<cstdio>
#include<cstring>
using namespace std;
int x=0;
char s[20];
int main()
{
  int i=0,j=1,k=0;
  bool b=false;
  for(scanf("%i",&x);j<x;)
  {
	if(j%7==0)
    {
      b^=1;
      goto label;
    }
    memset(s,'\0',sizeof(s));
    for(sprintf(s,"%i",j),k=0;s[k];k++)
    {
      if(s[k]=='7')
  	  {
  	    b^=1;
  	    goto label;
	  }
    }
	label:j++;
	if(b)
	{
	  i--;
	}
	else
	{
	  i++;
	}
  }
  for(;i<0;i+=1337);
  for(;i>=1337;i-=1337);
  printf("%i",i+1);
  return 0;
}
