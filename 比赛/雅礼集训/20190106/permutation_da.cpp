#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int n=0,k=0;
int main()
{
  register int i=0;
  srand(time(NULL));
  n=5050;k=2020;
  cout<<n<<' '<<k<<endl;
  for(i=1;i<=n;++i)
  {
    cout<<rand()<<endl;
  }
  return 0;
}