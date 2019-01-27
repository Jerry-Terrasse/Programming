#include<iostream>
#include<ctime>
#include<cstdlib>
#define rr(x) (rand()%(x))
using namespace std;
int main()
{
  int i=0;
  srand(time(NULL));
  i=rr(10)+1;
  cout<<i<<endl;
  for(;i--;)
  {
  	cout<<rr(10)<<' '<<rr(10)<<endl;
  }
  return 0;
}
