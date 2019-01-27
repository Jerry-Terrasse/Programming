#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
ofstream fout;
int main()
{
  register int t=0,e=0,s=0;
  for(t=681000;t;--t)
  {
	//cout<<"No."<<t<<endl;
	if(!(t%1000))
	{
	  cout<<"No."<<t<<endl;
	}
	fout.open("T54855.in");
  	fout<<t<<endl;
  	fout.close();
  	s=clock();
  	system("T54855.exe <T54855.in >T54855.out");
  	e=clock();
  	//cout<<e-s<<"ms"<<endl;
  	if(e-s>800)
  	{
  	  cout<<e-s<<"ms"<<"->"<<t<<endl;
	  system("pause");
  	  system("pause");
	}
  }
  return 0;
}
