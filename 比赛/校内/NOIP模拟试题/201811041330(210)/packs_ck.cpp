#include<iostream>
#include<ctime>
using namespace std;
int main()
{
  register int t=0,e=0,s=0;
  for(;;++t)
  {
  	cout<<t<<':'<<endl;
  	system("packs_da.exe >packs.in");
  	system("packs_bf.exe <packs.in >packs.ans");
  	s=clock();
  	system("packs.exe");
  	e=clock();
	if(system("fc packs.out packs.ans"))
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
