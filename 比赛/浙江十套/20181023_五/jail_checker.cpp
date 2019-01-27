#include<iostream>
#include<ctime>
using namespace std;
int main()
{
  int t=0,e=0,s=0;
  for(;;++t)
  {
  	cout<<"No."<<t<<endl;
  	system("jail_data.exe >jail.in");
  	system("jail_force.exe <jail.in >jail.ans");
  	s=clock();
    system("jail.exe <jail.in >jail.out");
  	e=clock();
    if(system("fc jail.out jail.ans"))
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
