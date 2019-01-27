#include<cstdio>
#include<algorithm>
using namespace std;
int a[5][5];
int main()
{
  int i=0,j=0,l[2];
  for(i=0;i<=4;i++)
  {
    for(j=0;j<=4;j++)
    {
      scanf("%d",&a[i][j]);
	}
  }
  scanf("%d%d",&l[0],&l[1]);
  l[0]--,l[1]--;
  swap(a[l[0]],a[l[1]]);
  for(i=0;i<=4;i++)
  {
  	for(j=0;j<=4;j++)
  	{
  	  printf("%d ",a[i][j]);
	}
	printf("\n");
  }
}
