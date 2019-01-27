#include<iostream>
#include<ctime>
#include<cstdlib>
#define MAXN 100010
#define MAXD 1010
#define rr(x) (rand()%(x))
using namespace std;
int n=0;
int main()
{
  int i=0;
  srand(time(NULL));
  n=rr(MAXN)+1;
  cout<<n<<' '<<rr(n+1)<<endl;
  for(;n--;)
  {
  	cout<<rr(MAXD)<<' ';
  }
  cout<<endl;
  return 0;
}
