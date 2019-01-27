#include<iostream>
using namespace std;
int main()
{
  unsigned short i=0;
  int j=0;
  for(;;i++)
  {
  	if(j>i)
  	{
  	  getchar();
	}
	cout<<i<<endl;
  	j=i;
  }
}
