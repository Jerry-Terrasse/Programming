#include<bits/stdc++.h>
using namespace std;
int t=0;
int main()
{
  int i=0;
  double s=0,e=0;
  for(;;t++)
  {
  	cout<<"No."<<t<<endl;
  	system("data_stone.exe");
  	system("stdAC.exe <stone.in >stone.out");
  	s=clock();
  	system("stone_force.exe <stone.in >stone.ans");
  	e=clock();
	if(system("fc stone.out stone.ans"))
  	{
  	  cout<<"!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
  	  system("pause");
	}
	else
	{
	  cout<<"Accept. "<<e-s<<"ms"<<endl;
	  //system("pause");
	}
  }
  return 0;
}
