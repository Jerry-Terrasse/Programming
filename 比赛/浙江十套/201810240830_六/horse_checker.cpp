#include<iostream>
using namespace std;
int main()
{
  int t=0;
  for(;;++t)
  {
  	cout<<"No."<<t<<endl;
  	system("horse_data.exe >horse.in");
  	system("horse_zyt.exe <horse.in >horse.ans");
  	system("horse_ans.exe <horse.in >horse.out");
  	if(system("fc horse.ans horse.out"))
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
