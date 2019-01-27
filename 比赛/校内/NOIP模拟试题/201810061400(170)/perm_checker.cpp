#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;
int t=0,s=0,e=0;
int main()
{
  int i=0;
  for(;;++t)
  {
  	cout<<"No."<<t<<endl;
  	system("perm_data.exe >perm.in");
  	system("perm_max20.exe <perm.in >perm.ans");
  	s=clock();
	system("perm.exe <perm.in >perm.out");
  	e=clock();
  	if(system("fc perm.out perm.ans"))
  	{
  	  cout<<"Wrong Answer!"<<endl;
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
