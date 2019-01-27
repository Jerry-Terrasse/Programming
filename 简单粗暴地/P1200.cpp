#include<iostream>
#include<string>
using namespace std;
int main()
{
  string a[2]={"",""};
  int s[2]={1,1},i=0,j=0;
  for(i=0;i<=1;i++)
  {
  	 cin>>a[i];
	 for(j=0;a[i][j]!='\0';j++)
	 {
	  s[i]*=(int)a[i][j]-64;
	  s[i]%=47;
	 }
  }
  if(s[0]==s[1])
  {
  	cout<<"GO"<<endl;
  }
  else
  {
  	cout<<"STAY"<<endl;
  }
  return 0;
  //cout<<a<<" "<<b;
}
