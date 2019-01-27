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
	system("C_data.exe >C.in");
	system("C_force.exe <C.in >C.ans");
	system("C.exe <C.in >C.out");
	if(system("fc C.out C.ans"))
	{
	  system("pause");
	  system("pause");
	}
	else
	{
	  cout<<"AC"<<endl;
	}
  }
  return 0;
}
