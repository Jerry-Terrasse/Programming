#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
  int t=0;
  for(;;++t)
  {
  	cout<<t<<':'<<endl;
	system("la_da.exe >la.in");
  	system("la.exe <la.in >la.out");
  	system("la_1.exe <la.in >la_1.out");
  	system("la_2.exe <la.in >la_2.out");
  	if(system("fc la_1.out la.out")|system("fc la_2.out la.out"))
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
