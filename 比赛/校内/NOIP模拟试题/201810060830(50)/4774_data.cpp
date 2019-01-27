#include<iostream>
#include<ctime>
#include<cstdlib>
#define MAXN 3010
using namespace std;
char c[2]={'4','7'};
int n=0,m=0;
inline int rr(const int&);
int main()
{
  int i=1,j=0;
  srand(time(NULL));
  n=rr(MAXN)+1;m=rr(MAXN)+1;
  for(cout<<n<<' '<<m<<endl;i<=n;++i)
  {
  	putchar(c[rr(2)]);
  }
  putchar('\n');
  for(;m--;)
  {
  	if(rr(3))
  	{
  	  i=rr(n)+1;
  	  j=rr(n)+1;
  	  if(i>j)
  	  {
  	    swap(i,j);
	  }
	  cout<<"switch "<<i<<' '<<j<<endl;
	}
	else
	{
	  cout<<"count"<<endl;
	}
  }
  return 0;
}
inline int rr(const int &x)
{
  return rand()*rand()%x;
}
