#include<iostream>
#include<ctime>
#include<cstdlib>
#define MAXN 10010
#define rr(x) (rand()%(x))
using namespace std;
int main()
{
  int n=0;
  srand(time(NULL));
  n=rr(MAXN)+1;
  cout<<n<<endl;
  for(;n--;)
  {
  	cout<<rr(MAXN)+1<<' '<<rr(MAXN)+1<<endl;
  }
  return 0;
}
