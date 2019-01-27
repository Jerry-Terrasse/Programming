#include<iostream>
#include<cstdlib>
#define MAXN 40
#define MAXX 1000001
#define rrr(x) (rand()*rand()%(x))
using namespace std;
int main()
{
  int n=0,x=0;
  srand((int)new char);
  n=rrr(MAXN)+1;
  x=rrr(MAXX);
  cout<<n<<' '<<x<<endl;
  for(;n--;)
  {
  	cout<<rrr(MAXX)<<' ';
  }
  return 0;
}
