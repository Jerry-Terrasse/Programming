#include<iostream>
#include<ctime>
#include<cstdlib>
#include<set>
#define MAXN 100000
//#define MAXN 100
#define rr(x) (rand()*rand()%(x))
using namespace std;
int n=0;
int main()
{
  register int i=0;
  srand(time(NULL));
  n=MAXN;
  cout<<n<<endl;
  for(;n--;)
  {
    i=rr(2147483647)+32768;
    cout<<i<<' ';
  }
  return 0;
}