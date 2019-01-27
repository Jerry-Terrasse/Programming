#include<iostream>
#include<iomanip>
#include<ctime>
#define ld long double
using namespace std;
int t=0;
ld s=0,e=0;
int main()
{
  int i=0;
  for(;;t++)
  {
  	cout<<"No."<<t<<endl;
  	s=clock();
  	system("P1337.exe <P1337.in >P1337.out");
  	e=clock();
  	cout<<fixed<<setprecision(5)<<e-s<<"ms"<<endl;
  	system("pause");
  }
  return 0;
}
