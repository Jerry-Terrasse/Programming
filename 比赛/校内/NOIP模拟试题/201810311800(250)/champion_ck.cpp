#include<iostream>
#include<ctime>
using namespace std;
int main()
{
  int t=0,e=0,s=0;
  for(;;++t)
  {
  	cout<<"No."<<t<<endl;
	system("champion_da.exe >champion.in");
  	system("champion_bf.exe <champion.in >champion.ans");
  	s=clock();
  	system("champion.exe <champion.in >champion.out");
  	e=clock();
  	if(system("fc champion.out champion.ans"))
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
