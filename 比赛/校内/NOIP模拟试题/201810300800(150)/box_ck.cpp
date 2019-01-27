#include<iostream>
using namespace std;
int main()
{
  int t=0,e=0,s=0;
  for(;;++t)
  {
  	cout<<"No."<<t<<endl;
  	system("box_data.exe >box.in");
  	system("box_bf.exe <box.in >box.ans");
  	system("box.exe <box.in >box.out");
  	if(system("fc box.out box.ans"))
  	{
  	  system("pause");
  	  system("pause");
	}
	else
	{
	  cout<<"AC"<<endl;
	}
  }
  return 0;
}
