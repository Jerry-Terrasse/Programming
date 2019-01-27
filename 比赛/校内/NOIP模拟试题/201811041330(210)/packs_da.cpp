#include<iostream>
#include<ctime>
#include<cstdlib>
#define MAXN 17
#define MAXA 1010
#define rr(x) (rand()%(x))
using namespace std;
int main()
{
  register int n=0,i=2;
  srand(time(NULL));
  for(; i--;)
  {
    n=rr(MAXN)+1;
    cout<<n<<' ';
    for(; n--;)
    {
      cout<<rr(MAXA)+1<<' ';
    }
    cout<<endl;
  }
  return 0;
}
