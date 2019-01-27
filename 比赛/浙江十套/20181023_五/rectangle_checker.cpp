#include<iostream>
#include<ctime>
using namespace std;
int main()
{
  int t=0,e=0,s=0;
  for(;;++t)
  {
  	cout<<"No."<<t<<endl;
  	system("rectangle_data.exe >rectangle.in");
  	system("rectangle_force.exe <rectangle.in >rectangle.ans");
  	s=clock();
    system("rectangle.exe <rectangle.in >rectangle.out");
  	e=clock();
    if(system("fc rectangle.out rectangle.ans"))
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
