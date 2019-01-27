#include<cstdio>
#include<cstdlib>
#define rr(x) (rand()%(x))
using namespace std;
char c[4]="()[]";
int t=0;
int main()
{
  t=10;
  for(;t--;)
  {
    putchar(c[rr(4)]);
  }
  return 0;
}