#include<iostream>
#include<ctime>
using namespace std;
int main()
{
  register int t=0,e=0,s=0;
  for(;;++t)
  {
  	cout<<"No."<<t<<endl;
	system("a_da.exe >a.in");
  	system("a_bf.exe <a.in >a.ans");
  	s=clock();
  	system("a.exe <a.in >a.out");
  	e=clock();
  	if(system("fc a.out a.ans"))
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
