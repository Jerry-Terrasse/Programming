#include<iostream>
#include<ctime>
using namespace std;
int main()
{
  int t=0,e=0,s=0;
  for(;;++t)
  {
  	cout<<"No."<<t<<endl;
  	system("photo_data.exe >photo.in");
  	system("photo_force.exe <photo.in >photo.ans");
  	s=clock();
  	system("photo.exe <photo.in >photo.out");
  	e=clock();
  	if(system("fc photo.ans photo.out"))
  	{
  	  system("pause");
  	  system("pause");
	}
	else
	{
	  cout<<"Accepted "<<e-s<<"ms"<<endl;
	}
  }
  return 0;
}
