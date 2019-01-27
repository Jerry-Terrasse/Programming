#include<cstdio>
#include<algorithm>
#define MAXN 1010
using namespace std;
int a[MAXN],n=0;
int main()
{
  register int i=0;
  a[1]=1;a[2]=2;a[3]=3;
  for(;next_permutation(a+1,a+4);)
  {
    for(i=0;i<5;++i)
  {
    printf("%d ",a[i]);
  }
  puts("");
  }
  return 0;
}