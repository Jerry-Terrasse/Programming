#include<bits/stdc++.h>
using namespace std;
int n=0,s=0;
char b[40001][40001];
int main()
{
  int i=0,j=0,g=0;
  scanf("%i",&n);
  n--;
  if(!n)
  {
  	printf("0\n");
  	return 0;
  }
  s=2;
  for(i=1;i<=n;i++)
  {
  	for(j=1;j<=n;j++)
  	{
  	  g=__gcd(i,j);
  	  if(b[i/g][j/g])
  	  {
  	  	continue;
	  }
	  else
	  {
	  	b[i/g][j/g]++;
	  	s++;
	  	//cout<<'('<<i<<','<<j<<')'<<endl;
	  	continue;
	  }
	}
  }
  printf("%i",s);
  return 0;
}
