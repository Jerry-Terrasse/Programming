#include<iostream>
#include<ctime>
#include<cstdlib>
#define MAXN 1000010
#define MAXD 4
#define rr(x) (rand()*rand()%(x))
using namespace std;
int n=0,d=0;
int main()
{
  int i=0;
  srand(time(NULL));
  //n=rr(MAXN)+1;
  n=10000;
  //d=rr(MAXD)+1;
  d=4;
  cout<<n<<' '<<d<<endl;
  for(;n--;)
  {
  	for(i=0;i<d;++i)
  	{
      cout<<rr(2147483647)<<' ';
    }
    cout<<endl;
  }
  return 0;
}
