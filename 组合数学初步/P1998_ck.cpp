#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
  register int t=0;
  for(;++t;)
  {
  	cout<<t<<':'<<endl;
  	system("P1998_da.exe >P1998.in");
  	system("P1998_low.exe <P1998.in >P1998.ans");
  	system("P1998.exe <P1998.in >P1998.out");
  	if(system("fc P1998.out P1998.ans"))
  	{
  	  cout<<"!!!!!!!!!!"<<endl;
  	  system("pause");
	}
	else
	{
	  cout<<"AC"<<endl;
	}
  }
  return 0;
}
