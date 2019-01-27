#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;
int main()
{
  int t=0,e=0,s=0;
  for(;;++t)
  {
  	cout<<"No."<<t<<endl;
  	system("card_da.exe >card.in");
  	system("card_zyt.exe <card.in >card.zyt");
  	system("card_bf.exe <card.in >card.ans");
  	s=clock();
  	system("card.exe <card.in >card.out");
  	e=clock();
  	if(system("fc card.out card.ans")||system("fc card.zyt card.ans"))
  	{
  	  system("pause");
  	  system("pause");
	}
	else
	{
	  cout<<"AC "<<e-s<<"ms"<<endl;
	}
  }
}
