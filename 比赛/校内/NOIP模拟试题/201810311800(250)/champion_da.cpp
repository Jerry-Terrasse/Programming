#include<iostream>
#include<ctime>
#include<cstdlib>
#define MAXN 25
#define MAXK 1000000010
#define MAXA 100010
#define rr(x) (rand()*rand()%(x))
using namespace std;
int n=0;
int main()
{
  int i=0;
  srand(time(NULL));
  n=rr(MAXN)+1;
  //n=40;
  cout<<n<<' '<<rr(MAXK)<<endl;
  for(;n--;)
  {
  	cout<<rr(MAXA)<<' ';
  }
  cout<<endl;
  return 0;
}
