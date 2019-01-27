#include<iostream>
#include<ctime>
using namespace std;
int main()
{
  register int t=0,e=0,s=0;
  for(;;++t)
  {
  	cout<<t<<':'<<endl;
  	system("earthworm_da.exe >earthworm.in");
  	system("earthworm_bf.exe <earthworm.in >earthworm.ans");
  	s=clock();
  	system("earthworm.exe <earthworm.in >earthworm.out");
  	e=clock();
  	if(system("fc earthworm.out earthworm.ans"))
  	{
  	  system("pause");
  	  system("pause");
	}
	else
	{
	  cout<<"AC "<<e-s<<"ms"<<endl;
	}
  }
  return 0;
}
