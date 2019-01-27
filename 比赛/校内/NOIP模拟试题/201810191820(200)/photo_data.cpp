#include<iostream>
#include<ctime>
#include<cstdlib>
#define MAXN 28
#define rr(x) (rand()%(x))
using namespace std;
int n=0;
int main()
{
  int i=0;
  srand(time(NULL));
  n=rr(MAXN)+1;
  cout<<n<<endl;
  for(;n--;)
  {
  	cout<<rr(MAXN)<<' '<<rr(MAXN)<<endl;
  }
  return 0;
}
