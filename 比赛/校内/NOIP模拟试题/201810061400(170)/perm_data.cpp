#include<iostream>
#include<ctime>
#include<cstdlib>
#include "memory.h"
#define MAXN 12
using namespace std;
int use[MAXN],n=0,a=0;
inline int rr(const int&);
int main()
{
  int i=0;
  srand(time(NULL));
  n=rr(MAXN)+1;
  cout<<n<<endl;
  for(i=1;i<=n;)
  {
  	a=rr(n);
	if(!use[a])
	{
	  cout<<a<<' ';
	  use[a]=1;
	  ++i;
	}
  }
  cout<<endl;
  memset(use,0,sizeof(use));
  for(i=1;i<=n;)
  {
  	a=rr(n);
	if(!use[a])
	{
	  cout<<a<<' ';
	  use[a]=1;
	  ++i;
	}
  }
  cout<<endl;
  return 0;
}
inline int rr(const int &x)
{
  return rand()*rand()%x;
}
