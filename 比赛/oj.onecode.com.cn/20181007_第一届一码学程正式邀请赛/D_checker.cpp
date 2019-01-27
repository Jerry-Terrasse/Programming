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
  	system("D_data.exe >D.in");
  	system("D_force.exe <D.in >D.ans");
	s=clock();
  	system("D.exe <D.in >D.out");
  	e=clock();
  	cout<<"AC "<<e-s<<"ms"<<endl;
  }
  return 0;
}
