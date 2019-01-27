#include<iostream>
#include<ctime>
#include<cstdlib>
#define MAXN 7
#define MAXX 20
#define rr(x) (rand()%(x))
using namespace std;
int use[MAXN],n=0;
int main()
{
  int i=0;
  srand(time(NULL));
  n=rr(MAXN)+1;
  cout<<rr(MAXX)+1<<' '<<n<<endl;
  cout<<'1'<<' ';
  use[1]=1;
  for(--n;n;)
  {
  	i=rr(MAXN<<1)+1;
  	if(use[i])
  	{
  	  continue;
	}
	use[i]=1;
	--n;
	cout<<i<<' ';
  }
  cout<<endl;
  return 0;
}
