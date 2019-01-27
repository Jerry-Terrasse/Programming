#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;
int t=0,s=0,e=0;
int main()
{
  int i=0;
  for(;;++t)
  {
  	cout<<"No."<<t<<endl;
  	system("str_data.exe >str.in");
  	system("str_force.exe <str.in >str.ans");
  	s=clock();
	system("str.exe <str.in >str.out");
  	e=clock();
  	if(system("fc str.out str.ans"))
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
