#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#define MAXN 10000000
#define rr(x) (rand()%(x))
using namespace std;
ofstream fout;
int main()
{
  int t=0,n=0,e=0,s=0;
  srand(time(NULL));
  for(t=0;;++t)
  {
  	cout<<"No."<<t<<endl;
	n=rr(MAXN)+1;
	fout.open("seven.in");
  	fout<<n<<endl;
  	fout.close();
  	system("seven_bf.exe <seven.in >seven.ans");
  	s=clock();
  	system("seven_bf.exe <seven.in >seven.out");
  	e=clock();
  	if(system("fc seven.out seven.ans"))
  	{
  	  cout<<"n=="<<t<<':'<<endl;
	  system("pause");
  	  system("pause");
	}
	else
	{
	  cout<<"AC"<<e-s<<"ms"<<endl;
	}
  }
  return 0;
}
