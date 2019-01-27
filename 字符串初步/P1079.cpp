#include<iostream>
#include<cstring>
using namespace std;
string c="",k="";
int lk=0;
void lowercase(string&);
void shift(char&,int);
int main()
{
  int i=0;
  cin>>k>>c;
  lowercase(k);
  lk=k.length();
  for(;i<c.length();i++)
  {
  	shift(c[i],(int)(k[i%lk]-'a'));
  }
  cout<<c<<endl;
  return 0;
}
void lowercase(string& s)
{
  for(int i=0;i<s.length();i++)
  {
  	if((s[i]>='A')&&(s[i]<='Z'))
  	{
  	  s[i]+=32;
	}
  }
  return;
}
void shift(char& s,int t)
{
  //cout<<'{'<<s<<','<<t<<'}';
  bool lower=false;
  if(s>='a')
  {
  	lower=true;
  	s-=32;
  }
  s-=t;
  if(s<'A')
  {
  	s+=26;
  }
  if(lower)
  {
  	s+=32;
  }
  //cout<<s<<endl;
  return;
}
