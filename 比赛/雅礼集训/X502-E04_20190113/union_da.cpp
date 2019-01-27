#include<iostream>
#include<ctime>
#include<cstdlib>
#define rr(x) (rand()%(x))
using namespace std;
int n=0;
int main()
{
  register int i=0,j=0;
  srand(time(NULL));
  n=6;
  cout<<n<<endl;
  for(i=1;i<n;++i)
  {
    for(j=i+1;j<=n;++j)
    {
      //cout<<rr(10)<<' ';
      cout<<"1 ";
    }
    cout<<endl;
  }
  return 0;
}
