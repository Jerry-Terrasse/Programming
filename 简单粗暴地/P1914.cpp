#include<iostream>
#include<cstring>
using namespace std;
int n=0;
string code="";
void shift(char&,int);
int main()
{
  int i=0;
  cin>>n>>code;
  n%=26;
  for(i=0;i<code.length();i++)
  {
  	shift(code[i],n);
  }
  cout<<code<<endl;
  return 0;
}
void shift(char& s,int t)
{
  s+=t;
  if(!(s>='a' && s<='z'))
  {
  	s-=26;
  }
  return;
}
