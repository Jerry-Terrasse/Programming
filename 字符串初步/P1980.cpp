#include<iostream>
#include<sstream>
using namespace std;
int n=0,s=0;
char x='\0';
stringstream sio;
int main()
{
  int i=0;
  char c='\0';
  cin>>n>>x;
  for(i=1;i<=n;i++)
  {
  	sio.clear();
  	sio.str("");
	sio<<i<<endl;
  	//string str=sio.str();
  	for(;(sio>>c)&&(c!='\n');s+=(c==x));
  }
  cout<<s<<endl;
  return 0;
}
