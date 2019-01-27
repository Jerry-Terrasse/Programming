#include<iostream>
#include<ctime>
#include<cstdlib>
#define MAXN 30010
#define MAXA 1000000010
#define rr(x) (rand()%(x))
#define rrr(x) (rand()*rand()%(x))
using namespace std;
int a[MAXN],use[MAXN],n=0,m=0;
int main()
{
  register int i=0,j=0;
  srand(time(NULL));
  n=rrr(MAXN)+1;
  m=rrr(n)+1;
  cout<<n<<' '<<m<<endl;
  for(i=1;i<=n;++i)
  {
  	a[i]=rrr(MAXA)+1;
  }
  for(i=1;i<=n;++i)
  {
  	cout<<a[i]<<' ';
  }
  cout<<endl;
  for(i=1;i<=m;)
  {
  	j=rrr(n)+1;
  	if(use[j])
  	{
  	  continue;
	}
	else
	{
	  use[j]=1;
	  ++i;
	  cout<<a[j]<<' ';
	}
  }
  cout<<endl;
  return 0;
}
