#include<cstdio>
using namespace std;
int n=0,cu[100],s;
int main()
{
  int i=0,j=0;
  scanf("%i",&n);
  for(;i<n;i++)
  {
	scanf("%i",&cu[i]);
  }
  for(i=0;i<n;i++)
  {
  	for(s=0,j=0;j<i;j++)
  	{
  	  if(cu[j]<cu[i])
  	  {
  	    s++;
	  }
	}
	printf("%i ",s);
  }
  printf("\n");
  return 0;
}
