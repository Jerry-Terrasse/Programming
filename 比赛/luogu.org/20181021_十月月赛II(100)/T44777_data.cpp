#include<iostream>
#include<ctime>
#include<cstdlib>
#define MAXN 27
#define rr(x) (rand()%(x))
using namespace std;
int n=0;
int main()
{
  int i=0;
  srand(time(NULL));
  n=rr(MAXN)+1;
  for(cout<<n<<endl;n--;)
  {
  	cout<<rr(MAXN)<<' ';
  }
  cout<<endl;
  return 0;
}
