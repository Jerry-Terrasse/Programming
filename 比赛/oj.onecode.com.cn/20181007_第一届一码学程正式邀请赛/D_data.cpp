#include<iostream>
#include<ctime>
#include<cstdlib>
#define ll long long
#define MAXN 20
#define MAXW 2147483648
using namespace std;
int n=0;
inline int rr(const int&);
int main()
{
  int i=0;
  srand(time(NULL));
  n=rr(MAXN);
  //n=250;
  cout<<n<<endl;
  for(;n--;)
  {
  	cout<<rr(MAXW)<<' ';
  }
  cout<<endl;
  return 0;
}
inline int rr(const int &x)
{
  return (ll)rand()*rand()*rand()%x;
}
