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
  	system("P3372_data.exe >P3372.in");
  	system("P3372.exe <P3372.in >P3372.ans");
  	s=clock();
  	system("P3372_zsdd.exe <P3372.in >P3372.out");
  	e=clock();
	if(system("fc P3372.out P3372.ans"))
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
