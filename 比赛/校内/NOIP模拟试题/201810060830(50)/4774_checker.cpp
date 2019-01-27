#include<iostream>
#include<ctime>
using namespace std;
int t=0,e=0,s=0;
int main()
{
  int i=0;
  for(;;++t)
  {
  	cout<<"No."<<t<<endl;
  	system("4774_data.exe >4774.in");
  	system("4774_force.exe <4774.in >4774.ans");
  	s=clock();
  	system("4774.exe <4774.in >4774.out");
  	e=clock();
  	if(system("fc 4774.out 4774.ans"))
  	{
  	  cout<<"Wrong Answer!"<<endl;
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
