#include<iostream>
#include<cstdlib>
#include<ctime>
#define MAXN 10
#define rr(x) (rand()%(x))
using namespace std;
int n=0;
int main()
{
  int i=0;
  srand(time(NULL));
  n=rr(MAXN)+1;
  cout<<n<<endl;
  for(i=1;i<=n;++i)
  {
  	cout<<rr(10);
  }
  cout<<endl;
  for(i=1;i<=n;++i)
  {
  	cout<<rr(10);
  }
  cout<<endl;
  return 0;
}
