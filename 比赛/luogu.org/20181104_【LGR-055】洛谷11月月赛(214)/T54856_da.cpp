#include<iostream>
#include<ctime>
#include<cstdlib>
#define MAXN 10
#define MAXH 10010
#define rr(x) (rand()%(x))
using namespace std;
int main()
{
  register int n=0;
  srand(time(NULL));
  n=rr(MAXN)+1;
  cout<<n<<endl;
  for(;n--;)
  {
  	cout<<rr(MAXH)+1<<' ';
  }
  return 0;
}
