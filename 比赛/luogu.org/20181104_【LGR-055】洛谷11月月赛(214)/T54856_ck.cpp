#include<iostream>
#include<ctime>
using namespace std;
int main()
{
  register int t=0,e=0,s=0;
  for(;;++t)
  {
  	cout<<"No."<<t<<endl;
  	system("T54856_da.exe >T54856.in");
  	system("T54856_bf.exe <T54856.in >T54856.ans");
  	system("T54856_ljq.exe <T54856.in >T54856_ljq.out");
  	system("T54856.exe <T54856.in >T54856.out");
  	if(system("fc T54856.ans T54856.out")||system("fc T54856.ans T54856_ljq.out"))
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
