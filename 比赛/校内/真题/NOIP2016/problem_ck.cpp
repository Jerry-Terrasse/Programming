#include<iostream>
#include<ctime>
using namespace std;
using namespace std;
int main()
{
  register int t=0,e=0,s=0;
  for(;;++t)
  {
  	cout<<t<<':'<<endl;
  	system("problem_da.exe >problem.in");
  	system("problem_bf.exe <problem.in >problem.ans");
  	s=clock();
	system("problem.exe <problem.in >problem.out");
	e=clock();
	if(system("fc problem.out problem.ans"))
	{
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
