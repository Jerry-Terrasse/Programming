#include<iostream>
#include<cstdlib>
#define MAXN 100000
#define MAXG 1000000001
#define rr(x) (rand()%(x))
using namespace std;
int main()
{
  int n=0,m=0,i=0;
  srand((int)new char);
  n=rr(MAXN)+1;
  m=rr(MAXN)+1;
  cout<<n<<' '<<m<<' '<<endl;
  for(i=1;i<n;++i)
  {
    cout<<rr(i)<<endl;
  }
  for(i=1;i<=m;++i)
  {
    cout<<rr(n)<<' '<<rr(MAXG)<<endl;
  }
  return 0;
}
