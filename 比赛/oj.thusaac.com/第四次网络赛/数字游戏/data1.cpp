#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a=0,i=0,j=0,k=0;
  srand(time(NULL));
  printf("300 10001\n");
  for(i=1;i<=300;i++)
  {
  	for(j=1;j<=10001;j++)
    {
      a=rand();
      printf("%i ",a);
	}
	printf("\n");
  }
}
