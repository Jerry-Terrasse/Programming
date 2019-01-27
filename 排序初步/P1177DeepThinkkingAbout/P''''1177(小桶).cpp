#include<string>
#include<cstdio>
#include<vector>
#include "memory.h"
using namespace std;
long long n=0,a=0,m=-1;
struct nice
{
  int x:4;
}
vector<nice>s;
int main()
{
  long long i=0,j=0,b=0,t=0;
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
	s[a]++;
  }
  for(i=0;i<=m;i++)
  {
  	for(j=1;j<=s[i];j++)
  	{
  	  printf("%i ",i);
	}
  }
  return 0;
}
