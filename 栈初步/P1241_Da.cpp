#include<cstdio>
#include<cstdlib>
#include<ctime>
#define rr(x) (rand()%(x))
using namespace std;
char c[11]="()[]";
int t=0;
int main()
{
  srand(time(NULL));
  t=10;
  for(;t--;)
  {
    putchar(c[rr(4)]);
  }
  return 0;
}