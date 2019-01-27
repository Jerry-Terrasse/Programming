#include<iostream>
#include<fstream>
#include<ctime>
#define ld long double
using namespace std;
int t=0,s=0,e=0,n=0;
ifstream fin;
int main()
{
  int i=0;
  for(;;t++)
  {
  	cout<<"No."<<t<<endl;
  	system("P2503_data.exe >P2503.in");
  	fin.open("P2503.in");
  	fin>>n;
  	fin.close();
  	cout<<"data::n="<<n<<endl;
  	system("P2503_force.exe <P2503.in >P2503.ans");
  	s=clock();
  	system("P2503_dp_sa.exe <P2503.in >P2503.out");
  	e=clock();
  	if(system("fc P2503.out P2503.ans"))
  	{
  	  cout<<"Wrong Answer!"<<endl;
  	  system("pause");
	}
	else
	{
	  cout<<"Accept "<<e-s<<"ms"<<endl;
	}
	if(e-s>=1000||e-s<=800)
	{
	  system("pause");
	}
  	//system("pause");
  }
  return 0;
}
