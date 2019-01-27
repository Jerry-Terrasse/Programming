#include<cstdio>
#include "Windows.h"
#include<iostream>
using namespace std;
int t=0;
void bell(int);
int main()
{
  int i=0;
  for(;;t++)
  {
  	cout<<"No."<<t<<endl;
  	system("data_P1955.exe >P1955.in");
  	cout<<"data...done"<<endl;
  	system("P1955.exe <P1955.in >P1955.out");
  	cout<<"own...done"<<endl;
  	system("ans.exe <P1955.in >P1955.ans");
  	cout<<"ans...done"<<endl;
  	if(system("fc P1955.out P1955.ans"))
  	{
  	  cout<<"Wrong Answer!"<<endl;
  	  bell(100);
  	  system("pause");
	}
	else
	{
	  cout<<"Accepted"<<endl;
	}
  }
  return 0;
}
void bell(int x)
{
  for(;x--;)
  {
  	cout<<'\a';
  	Sleep(100);
  }
  return;
}
