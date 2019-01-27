#include<iostream>
using namespace std;
int main()
{
  string s="";
  int i=0,j=0,q=0;
  cin>>q;
  for(;i<q;i++)
  {
    cin>>s;
    if(s[s.length()-1]=='c' && s[s.length()-2]=='i')
    {
      if(s[0]=='h' && s[1]=='y' && s[2]=='d' && s[3]=='r' && s[4]=='o')
      {
      	cout<<"non-metal acid"<<endl;
	  }
	  else
	  {
	  	cout<<"polyatomic acid"<<endl;
	  }
	}
	else
	{
	  cout<<"not an acid"<<endl;
	}
  }
  return 0;
}
