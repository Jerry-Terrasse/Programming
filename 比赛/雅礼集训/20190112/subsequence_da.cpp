#include<iostream>
#include<ctime>
#include<cstdlib>
#define rr(x) (rand()%(x))
using namespace std;
int n=0;
int main()
{
  register int i=0;
  srand(time(NULL));
  n=37;
  cout<<n<<endl;
  for(i=1;i<=n;++i)
  {
    cout<<rand()-RAND_MAX/2<<' ';
  }
  cout<<endl;
  return 0;
}