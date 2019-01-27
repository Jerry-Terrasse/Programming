#include<iostream>
#include<cstdlib>
#include<ctime>
#define MAXN 110
using namespace std;
int t=0,n=0;
inline int rr(int);
int main()
{
  int i=0;
  srand(time(NULL));
  for(t=1;t--;)
  {
  	n=rr(MAXN)+10;
  	for(cout<<n<<endl;n--;)
  	{
  	  cout<<rr(MAXN)+10<<' ';
	}
	cout<<endl;
  }
  return 0;
}
inline int rr(int x)
{
  return rand()%x;
}
