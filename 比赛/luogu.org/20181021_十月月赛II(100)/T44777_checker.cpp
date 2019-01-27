#include<iostream>
#include<ctime>
using namespace std;
int main()
{
  int t=0,e=0,s=0;
  for(;;++t)
  {
    cout<<"No."<<t<<endl;
    system("T44777_data.exe >T44777.in");
    system("T44777_force.exe <T44777.in >T44777.ans");
    system("T44777.exe <T44777.in >T44777.out");
    if(system("fc T44777.ans T44777.out"))
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
