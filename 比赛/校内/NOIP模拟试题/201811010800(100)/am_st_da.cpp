#include<iostream>
#include<ctime>
#include<cstdlib>
#define MAXN 110
#define rr(x) (rand()%(x))
using namespace std;
int n=0,m=0;
int main()
{
  register int i=0,j=0;
  srand(time(NULL));
  n=3;m=4;
  cout<<n<<' '<<m<<endl;
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=m;++j)
  	{
  	  cout<<rr(2)<<' ';
	}
	cout<<endl;
  }
  return 0;
}
