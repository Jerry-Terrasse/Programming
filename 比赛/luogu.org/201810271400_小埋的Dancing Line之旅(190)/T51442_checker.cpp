#include<iostream>
#include<ctime>
using namespace std;
int main()
{
	int t=0,e=0,s=0;
	for(;;++t)
	{
		system("T51442_data.exe >T51442.in");
		system("T51442_force.exe <T51442.in >T51442.ans");
		s=clock();
		system("T51442.exe <T51442.in >T51442.out");
		e=clock();
		if(system("fc T51442.out T51442.ans"))
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
