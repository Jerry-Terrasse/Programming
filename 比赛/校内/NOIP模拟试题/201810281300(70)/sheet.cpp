#include<iostream>
#include<iomanip>
#define ld long double
#define MAXN 500
using namespace std;
int main()
{
  int i=0,j=0;
  for(i=1;i<=MAXN;++i)
  {
  	for(j=1;j<=i;++j)
  	{
  	  cout<<j<<'/'<<i<<'='<<fixed<<setprecision(4)<<(ld)j/i<<' ';
	}
	cout<<endl;
  }
  return 0;
}
