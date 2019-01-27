#include<iostream>
#include<cstdlib>
#define MAXN 10010
#define MAXK 1010
#define MAXA 2147483648
#define rr(x) ((long long)rand()*rand()*rand()%(x))
using namespace std;
int main()
{
  int n=0,k=0;
  n=rr(MAXN)+1;
  k=rr(MAXK)+1;
  cout<<n<<' '<<k<<endl;
  for(;n--;)
  {
  	cout<<rr(MAXA)<<' ';
  }
  return 0;
}
