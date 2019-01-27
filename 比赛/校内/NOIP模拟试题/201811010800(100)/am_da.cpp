#include<iostream>
#include<ctime>
#include<cstdlib>
#define MAXT 11
#define MAXN 110
#define rr(x) (rand()%(x))
using namespace std;
int n=0,m=0,t=0;
int main()
{
  register int i=0,j=0;
  srand(time(NULL));
  cout<<10<<endl;
  for(t=10; t--;)
  {
    n=rr(MAXN)+1;
    m=rr(MAXN)+1;
    cout<<n<<' '<<m<<endl;
    for(i=1; i<=n; ++i)
    {
      for(j=1; j<=m; ++j)
      {
        cout<<rr(2)<<' ';
      }
      cout<<endl;
    }
  }
  return 0;
}
