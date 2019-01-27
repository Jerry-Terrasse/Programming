#include<iostream>
#include<cstdlib>
#define MAXT 10000
#define MAXN 20
#define MAXK 32
#define rr(x) (rand()%(x))
using namespace std;
int t=0,k=0;
int main()
{
  register int i=0,j=0;
  srand((int)new char);
  t=rr(MAXT)+1;
  k=rr(MAXK)+2;
  cout<<t<<' '<<k<<endl;
  for(;t--;)
  {
  	cout<<rr(MAXN)<<' '<<rr(MAXN)<<endl;
  }
  return 0;
}
