#include<iostream>
#include<ctime>
using namespace std;
int main()
{
  int t=0,e=0,s=0;
  for(;;++t)
  {
  	cout<<"No."<<t<<endl;
	system("am_da.exe >am.in");
  	s=clock();
  	system("am.exe <am.in >am.out");
  	e=clock();
  	if(system("am_jg.exe"))
  	{
  	  system("pause");
  	  system("pause");
	}
	else
	{
	  cout<<"AC "<<e-s<<endl;
	}
  }
  return 0;
}
