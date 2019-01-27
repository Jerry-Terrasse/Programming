#include<iostream>
#include<ctime>
using namespace std;
int main()
{
  int t=0,e=0,s=0;
  for(;;++t)
  {
  	cout<<"No."<<t<<endl;
	system("dish_da.exe >dish.in");
  	system("dish_bf.exe <dish.in >dish.ans");
  	s=clock();
  	system("dish.exe <dish.in >dish.out");
  	e=clock();
  	if(system("fc dish.out dish.ans"))
  	{
  	  system("pause");
  	  system("pause");
	}
	else
	{
	  cout<<"Accepted "<<e-s<<"ms"<<endl;
	}
  }
  return 0;
}
