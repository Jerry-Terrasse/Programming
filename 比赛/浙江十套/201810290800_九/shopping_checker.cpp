#include<iostream>
#include<ctime>
using namespace std;
int main()
{
  int t=0,e=0,s=0;
  for(;;++t)
  {
  	cout<<"No."<<t<<endl;
  	system("shopping_data.exe >shopping.in");
  	s=clock();
  	system("shopping_force.exe <shopping.in >shopping.out");
  	e=clock();
  	cout<<e-s<<"ms"<<endl;
  }
  return 0;
}
