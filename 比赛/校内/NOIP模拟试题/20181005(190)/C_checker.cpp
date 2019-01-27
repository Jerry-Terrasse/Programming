#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;
int t=0,e=0,s=0;
int main()
{
  int i=0;
  for(;;t++)
  {
  	cout<<"No."<<t<<endl;
  	system("C_data.exe >C.in");
  	system("C_force.exe <C.in >C.ans");
  	s=clock();
  	system("C.exe <C.in >C.out");
  	e=clock();
  	if(system("fc C.out C.ans"))
  	{
  	  cout<<"Wrong Answeer!"<<endl;
  	  system("pause");
	}
	else
	{
	  cout<<"Accepted "<<e-s<<"ms"<<endl;
	}
  }
  return 0;
}
