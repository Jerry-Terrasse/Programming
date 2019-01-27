#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;
int main()
{
  int minput=0,mall=0,mright=0,ma=0;
  srand((unsigned)time(NULL));
  for(mall=0;minput!=-1;mall++)
  {
  	ma=rand()%20;
  	cout<<ma<<":";
  	ma*=ma;
  	cin>>minput;
  	if(minput==ma)
  	{
  	  mright++;
	}
	cout<<"----"<<ma<<endl;
  }
  mall--;
  cout<<endl<<setprecision(4)<<endl<<endl<<(double)mright/mall*100<<"%"<<endl;
  return 0;
}
