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
  	system("dierti_data.exe >dierti.in");
  	cout<<"data..done"<<endl;
  	system("dierti_dp.exe <dierti.in >dierti.ans");
  	cout<<"ans..done"<<endl;
  	system("dierti.exe <dierti.in >dierti.out");
  	cout<<"own..done"<<endl;
  	if(system("fc dierti.out dierti.ans"))
  	{
  	  cout<<"Wrong Answer"<<endl;
  	  for(int kkk=0;kkk<20;kkk++)
  	  {
  	    cout<<'\a';
  	    Sleep(200);
	  }
  	  system("pause");
	}
	else
	{
	  cout<<"Accepted"<<endl;
	}
  }
  return 0;
}
