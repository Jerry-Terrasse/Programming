#include<iostream>
#include<ctime>
#include<cstdlib>
//#define MAXN 100000
#define MAXN 2000
//#define MAXQ 500000
#define MAXQ 500050
#define MAXA 1<<30
#define rr(x) (rand()*rand()%(x))
using namespace std;
int n=0,q=0,k=0;
int main()
{
  register int i=0,u=0,v=0;
  ios::sync_with_stdio(false);cin.tie(0);
  srand(time(NULL));
  n=MAXN;
  q=MAXQ;
  //k=rr(3)+1;
  k=2;
  cout<<n<<' '<<q<<' '<<k<<endl;
  for(i=1;i<=n;++i)
  {
    cout<<rr(MAXA)<<' ';
  }
  cout<<endl;
  for(i=1;i<=q;++i)
  {
    u=rr(n)+1;
    v=rr(n)+1;
    if(u>v)
    {
      u^=v^=u^=v;
    }
    cout<<u<<' '<<v<<endl;
  }
  return 0;
}