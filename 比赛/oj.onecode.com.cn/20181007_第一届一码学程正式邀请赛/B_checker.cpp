#include<iostream>
#include<ctime>
using namespace std;
int t=0,e=0,s=0;
int main()
{
  //int i=0;
  for(;;++t)
  {
  	cout<<"No."<<t<<endl;
  	system("B_data.exe >B.in");
  	system("B_force.exe <B.in >B.ans");
  	s=clock();
  	system("B.exe <B.in >B.out");
  	e=clock();
  	if(system("fc B.out B.ans"))
  	{
  	  cout<<"WA"<<endl;
  	  system("pause");
  	  system("pause");
	}
	else
	{
	  cout<<"AC "<<e-s<<"ms"<<endl;
	}
  }
  return 0;
}
