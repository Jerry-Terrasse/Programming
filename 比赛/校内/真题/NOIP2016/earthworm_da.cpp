#include<iostream>
#include<cstdlib>
#define MAXN 100000
#define MAXM 7000
#define MAXV 1000000000
#define MAXQ 201
#define MAXT 71
#define MAXA 100000001
#define rr(x) (rand()*rand()%(x))
using namespace std;
int n=0,v=0;
int main()
{
  register int i=0;
  srand((int)new char);
  n=rr(MAXN)+1;
  v=rr(MAXV)+2;
  cout<<n<<' '<<rr(MAXM)<<' '<<rr(MAXQ)<<' '<<rr(v)+1<<' '<<v<<' '<<rr(MAXT)+1<<endl;
  for(;n--;)
  {
  	cout<<rr(MAXA)<<' ';
  }
  return 0;
}
