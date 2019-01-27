#include<string>
#include<cstdio>
#include<vector>
#include "memory.h"
using namespace std;
long long n=0,a=0,m=-1;
vector<char>s;
int main()
{
  long long i=0,j=0,t=0;
  //memset(s,0,sizeof(s));
  scanf("%i",&n);
  for(i=0;i<n;i++)
  {
    scanf("%i",&a);
    if(m<a)
    {
      m=a;
      for(j=s.size();j<=m;j++)
      {
      	s.push_back(0);
	  }
	}
	t+=(!s[a]);
	s[a]=1;
  }
  printf("%i\n",t);
  for(i=0;i<=m;i++)
  {
  	if(s[i])
  	{
  	  printf("%i ",i);
	}
  }
  printf("\n");
  return 0;
}
