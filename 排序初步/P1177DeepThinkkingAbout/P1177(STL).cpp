//Zan Shi AC by STL Ming Tian Shou Da Kuai Pai
#include<cstdio>
#include<algorithm>
using namespace std;
long n=0,a[100000];
int main()
{
  long i=0;
  scanf("%i",&n);
  for(i=0;i<n;i++)
  {
  	scanf("%i",&a[i]);
  }
  sort(a,a+n);
  for(i=0;i<n;i++)
  {
  	printf("%i ",a[i]);
  }
  printf("\n");
  return 0;
}
