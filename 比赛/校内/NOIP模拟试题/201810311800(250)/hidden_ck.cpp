#include<iostream>
#include<ctime>
using namespace std;
int main()
{
  int t=0,e=0,s=0;
  for(;;++t)
  {
  	cout<<"No."<<t<<endl;
	system("hidden_da.exe");
  	s=clock();
  	system("hidden.exe <hidden.in >hidden.out");
  	e=clock();
  	if(system("fc hidden.out hidden.ans"))
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
