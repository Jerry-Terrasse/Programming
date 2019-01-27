#include<cstdio>
#include<iomanip>
#include<cstdlib>
#define ld double
#define rr(x) (rand()%(x))
using namespace std;
int main()
{
  register int n=0,i=0,j=0;
  srand((int)new char);
  ld p=0;
  n=12;
  printf("%d\n",n);
  for(i=1;i<=n;++i)
  {
  	for(j=0,p=1;j<=i;++j)
  	{
  	  p*=(ld)(rr(1000)+100)/1100;
  	  //p-=0.1*(ld)(rr(1000)+100)/1100;
  	  printf("%.3f ",p);
  	}
  	puts("");
  }
  return 0;
}
