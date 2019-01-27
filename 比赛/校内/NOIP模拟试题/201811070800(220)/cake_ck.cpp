#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
  int t=0,e=0,s=0;
  for(;;++t)
  {
  	cout<<t<<':'<<endl;
  	system("cake_da.exe >cake.in");
  	system("cake_bf.exe <cake.in >cake.ans");
  	system("cake.exe <cake.in >cake.out");
  	if(system("fc cake.out cake.ans"))
  	{
  	  system("pause");
  	  system("pause");
  	}
  	else
  	{
  	  cout<<"AC"<<endl;
  	}
  }
}
