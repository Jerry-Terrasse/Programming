#include<iostream>
#include<ctime>
#include<cstdlib>
#define MAXN 200
#define rr(x) (rand()%(x))
using namespace std;
int n=0,m=0;
int main()
{
  int i=0;
  srand(time(NULL));
  n=rr(MAXN)+1;
  m=rr(MAXN)+1;
  cout<<n<<' '<<m<<endl;
  for(;n--;)
  {
  	for(i=1;i<=m;++i)
  	{
      cout<<(rr(2)?'*':'.');
    }
    cout<<endl;
  }
  return 0;
}
