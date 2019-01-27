#include<iostream>
#include<Windows.h>
#include<cstdio>
using namespace std;
int t=0;
int main()
{
  int i=0;
  for(;;t++)
  {
  	cout<<"No."<<t<<endl;
  	system("diyiti_data.exe >diyiti.in");
  	cout<<"data..done"<<endl;
  	system("diyiti_force.exe <diyiti.in >diyiti.ans");
  	cout<<"ans..done"<<endl;
  	system("diyiti.exe");
  	cout<<"own..done"<<endl;
  	if(system("fc diyiti.out diyiti.ans"))
  	{
  	  cout<<"Wrong Answer"<<endl;
  	  system("pause");
  	  for(int kkk=0;kkk<20;kkk++)
  	  {
  	    cout<<'\a';
  	    Sleep(200);
	  }
	}
	else
	{
	  cout<<"Accepted"<<endl;
	}
  }
  return 0;
}
