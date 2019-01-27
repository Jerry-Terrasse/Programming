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
  	system("P3373_data.exe >P3373.in");
  	system("P3373.exe <P3373.in >P3373.ans");
  	s=clock();
  	system("P3373_ljq.exe <P3373.in >P3373.out");
  	e=clock();
	if(system("fc P3373.out P3373.ans"))
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
